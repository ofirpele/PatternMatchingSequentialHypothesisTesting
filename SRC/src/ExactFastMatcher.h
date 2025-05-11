#ifndef _EXACT_FAST_MATCHER
#define _EXACT_FAST_MATCHER


#include <FastMatcher.h> // Father


/// Does fast matching of a pattern with images exactly.
/// \param T_isSimilar - the functor that is used to decide whether
///        two pixels are similar.
template<typename T_isSimilar>
    class ExactFastMatcher : public FastMatcher<T_isSimilar> {
    
public:
    
    /// Constructor.
    /// \param imageWidthStep - size of aligned image row in bytes (see IplImage.widthStep)
    /// \param pattern - pattern image
    /// \param maskLocations - locations mask 
    ///        (for example 2D points that are the mask for the pattern or
    ///         pairs of 2D points)
    ExactFastMatcher(
        
        int imageWidthStep,
        IplImage* pattern,
        
        std::vector<typename T_isSimilar::T_maskLocation>& maskLocations)
        
        : FastMatcher<T_isSimilar>(imageWidthStep,pattern,maskLocations)
                
        {
        
        
        typedef MasksMakers<typename FastMatcher<T_isSimilar>::T_inputPattern> T_masksMakers;
        T_masksMakers::MakeMask(imageWidthStep,
            FastMatcher<T_isSimilar>::m_pattern,
            FastMatcher<T_isSimilar>::m_maskLocations,
            FastMatcher<T_isSimilar>::m_mask);
                
    } // end ctor
    
    /// Measures exact hamming similarity between template and 
    /// overlapped windows in the source image and fills the result 
    /// with the measurements.
    /// \param image - the source image.
    /// \param result - the results matrix.
    void cvHammingMatchTemplate(IplImage* image, CvMat* result) {
        
        // include the exact implementation of this method 
        #undef HS_SEQUENTIAL_HAMMING_MATCH_TEMPLATE_IMPL
        #include "cvHammingMatchTemplate.impl.h"       
                
    } // end cvHammingSamplingMatchTemplate
        
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
