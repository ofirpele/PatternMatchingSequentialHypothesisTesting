#ifndef _LU_SEQ_FAST_MATCHER
#define _LU_SEQ_FAST_MATCHER

// FastMatcher<T_isSimilar>::m_maskSize
//m_LUmaskSize

#include <FastMatcher.h> // Father
#include <RejectGrades.h>

#include <runner/StatisticsMaker.h>
extern StatisticsMaker GLOBAL_num_iterations;
extern unsigned int GLOBAL_windows_not_visited;

/// Does fast matching of a pattern with images sequentialy.
/// For extra speed uses also LU.
/// \param T_isSimilar - the functor that is used to decide whether
///        two pixels are similar.
/// \param REC_IS_SIMILAR_CALLS_FLAG - should we do recording of how 
///        much times is similar calls flag was called. 
template<typename T_isSimilar, bool REC_IS_SIMILAR_CALLS_FLAG=false>
    class LUSeqFastMatcher : public FastMatcher<T_isSimilar> {
    
    
    
public:
    
    typedef FastMatcher<T_isSimilar> T_father;
    typedef typename FastMatcher<T_isSimilar>::T_channel T_channel;
    typedef typename FastMatcher<T_isSimilar>::T_inputPattern T_inputPattern;
    
    /// Constructor.
    /// \param imageWidthStep - size of aligned image row in bytes (see IplImage.widthStep)
    /// \param imageWidth
    /// \param imageHeight
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
    /// \param LUmaskLocations - same as maskLocations for LU
    /// \param LUfalseNegative - same as falseNegative for LU
    /// \param LUmaxOcclusion - same as maxOcclusion for LU
    /// \param LUX
    /// \param LUY 
    LUSeqFastMatcher(
        
        int imageWidthStep,
        int imageWidth,
        int imageHeight,
        
        IplImage* pattern,
        
        std::vector<typename T_isSimilar::T_maskLocation>& maskLocations,
        const double& falseNegative,
        const double& maxOcclusion,
        
        std::vector<typename T_isSimilar::T_maskLocation>& LUmaskLocations,
        double LUfalseNegative,
        double LUmaxOcclusion,
        int LUX,
        int LUY)
        
        : FastMatcher<T_isSimilar>(imageWidthStep,pattern,maskLocations),
        m_falseNegative(falseNegative),
        m_maxOcclusion(maxOcclusion),
        
        
        
        m_LUmaskLocations(LUmaskLocations),
        m_LUfalseNegative(LUfalseNegative),
        m_LUmaxOcclusion(LUmaxOcclusion),
        
        m_LUjumpColoumns(LUX+1),
        m_LUjumpRows((imageWidthStep)*(LUY+1)),
        
        
        
        
        m_LUmaskSize(LUmaskLocations.size()),
        m_LUxwidthStepPlusOne((imageWidthStep)*(LUY)+1),
        
        m_LUX(LUX),
        m_LUY(LUY),
        
        m_randGen(maskLocations.size()),
        m_LUrandGen(LUmaskLocations.size())
    
        {
       
        typedef MasksMakers<typename FastMatcher<T_isSimilar>::T_inputPattern> T_masksMakers;
        
        T_masksMakers::MakeShuffledMask(imageWidthStep,
            FastMatcher<T_isSimilar>::m_pattern,
            FastMatcher<T_isSimilar>::m_maskLocations,
            FastMatcher<T_isSimilar>::m_mask);
        
        T_masksMakers::MakeShuffledMask(imageWidthStep,
            FastMatcher<T_isSimilar>::m_pattern,
            m_LUmaskLocations,
            m_LUmask);
        
        RejectGrades rg;
        
        m_ub= rg.sprtRejectGradesArrayUniformPrior
            (FastMatcher<T_isSimilar>::m_maskLocations.size(),
             m_falseNegative,m_maxOcclusion,m_rejectedGradesArray);
        
        m_LUub= rg.sprtRejectGradesArrayUniformPrior
            (m_LUmaskLocations.size(),
             m_LUfalseNegative,m_LUmaxOcclusion,m_LUrejectedGradesArray);
        
    } // end ctor
    
    /// Measures approximate hamming similarity between template and 
    /// overlapped windows in the source image and fills the result 
    /// with the measurements.
    /// Results that are smaller than ub() are accurate.
    /// Results that are maskSize() are results of windows that
    /// the distance is probably bigger than ub(). There is a possibility
    /// of error with this windows.
    /// The method jumps more than one window in each step according
    /// to the LU technique (TODO: write more...)
    /// \param image - the source image.
    /// \param result - the results matrix.
    void cvHammingSamplingMatchTemplate(IplImage* image, CvMat* result) {
        
        if (REC_IS_SIMILAR_CALLS_FLAG) {
            GLOBAL_windows_not_visited= result->width*result->height;
        }
        
        // Move to the start of (LUY+1) next row in result ==
        // ( move to next row start           + go back one win ) + ( move LUY rows     ) ==
        // ( (move to end of current row) + 1 + (-(LUX+1))       ) + ( move LUY rows     ) ==
        // ( ((result->width-1)%(LUX+1)  ) - LUX                  ) + ( LUY*result->width ) 
        m_LUresJumpRows=(
           ( ((result->width-1)%(m_LUX+1)  ) - m_LUX                  ) + ( m_LUY*result->width )                      );
        m_LUresJumpSmallWinRow=(result->width-1)-m_LUX;
        
                
        // g "m.step" cxtypes.h
        // m.step = rows > 1 ? m.cols*CV_ELEM_SIZE(type) : 0;
        // Thus this assert should always be true
        assert(((result->step) == (result->width*4)));
        assert( image->widthStep == FastMatcher<T_isSimilar>::m_imWidthStep );
        assert((FastMatcher<T_isSimilar>::m_imWidthStep / image->width)==sizeof(T_channel));
        assert( image->height >= FastMatcher<T_isSimilar>::m_pattern->height);
        assert( image->width >= FastMatcher<T_isSimilar>::m_pattern->width);
        assert( result->height == image->height - FastMatcher<T_isSimilar>::m_pattern->height + 1);
        assert( result->width == image->width - FastMatcher<T_isSimilar>::m_pattern->width + 1);
        
        // fill with max values
        cvSet( result, cvScalar(FastMatcher<T_isSimilar>::m_maskSize));
        int* resultPtr = result->data.i;

        const T_channel* firstPatternInRowsPtr = (T_channel*)(image->imageData);
        // Pointer to the begining of the last row that is possible 
        // that the pattern fits in (i.e: including this row)
        const T_channel* lastPatternInRowsPtr = 
            (firstPatternInRowsPtr) + 
            (FastMatcher<T_isSimilar>::m_imWidthStep*(image->height-FastMatcher<T_isSimilar>::m_pattern->height));
        
        const T_channel* oneRowAfterlastPatternInRowsPtr = 
            lastPatternInRowsPtr + FastMatcher<T_isSimilar>::m_imWidthStep;
        
        T_inputPattern* maskStartPtr= &(FastMatcher<T_isSimilar>::m_mask[0]);
        T_inputPattern* LUmaskStartPtr= &(m_LUmask[0]);

        // Going on rows in big jumps
        for (const T_channel* row = firstPatternInRowsPtr;
             row <= lastPatternInRowsPtr;
             row += m_LUjumpRows)
            {
            
            // No need for step as the + is pointers arithmetics
            // Pointer to the last top left window that the pattern 
            // can fit in in the current row.  
            const T_channel* lastPatternInRowPtr = row + (image->width-FastMatcher<T_isSimilar>::m_pattern->width);
            
            // going over coloumns in big jumps
            for (const T_channel* patternTopLeftOnImage = row ; 
                 patternTopLeftOnImage <= lastPatternInRowPtr ;
                 patternTopLeftOnImage += m_LUjumpColoumns)
                {
                int countDifferentPixels=0;
        
                //now patternTopLeftOnImage is a pointer to a place in the image, 
                //so we start sampling/going over LU pixels:
                
                T_inputPattern* LUplaceInMask = LUmaskStartPtr
                    + m_LUrandGen(); 
                
                std::vector<int>::iterator LUplaceInRejectGradeArray = m_LUrejectedGradesArray.begin();
                
                // LU test
                for (int c=0; c<m_LUmaskSize; ++c) {
                    
                    countDifferentPixels+= T_father::m_isSimilar(*LUplaceInMask,patternTopLeftOnImage,this->m_imWidthStep);
            
                    assert(countDifferentPixels<=(*LUplaceInRejectGradeArray));
                    if (countDifferentPixels == (*LUplaceInRejectGradeArray))
                        {
                        //this pattern location can already be rejected:
                        //Note that result is by default m_maskSize
                        if (REC_IS_SIMILAR_CALLS_FLAG) {
                            GLOBAL_num_iterations.update(c+1);
                            --GLOBAL_windows_not_visited;
                        }

                        goto nextLUWindowLabel;
                    } // end rejection
                    ++LUplaceInRejectGradeArray;                    
                    
                    ++LUplaceInMask;
                } // end for c
                
                // passed the LU test. Now the regular test
                // For ALL the small LU window
                {
                
                
                
                using std::min;
                
                const T_channel* oneAfterSmallWinRowEnd= 
                    min(patternTopLeftOnImage+m_LUxwidthStepPlusOne,
                        oneRowAfterlastPatternInRowsPtr);
                
                int* smallWinResultPtr= resultPtr;
                
                const T_channel* smallWinLastPatternInRowPtr = 
                    lastPatternInRowPtr;
                
                for (const T_channel* smallWinRow = patternTopLeftOnImage;
                     smallWinRow < oneAfterSmallWinRowEnd;
                     smallWinRow += FastMatcher<T_isSimilar>::m_imWidthStep) {
                    
                    const T_channel* smallWinPatternTopLeftOnImageEnd=
                        min(smallWinRow+m_LUX,
                            smallWinLastPatternInRowPtr);
                    for (const T_channel* smallWinPatternTopLeftOnImage = smallWinRow ; 
                         smallWinPatternTopLeftOnImage <= smallWinPatternTopLeftOnImageEnd;
                         ++smallWinPatternTopLeftOnImage) {
                        
                        
                                                
                        countDifferentPixels=0;
                        T_inputPattern* placeInMask = maskStartPtr
                            + m_randGen(); 
                        
                        std::vector<int>::iterator placeInRejectGradeArray = m_rejectedGradesArray.begin();
                        
                        for (int c=0; c<FastMatcher<T_isSimilar>::maskSize(); ++c) {
                            
                            countDifferentPixels+= T_father::m_isSimilar(*placeInMask,smallWinPatternTopLeftOnImage,this->m_imWidthStep);
                            
                            assert(countDifferentPixels<=(*placeInRejectGradeArray));
                            if (countDifferentPixels == (*placeInRejectGradeArray))
                                {
                                //this pattern location can already be rejected:
                                if (REC_IS_SIMILAR_CALLS_FLAG) {
                                    GLOBAL_num_iterations.update(c+1+m_LUmaskSize);
                                    --GLOBAL_windows_not_visited;
                                }
                                goto nextWindowLabel;
                            }
                            ++placeInRejectGradeArray;                    
                            ++placeInMask;
                        } // end for c
                        
                        // window passed both LU and regular test -
                        // it's similar
                        if (REC_IS_SIMILAR_CALLS_FLAG) {
                            GLOBAL_num_iterations.update(FastMatcher<T_isSimilar>::maskSize()+m_LUmaskSize);
                            --GLOBAL_windows_not_visited;
                        }
                        
                        *smallWinResultPtr= countDifferentPixels;
                    nextWindowLabel:
                        ++smallWinResultPtr;
                    } // smallWinPatternTopLeftOnImage
                    smallWinLastPatternInRowPtr+= FastMatcher<T_isSimilar>::m_imWidthStep;
                    smallWinResultPtr+= m_LUresJumpSmallWinRow;
                } // smallWinRow
                } // LU small window all test
                        
            nextLUWindowLabel:
                resultPtr+= m_LUjumpColoumns;                        
            } // end for jumps on coloumns in image
            resultPtr+= m_LUresJumpRows;
        } // end for jumps on rows in image
        
        
        if (REC_IS_SIMILAR_CALLS_FLAG) {
            for (unsigned int i= 0; i<GLOBAL_windows_not_visited; ++i) {
                GLOBAL_num_iterations.update(0);
            }
        }
        
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
    
    // LU stuff
    std::vector<int> m_LUrejectedGradesArray;
    std::vector<typename T_father::T_maskLocation>& m_LUmaskLocations;
    int m_LUub;
    double    m_LUfalseNegative;
    double    m_LUmaxOcclusion;
    const int m_LUjumpColoumns;
    const int m_LUjumpRows;
    int m_LUresJumpRows;
    int m_LUresJumpSmallWinRow;
    std::vector<T_inputPattern> m_LUmask;
    int m_LUmaskSize;
    int m_LUxwidthStepPlusOne;
    const int m_LUX;
    const int m_LUY;
    
    TRandomaNumberGenerator m_randGen;
    TRandomaNumberGenerator m_LUrandGen;
    
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
