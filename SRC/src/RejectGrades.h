#ifndef  _REJECT_GRADES_H
#define  _REJECT_GRADES_H

#include <cmath>
#include <vector>

/// Produces rejection grades. i.e: Points that if touched returns non-similar
class RejectGrades
{
 private:

   int _maskSize;
   std::vector<int>* _ul;
   int _ub,_ubp1;
   int _k;
   long double* _p_d_given_in_k_n;
   long double _s_s,_s_ns;
   long double _B;



   void init(const int& maskSize,
	     const long double& falseNegative,
	     const long double& maxOcclusion,
	     std::vector<int>& ul) {
	 
	 assert( maskSize > 0 );
	 assert( (falseNegative >= 0)&&(falseNegative < 100) );
	 assert( (maxOcclusion > 0)&&(maxOcclusion <= 100) );
	 
	 
	 ul.resize(maskSize);
	 _ul= &ul;
	 _maskSize= maskSize;
	 _ub= static_cast<int>(floor( (maxOcclusion/100.0)*maskSize ));
	 
	 //cout << "_ub == " << _ub << endl;
	 _ubp1= _ub+1;
	 
	 // trying (n=1,k=1) as a rejection point
	 _k= 1;
	 
	 // cache
	 _p_d_given_in_k_n= new long double[_maskSize+1];
	 
	 // sum of similar and non-similar of p_d_given_in_k_n
	 _s_s= (_s_ns= 0.0);

   } // init







   
   void main_loop() {
	 
	 
	 int maskSize_m_n= _maskSize;
	 for (int n=1; n<_maskSize; ++n) {

	       --maskSize_m_n;
	       long double one_div_maskSize_m_n= 1.0/maskSize_m_n;
           _s_ns/=_s_s; // _s_ns <=> lik ratio
	       
	       int d=0;

	       if (_s_ns>=_B) {
		     //cerr << _s_ns << " ";
			 //cerr << _k << endl;   		     
		     _s_ns= (_s_s=0);

		     // d<k <=> number of existing non similar is smaller
		     //         than the number of non similar sampled
		     //     <=> event with probability zero
		     while ( (d<_k) ) {
			   _p_d_given_in_k_n[d]= 0.0;
			   ++d;
		     }

		     // num == num_similar_left
		     //     == (num_all_left) - (num_non_similar_left)
		     //     == (maskSize - n) - (d-k)
		     //     == maskSize - n + k - d // d==k
		     //     == maskSize - n + k - k 
		     //     == maskSize - n
		     long double num= maskSize_m_n;

		     // while similar region AND num_similar_left>0
		     while ( (d<=_ub) && (num>0) ) {
			   _s_s+=  (_p_d_given_in_k_n[d]*= num*one_div_maskSize_m_n);
			   ++d;
			   --num;
		     }

		     // while non-similar region AND num_similar_left>0
		     while ( (d<=_maskSize) && (num>0) ) {
			   _s_ns+= (_p_d_given_in_k_n[d]*= num*one_div_maskSize_m_n);
			   ++d;
			   --num;
		     }
		     
		     // case where num==num_similar_left<=0
		     // event of next 0 has probability 0
		     while (d<=_maskSize) {
			   _p_d_given_in_k_n[d]= 0.0;
			   ++d;
		     }
		     
		     (*_ul)[n-1]= _k;
		     
	       } else {

		     // num2 == num_non_similar_left
		     //      == d-k // d==0
		     //      == -k 
		     long double num2= -_k; 

		     _s_ns= (_s_s=0);

		     // num_non_similar_left<=0 <=>
		     // probability of event of sampling another non_similar is zero
		     while (num2<=0) {
			   _p_d_given_in_k_n[d]= 0.0;
			   ++num2;
			   ++d;
		     }

		     // while similar region AND num_non_similar_left<=all_left
		     while ( (d<=_ub) && (num2<=maskSize_m_n) ) {
			   _s_s+=  (_p_d_given_in_k_n[d]*= num2*one_div_maskSize_m_n); 
			   ++num2;
			   ++d;
		     }

		     // while non-similar region AND num_non_similar_left<=all_left
		     while ( (d<=_maskSize) && (num2<=maskSize_m_n) ) {
			   _s_ns+= (_p_d_given_in_k_n[d]*= num2*one_div_maskSize_m_n); 
			   ++num2;
			   ++d;
		     }

		     // case where num==num_non_similar_left>all_left
		     // event of next 1 has probability 0
		     while ( (d<=_maskSize) ) {
			   _p_d_given_in_k_n[d]= 0.0;
			   ++d;
		     }
		     
		     (*_ul)[n-1]= ++_k;
		     
	       } // end else of if s_ns>=B

	       //---------------------------------------------------------
	       // Normalization !!!
	       //---------------------------------------------------------	       
	       long double one_div_sum_p_in_k_and_d= 1.0/(_s_s+_s_ns);
	       for (d= 0; d<=_maskSize; ++d) {
		     _p_d_given_in_k_n[d]*= one_div_sum_p_in_k_and_d;
	       }
	       // true values of s_s and s_ns after normalization.
	       // However, since we compute:
	       // ( true(s_ns)/true(s_s) )==
	       // ( (s_ns/(s_s+s_ns)) / (s_s/(s_s+s_ns)) ==
	       // ( s_ns / s_s )
	       // There is no need for this normalization
	       //s_s/=(s_s+s_ns);
	       //s_ns/=(s_s+s_ns);
	       //---------------------------------------------------------	       
	       
	       
	 } // end for n
	 (*_ul)[_maskSize-1]= _ubp1;
	 
	 delete[] _p_d_given_in_k_n;
   } // main_loop




   
 public:
      
   
   /// Fills an array of rejection grades, assuming uniform prior.
   ///\param maskSize - the number of pattern pixels that are considered.
   ///       values greater than 0
   ///\param falseNegative - the max percent of undesired rejections.
   ///       (the false-positive is always 0)
   ///       values in the range [0,100)
   ///\param maxOcclusion - the max percent of the masked pattern pixels,
   ///       we allow not to match to	the image, still accepting this
   ///       location in the image.
   ///       values in the range [0,100)
   ///
   ///\output ul - vector initialized to size 'maskSize' 
   ///	      the value 'val' in the j-th place, means that if you sampled (j+1) pixels, and the
   ///        pattern doesn't match the image location in 'val' pixels, you should reject this
   ///        location.
   ///\return the bound on the similar windows distance. i.e: if the hamming distance
   ///        is smaller than this number than the window is similar to the pattern.
   ///        This value is: \f$\frac{maxOcclusion}{100}maskSize\f$
   int sprtRejectGradesArrayUniformPrior(const int& maskSize,
					  const long double& falseNegative,
					  const long double& maxOcclusion,
					  std::vector<int>& ul) {

	 init(maskSize,falseNegative,maxOcclusion,ul);
	 
	 // assuming uniform prior
	 long double div_d= (2.0/(maskSize*(maskSize+1)));
	 for (int d= 0; d<=_ub; ++d) {
	       _s_s+=  (_p_d_given_in_k_n[d]= d*div_d);
	 }
	 for (int d= _ubp1; d<=maskSize; ++d) {
	       _s_ns+= (_p_d_given_in_k_n[d]= d*div_d);
	 }

	 // P[D>t] / (fn * P[D<=t]), assuming uniform prior
	 // P[D>t] = (1/maskSize) * (maskSize-ub)
	 // P[D<=t]= (1/maskSIze) * (ub+1)
	 _B= ((_maskSize-_ub) / (((_ubp1))*(falseNegative/100.0)));
	 
	 
	 
	 main_loop();
     return _ub;
   } // end sprtRejectGradesArrayUniformPrior


   

   
   /// Fills an array of rejection grades, assuming given prior.
   ///\param - prior - an array of size 'maskSize+1' for each possible distance d=0..maskSize
   ///         prior[d] is the prior probability that the distance is equal to d.
   ///\see sprtRejectGradesArrayUniformPrior()
   int sprtRejectGradesArrayGivenPrior(const long double* const prior,
					const int& maskSize,
					const long double& falseNegative,
					const long double& maxOcclusion,
					std::vector<int>& ul) {
	 
	 #ifndef NDEBUG
	 long double prior_sum= 0;
	 for (int i=0; i<maskSize; ++i) {
         assert ( prior[i] > 0 );
         prior_sum+= prior[i];          
	 }
	 assert( (prior_sum > 0.9999)&&(prior_sum< 1.0001) );
	 #endif
	 
	 init(maskSize,falseNegative,maxOcclusion,ul);
	 
	 // assuming given prior
	 long double div_d= (1.0/maskSize);
	 long double p_similar,p_non_similar;
	 p_similar= (p_non_similar= 0);
	 for (int d= 0; d<=_ub; ++d) {
	       _s_s+=  (_p_d_given_in_k_n[d]= d*div_d*prior[d]);
	       p_similar+= prior[d];
	 }
	 for (int d= _ubp1; d<=maskSize; ++d) {
	       _s_ns+= (_p_d_given_in_k_n[d]= d*div_d*prior[d]);
	       p_non_similar+= prior[d];
	 }

	 // P[D>t] / (falseNegative * P[D<=t]), assuming given prior
	 _B= (p_non_similar) / ( (falseNegative/100.0)*p_similar );
	 
	 main_loop();
     return _ub;
   }
};
#endif


// Copyright (c) 2012, Ofir Pele
// All rights reserved.

// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met: 
//    * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//    * Neither the name of the The Hebrew University of Jerusalem nor the
//    names of its contributors may be used to endorse or promote products
//    derived from this software without specific prior written permission.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
// IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
