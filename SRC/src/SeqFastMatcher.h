#ifndef _SEQ_FAST_MATCHER
#define _SEQ_FAST_MATCHER

// for checking time of program
//#include <sys/param.h>
//#include <sys/times.h>
//#include <sys/types.h>
//#include <iostream>
//using namespace std;

#include <FastMatcher.h> // Father
#include <RejectGrades.h>

#include <runner/StatisticsMaker.h>
extern StatisticsMaker GLOBAL_num_iterations;

/// Does fast matching of a pattern with images sequentialy.
/// \param T_isSimilar - the functor that is used to decide whether
///        two pixels are similar.
/// \param REC_IS_SIMILAR_CALLS_FLAG - should we do recording of how 
///        much times is similar calls flag was called. 
template<typename T_isSimilar, bool REC_IS_SIMILAR_CALLS_FLAG=false>
    class SeqFastMatcher : public FastMatcher<T_isSimilar> {
    
public:
    
    /// Constructor.
    /// \param imageWidthStep - size of aligned image row in bytes (see IplImage.widthStep)
    /// \param pattern - pattern image
    /// \param maskLocations - locations mask 
    ///        (for example 2D points that are the mask for the pattern or
    ///         pairs of 2D points)
    /// \param falseNegative - the max percent of undesired rejections.
    ///        (the false-positive is always 0)
    ///        Values in the range [0,100)
    /// \param maxOcclusion - the max percent of the masked pattern pixels,
    ///        we allow not to match to the image, still accepting this
    ///        location in the image.
    ///        Values in the range [0,100)
    SeqFastMatcher(
        
        int imageWidthStep,
        IplImage* pattern,
        
        std::vector<typename T_isSimilar::T_maskLocation>& maskLocations,
        const double& falseNegative,
        const double& maxOcclusion)
        : FastMatcher<T_isSimilar>(imageWidthStep,pattern,maskLocations),
        m_falseNegative(falseNegative),
        m_maxOcclusion(maxOcclusion),
        m_randGen(maskLocations.size())
        
        
        
        
        {
        //cerr << "Begin Ctor Of SeqFast" << endl;
        
        typedef MasksMakers<typename FastMatcher<T_isSimilar>::T_inputPattern> T_masksMakers;
        T_masksMakers::MakeShuffledMask(imageWidthStep,
            FastMatcher<T_isSimilar>::m_pattern,
            FastMatcher<T_isSimilar>::m_maskLocations,
            FastMatcher<T_isSimilar>::m_mask);
        
        
        
        createRejectGrades();
        
        
        //struct tms b,e;
        //long br,er;
        
        //br= times(&b);
        
        //for (int i= 0; i<1000; ++i) {
        //createRejectGrades();
        //}
        
        //er= times(&e);
        
        //double avgTime=
        //   ((long double)(e.tms_utime-b.tms_utime))
        //    / (1000*HZ);
        //cout << "|A|==" << maskLocations.size() << "OPT==" << avgTime << endl;
        
                    
    } // end ctor
    
    void createRejectGrades() {
        
//        RejectGrades rg;
//        
//        //---------------------------------------
//        std::vector<long double> prior_vec;
//                
//        // india
//        //std::ifstream in("/cs/vis/ofirpele/pics_and_movies/fast_pattern_matching_images/fm_india/hist.txt");
//        // crowd
//        //std::ifstream in("/cs/vis/ofirpele/pics_and_movies/fast_pattern_matching_images/fm_crowd/hist.txt");
//        // snake
//        // std::ifstream in("/cs/vis/ofirpele/pics_and_movies/fast_pattern_matching_images/zoo/snake/hist.txt");
//        // maras
//        //std::ifstream in("/cs/vis/ofirpele/pics_and_movies/fast_pattern_matching_images/zoo/mara/hist.txt");
//        // frog
//        std::ifstream in("/cs/vis/ofirpele/pics_and_movies/fast_pattern_matching_images/zoo/frogs/hist.txt");
//        
//        long double curr_double;
//        
//        while (in>>curr_double) {
//            prior_vec.push_back(curr_double);
//        };
//        
//        long double* prior= new long double[prior_vec.size()];
//        for (unsigned int i= 0; i<prior_vec.size(); ++i) {
//            prior[i]= prior_vec[i];
//        }
//        std::cout << "Prior |A|==" << prior_vec.size()-1 << std::endl;
//        //---------------------------------------
//                
//        m_ub=rg.sprtRejectGradesArrayGivenPrior
//            (prior,
//             FastMatcher<T_isSimilar>::m_maskLocations.size(),m_falseNegative,m_maxOcclusion,m_rejectedGradesArray);
        
        RejectGrades rg;
        m_ub= rg.sprtRejectGradesArrayUniformPrior(FastMatcher<T_isSimilar>::m_maskLocations.size(),m_falseNegative,m_maxOcclusion,m_rejectedGradesArray);
        
        //for (unsigned int i= 0; i<m_rejectedGradesArray.size(); ++i) {
        //    cerr << m_rejectedGradesArray[i] << " ";            
        // }
        //cerr << endl;
    }
    
    /// Measures approximate hamming similarity between template and 
    /// overlapped windows in the source image and fills the result 
    /// with the measurements.
    /// Results that are smaller than ub() are accurate.
    /// Results that are maskSize() are results of windows that
    /// the distance is probably bigger than ub(). There is a possibility
    /// of error with this windows which is smaller than falseNegative() percent.
    /// \param image - the source image.
    /// \param result - the results matrix.
    void cvHammingSamplingMatchTemplate(IplImage* image, CvMat* result) {
        
        // include the sequential implementation of this method 
        #define HS_SEQUENTIAL_HAMMING_MATCH_TEMPLATE_IMPL
        #include "cvHammingMatchTemplate.impl.h"       
        #undef HS_SEQUENTIAL_HAMMING_MATCH_TEMPLATE_IMPL
        
    } // end cvHammingSamplingMatchTemplate
    
    
    
    
    ///\see return value of RejectGrades.sprtRejectGradesArrayUniformPrior()
    int ub() const {
        return m_ub;
    }
    
    /// Returns the max percent of undesired rejections.
    /// (the false-positive is always 0)
    /// Values in the range [0,100)
    double falseNegative() const {
        return m_falseNegative;
    }
    
private:
    
    std::vector<int> m_rejectedGradesArray;
    int m_ub;
    double    m_falseNegative;
    double    m_maxOcclusion;
    TRandomaNumberGenerator m_randGen;
    
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
