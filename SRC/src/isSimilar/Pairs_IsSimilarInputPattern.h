#ifndef PAIRS_ISSIMILARINPUTPATTERN_H_
#define PAIRS_ISSIMILARINPUTPATTERN_H_

#include <opencv/cv.h> 
#include <vector> 
#include <isSimilar/Point.h>

/// Pairs of disparities of two pixels.
class Pairs_IsSimilarInputPattern {

public:
	
	/// How much to add to the pointer to the top left pixel of the current window in the image
	/// to get to the pixels in the image.
	int disparityA,disparityB;
    
    /// \see FastMatcher::T_maskLocation.
	typedef pair<Point,Point> T_maskLocation;
	
	/// Fills the disparities of this object.
	/// \param maskIterator - iterator to the current maskLocation.
	/// \param imageWidthStep - how much to add to a pointer in the image
	///                         in order to move one row.
	/// \param pattern - Ignored here - can be NULL.
    void fill(std::vector<T_maskLocation>::const_iterator maskIterator,
        int imageWidthStep,
        const IplImage* pattern)
    {
    	
        disparityA= ((maskIterator->first.y )*(imageWidthStep)) + (maskIterator->first.x);
        disparityB= ((maskIterator->second.y)*(imageWidthStep)) + (maskIterator->second.x);
        
    } // end fill
    
};
#endif /*PAIRS_ISSIMILARINPUTPATTERN_H_*/


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
