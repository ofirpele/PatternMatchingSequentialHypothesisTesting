#ifndef  _REJECTION_LINE_HPP_
#define  _REJECTION_LINE_HPP_

#include <cmath>

/// This class has two functions for computing an array of rejection points (rejectionLine). The first
/// function using uniform prior and the second using a given prior.
/// These are the implementations of Algorithm 5 in the paper:
///  Robust Real Time Pattern Matching using Bayesian Sequential Hypothesis Testing
///	   Ofir Pele, Michael Werman
///    PAMI 2008
/// Please cite the paper if you use this code.
class RejectionLine {
public:
    
    /// Fills an array of a rejection line, assuming uniform prior.
    ///
    ///\param vecSize - Size of the vectors compared (the maximum number of binary
    ///       dis-similarity checks that we will do). 
    ///       Denoted in paper as |A|.
    ///\param falseNegativePercentage - The max percentage of undesired rejections (the
    ///       false-positive is always 0). Values in the range [0,100).  For
    ///       example, if it is 0.1, we expect 0.1/100 of the 'similar' object pairs
    ///       to be declared as non-similar.
    ///       Denoted in paper as alpha (beta, which represents false-positive in
    ///       paper is assumed zero here).
    ///\param maxDiffPercentage - The max percentage of the dis-similarities that we
    ///       allow for similar objects.  Values in the range [0,100).
    ///       Denoted in paper as (t/|A|).
    ///
    ///\output rejectionLine - rejectionLine - An array of size vecSize. rejectionLine(i), means that if
    ///        you sampled (i+1) dis-similarties checks and out of them rejectionLine(i)
    ///        were true (there were rejectionLine(i) dis-similarties between the
    ///        objects), the two objects are classified as non-similar.
    ///\return the bound on the similar windows distance. i.e: if the hamming distance
    ///        is smaller than this number than the window is similar to the pattern.
    ///        This value is: (maxDiffPercentage/100)*vecSize
    int sprtRejectionLineUniformPrior(const int& vecSize,
                                      const double& falseNegativePercentage,
                                      const double& maxDiffPercentage,
                                      double* rejectionLine) {
        
        init(vecSize,falseNegativePercentage,maxDiffPercentage,rejectionLine);
        
        // assuming uniform prior
        long double div_d= (2.0/(vecSize*(vecSize+1)));
        for (int d= 0; d<=_ub; ++d) {
            _s_s+=  (_p_d_given_in_k_n[d]= d*div_d);
        }
        for (int d= _ubp1; d<=vecSize; ++d) {
            _s_ns+= (_p_d_given_in_k_n[d]= d*div_d);
        }
        
        // P[D>t] / (fn * P[D<=t]), assuming uniform prior
        // P[D>t] = (1/vecSize) * (vecSize-ub)
        // P[D<=t]= (1/maskSIze) * (ub+1)
        _B= ((_vecSize-_ub) / (((_ubp1))*(falseNegativePercentage/100.0)));
        
        main_loop();
        return _ub;
    } // end sprtRejectionLineUniformPrior
    
    
    
    
    
    /// Fills an array of a rejection line, assuming given prior.
    ///\param prior (optional) - An array of size 'vecSize+1' for each possible
    ///       d=0..vecSize+0, prior[d] is the prior probability that the distance is
    ///       equal to d.  If not given we assume uniform prior: prior(d)=
    ///       1/(vecSize+1)
    ///       Denoted in paper as P[d]. 
    ///
    ///\see sprtRejectionLineUniformPrior()
    int sprtRejectionLineGivenPrior(const double* const prior,
                                    const int& vecSize,
                                    const double& falseNegativePercentage,
                                    const double& maxDiffPercentage,
                                    double* rejectionLine) {
	 
#ifndef NDEBUG
        long double prior_sum= 0;
        for (int i=0; i<vecSize; ++i) {
            mc_assert ( prior[i] > 0 );
            prior_sum+= prior[i];          
        }
        mc_assert( (prior_sum > 0.9999)&&(prior_sum< 1.0001) );
#endif
        
        init(vecSize,falseNegativePercentage,maxDiffPercentage,rejectionLine);
        
        // assuming given prior
        long double div_d= (1.0/vecSize);
        long double p_similar,p_non_similar;
        p_similar= (p_non_similar= 0);
        for (int d= 0; d<=_ub; ++d) {
            _s_s+=  (_p_d_given_in_k_n[d]= d*div_d*prior[d]);
            p_similar+= prior[d];
        }
        for (int d= _ubp1; d<=vecSize; ++d) {
            _s_ns+= (_p_d_given_in_k_n[d]= d*div_d*prior[d]);
            p_non_similar+= prior[d];
        }
        
        // P[D>t] / (falseNegativePercentage * P[D<=t]), assuming given prior
        _B= (p_non_similar) / ( (falseNegativePercentage/100.0)*p_similar );
        
        main_loop();
        return _ub;
    }
    
    
private:
    
    int _vecSize;
    double* _rejectionLine;
    int _ub,_ubp1;
    int _k;
    long double* _p_d_given_in_k_n;
    long double _s_s,_s_ns;
    long double _B;
    
    
    
    void init(const int& vecSize,
              const long double& falseNegativePercentage,
              const long double& maxDiffPercentage,
              double* rejectionLine) {
	 
        mc_assert( vecSize > 0 );
        mc_assert( (falseNegativePercentage >= 0)&&(falseNegativePercentage < 100) );
        mc_assert( (maxDiffPercentage > 0)&&(maxDiffPercentage <= 100) );
	 
	 
        _rejectionLine= rejectionLine;
        _vecSize= vecSize;
        _ub= static_cast<int>(floor( (maxDiffPercentage/100.0)*vecSize ));
	 
        //cout << "_ub == " << _ub << endl;
        _ubp1= _ub+1;
	 
        // trying (n=1,k=1) as a rejection point
        _k= 1;
	 
        // cache
        _p_d_given_in_k_n= new long double[_vecSize+1];
	 
        // sum of similar and non-similar of p_d_given_in_k_n
        _s_s= (_s_ns= 0.0);

    } // init

    void main_loop() {
	 
	 
        int vecSize_m_n= _vecSize;
        for (int n=1; n<_vecSize; ++n) {

            --vecSize_m_n;
            long double one_div_vecSize_m_n= 1.0/vecSize_m_n;
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
                //     == (vecSize - n) - (d-k)
                //     == vecSize - n + k - d // d==k
                //     == vecSize - n + k - k 
                //     == vecSize - n
                long double num= vecSize_m_n;

                // while similar region AND num_similar_left>0
                while ( (d<=_ub) && (num>0) ) {
                    _s_s+=  (_p_d_given_in_k_n[d]*= num*one_div_vecSize_m_n);
                    ++d;
                    --num;
                }

                // while non-similar region AND num_similar_left>0
                while ( (d<=_vecSize) && (num>0) ) {
                    _s_ns+= (_p_d_given_in_k_n[d]*= num*one_div_vecSize_m_n);
                    ++d;
                    --num;
                }
		     
                // case where num==num_similar_left<=0
                // event of next 0 has probability 0
                while (d<=_vecSize) {
                    _p_d_given_in_k_n[d]= 0.0;
                    ++d;
                }
		     
                _rejectionLine[n-1]= _k;
		     
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
                while ( (d<=_ub) && (num2<=vecSize_m_n) ) {
                    _s_s+=  (_p_d_given_in_k_n[d]*= num2*one_div_vecSize_m_n); 
                    ++num2;
                    ++d;
                }

                // while non-similar region AND num_non_similar_left<=all_left
                while ( (d<=_vecSize) && (num2<=vecSize_m_n) ) {
                    _s_ns+= (_p_d_given_in_k_n[d]*= num2*one_div_vecSize_m_n); 
                    ++num2;
                    ++d;
                }

                // case where num==num_non_similar_left>all_left
                // event of next 1 has probability 0
                while ( (d<=_vecSize) ) {
                    _p_d_given_in_k_n[d]= 0.0;
                    ++d;
                }
		     
                _rejectionLine[n-1]= ++_k;
		     
            } // end else of if s_ns>=B

            //---------------------------------------------------------
            // Normalization !!!
            //---------------------------------------------------------	       
            long double one_div_sum_p_in_k_and_d= 1.0/(_s_s+_s_ns);
            for (d= 0; d<=_vecSize; ++d) {
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
        _rejectionLine[_vecSize-1]= _ubp1;
	 
        delete[] _p_d_given_in_k_n;
    } // main_loop

};
#endif

// Copyright (c) 2011, Ofir Pele
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

