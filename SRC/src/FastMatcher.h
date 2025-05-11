#ifndef _FAST_MATCHER
#define _FAST_MATCHER

#include <vector>
#include <cassert>

#include <opencv/cv.h>

#include <TRandomaNumberGenerator.h>
#include <MasksMakers.h>

/// Does fast matching of a pattern with images sequentialy.
/// \param T_isSimilar - the functor that is used to decide whether
///        two pixels are similar.
template<typename T_isSimilar>
    class FastMatcher
    {
public:
    
    /// Type of the input from the pattern for operator() of the isSimilar functor. 
    typedef typename T_isSimilar::T_inputPattern T_inputPattern;
    
    /// Type of the location in mask (for example Point or pair<Point>).
    typedef typename T_isSimilar::T_maskLocation T_maskLocation;
    
    /// Type of channel in images.
    typedef typename T_isSimilar::T_channel T_channel;
    
    
    
        
        
    /// Returns the size of mask (For example, number of pixels or number
    /// of pairs of pixels.
    int maskSize() const {
        return m_maskSize;
    }
    
    
    
        
protected:
    
    // Constructor.
    // \param imageWidthStep - size of aligned image row in bytes (see IplImage.widthStep)
    // \param pattern - pattern image
    // \param maskLocations - locations mask 
    //        (for example 2D points that are the mask for the pattern or
    //         pairs of 2D points)
    // \param falseNegative - the max percent of undesired rejections.
    //        (the false-positive is always 0)
    //        Values in the range [0,100)
    // \param maxOcclusion - the max percent of the masked pattern pixels,
    //        we allow not to match to the image, still accepting this
    //        location in the image.
    //        Values in the range [0,100)
    FastMatcher(
        
        int imageWidthStep,
        IplImage* pattern,
        
        std::vector<T_maskLocation>& maskLocations)
        
        : m_pattern(pattern),
        m_maskLocations(maskLocations),
        m_imWidthStep(imageWidthStep), // NOT ALWAYS EQUAL TO imageWidth*sizeof(channel) !!!
        
        m_maskSize(maskLocations.size()
    ) {
        
        assert( imageWidthStep > 0 );
        
    } // end ctor    
    

    
    T_isSimilar m_isSimilar;
    
    IplImage* m_pattern;            
    std::vector<T_maskLocation>& m_maskLocations;
    
    int m_imWidthStep;
    
    std::vector<T_inputPattern> m_mask;
        
    int m_maskSize;
        
    
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
