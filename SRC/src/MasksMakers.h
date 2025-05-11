#ifndef _MASK_MAKERS_H
#define _MASK_MAKERS_H

#include <vector>
#include <opencv/cv.h>
#include <utility>
#include <algorithm>

#include <TRandomaNumberGenerator.h>
//#include <math.h> 

/// Contains makers of masks - functions that creates masks out of pattern and information about the image.
/// \param T_IsSimilarInputPattern - the mask is a std::vector of T_IsSimilarInputPattern::T_maskLocation.
template <typename T_IsSimilarInputPattern>
class MasksMakers
{
    
private:
    
    // init the mask with maskLocations.size() entries.
    static void InitMask(
        int reserveSpace,
        int imageWidthStep,
        const IplImage* pattern,
        const std::vector<typename T_IsSimilarInputPattern::T_maskLocation>& maskLocations,
        //output:
        std::vector<T_IsSimilarInputPattern>& maskVector) {
        
         
         assert( reserveSpace >= 0 );
         assert( imageWidthStep > 0 );
                
         T_IsSimilarInputPattern inputPattern;
	 	 maskVector.clear();
	 	 maskVector.reserve(reserveSpace);
	 	 typedef typename T_IsSimilarInputPattern::T_maskLocation LOC;
	 	 typedef typename std::vector<LOC>::const_iterator LOC_IT;
	 	 for (LOC_IT maskPtr=maskLocations.begin();
	 	  	  maskPtr!=maskLocations.end(); ++maskPtr)
	 	 {
	 	  inputPattern.fill(maskPtr,imageWidthStep,pattern);
	 	  maskVector.push_back(inputPattern);
		 }
         
     } // end InitMask




public:
	
	
	/// Make a mask.
	///\param imageWidth - the width of the image .
	///\param pattern - a pointer to a small image that the mask is masking.
	///\param maskLocations - vector that contains x,y pairs of valid pixels
	///        (one that the mask don't hide).
	///\output maskVector - vector that contains pairs.
	///			The first value is the distance in pixels from the pattern top-left in the image
	///			if the image is given in row-stack.
	///			The second value is a pixel gray level.
	///			The output contains only pixels that were in 'maskLocations'.
	///         The vector is being cleared and it's space is reserved in the 
    ///         function before it is filled.
    static void MakeMask(
        int imageWidthStep,
        const IplImage* pattern,
        const std::vector<typename T_IsSimilarInputPattern::T_maskLocation>& maskLocations,
        //output:
        std::vector<T_IsSimilarInputPattern>& maskVector) {
                
        InitMask(maskLocations.size(),imageWidthStep,pattern,maskLocations,maskVector);
        
    } // end MakeMask
	
	
	
	
	/// Make a shuffled mask. Randomness is dependant on the current time.
	///\see MakeMask
    static void MakeShuffledMask(
        int imageWidthStep,
        const IplImage* pattern,
        const std::vector<typename T_IsSimilarInputPattern::T_maskLocation>& maskLocations,
        //output:
        std::vector<T_IsSimilarInputPattern>& maskVector) {
        
        InitMask(maskLocations.size()*2,imageWidthStep,pattern,maskLocations,maskVector);
        
        // shuffle it
        //TRandomaNumberGenerator rg(100);
        std::random_shuffle(maskVector.begin(), maskVector.end());
        
//        for (unsigned int i= 0; i<maskVector.size(); ++i) {
//            int y= static_cast<int>(floor( maskVector[i].disparity / imageWidthStep ));
//            int x= maskVector[i].disparity - y*imageWidthStep;
//            cerr << y+1 << " " << x+1 << endl;
//        }

        // duplicate it to its end:
        maskVector.insert( maskVector.end() , maskVector.begin() , maskVector.end() );
                
    } // end MakeShuffledMask
	
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
