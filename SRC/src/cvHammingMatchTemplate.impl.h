// g "m.step" cxtypes.h
// m.step = rows > 1 ? m.cols*CV_ELEM_SIZE(type) : 0;
// Thus this assert should always be true
assert (((result->step) == (result->width*4)));
                 
typedef FastMatcher<T_isSimilar> T_father;
typedef typename FastMatcher<T_isSimilar>::T_channel T_channel;
typedef typename FastMatcher<T_isSimilar>::T_inputPattern T_inputPattern;

assert( image->widthStep == FastMatcher<T_isSimilar>::m_imWidthStep );
assert ((FastMatcher<T_isSimilar>::m_imWidthStep / image->width)==sizeof(T_channel));
assert( image->height >= FastMatcher<T_isSimilar>::m_pattern->height);
assert( image->width >= FastMatcher<T_isSimilar>::m_pattern->width);
assert( result->height == image->height - FastMatcher<T_isSimilar>::m_pattern->height + 1);
assert( result->width == image->width - FastMatcher<T_isSimilar>::m_pattern->width + 1);

int* resultPtr = result->data.i;

const T_channel* firstPatternInRowsPtr = (T_channel*)(image->imageData);
// Pointer to the begining of the last row that is possible that the pattern fits in (i.e: including this row)
const T_channel* lastPatternInRowsPtr = (firstPatternInRowsPtr) + (FastMatcher<T_isSimilar>::m_imWidthStep*(image->height-FastMatcher<T_isSimilar>::m_pattern->height));

T_inputPattern* maskStartPtr= &(FastMatcher<T_isSimilar>::m_mask[0]);
for (const T_channel* row = firstPatternInRowsPtr;
row <= lastPatternInRowsPtr;
row += FastMatcher<T_isSimilar>::m_imWidthStep)
    {
    
    // const T_channel* lastPatternInRowPtr = row + (step*(image->width-FastMatcher<T_isSimilar>::m_pattern->width));
    // No need for step as the + is pointers arithmetics
    // Pointer to the last top left window that the pattern can fit in in the current row.  
    const T_channel* lastPatternInRowPtr = row + (image->width-FastMatcher<T_isSimilar>::m_pattern->width);
    
    // going over coloumns
    for (const T_channel* patternTopLeftOnImage = row ; 
    patternTopLeftOnImage <= lastPatternInRowPtr ;
    ++patternTopLeftOnImage)
        {
        int countDifferentPixels=0;
        
        //now patternTopLeftOnImage is a pointer to a place in the image, so we start sampling/going over all pixels:
                
        T_inputPattern* placeInMask = maskStartPtr
#ifdef HS_SEQUENTIAL_HAMMING_MATCH_TEMPLATE_IMPL
            + m_randGen(); 
#else
        ;
#endif

#ifdef HS_SEQUENTIAL_HAMMING_MATCH_TEMPLATE_IMPL
        std::vector<int>::iterator placeInRejectGradeArray = m_rejectedGradesArray.begin();
#endif
        
        for (int c=0; c<FastMatcher<T_isSimilar>::maskSize(); ++c) {
        
            
            countDifferentPixels+= T_father::m_isSimilar(*placeInMask,patternTopLeftOnImage,this->m_imWidthStep);
            //countDifferentPixels+= T_father::m_isSimilar(*placeInMask,patternTopLeftOnImage);
            
#ifdef HS_SEQUENTIAL_HAMMING_MATCH_TEMPLATE_IMPL
            assert(countDifferentPixels<=(*placeInRejectGradeArray));
            if (countDifferentPixels == (*placeInRejectGradeArray))
                {
                //this pattern location can already be rejected:
                *resultPtr= FastMatcher<T_isSimilar>::m_maskSize;
#ifdef HS_SEQUENTIAL_HAMMING_MATCH_TEMPLATE_IMPL    
                if (REC_IS_SIMILAR_CALLS_FLAG) {
                    GLOBAL_num_iterations.update(c+1);
                }
#endif                
                goto nextWindowLabel;
            }
            ++placeInRejectGradeArray;                    
#endif
            
            ++placeInMask;
        } // end for c
#ifdef HS_SEQUENTIAL_HAMMING_MATCH_TEMPLATE_IMPL    
        if (REC_IS_SIMILAR_CALLS_FLAG) {
            GLOBAL_num_iterations.update(FastMatcher<T_isSimilar>::maskSize());
        }
#endif                
        *resultPtr= countDifferentPixels;
#ifdef HS_SEQUENTIAL_HAMMING_MATCH_TEMPLATE_IMPL
    nextWindowLabel:
#endif
        ++resultPtr;                        
    } // end for on coloumns in image
} // end for on rows in image


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
