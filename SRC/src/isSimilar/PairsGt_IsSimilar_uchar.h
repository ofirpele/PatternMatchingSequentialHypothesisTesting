#ifndef PAIRSGT_ISSIMILAR_UCHAR_H_
#define PAIRSGT_ISSIMILAR_UCHAR_H_

#include <isSimilar/Pairs_IsSimilarInputPattern.h>

/// Functor of concept IsSimilar that checks if one pixel in the image
/// is greater than another one (as was in the pattern). 
/// Name in paper: "Monotonic Relations".
/// Where a is greater than b is defined as: "a > b + THRESH"
/// \param THRESH - the given threshold.
template<uchar THRESH>
class PairsGt_IsSimilar_uchar {
public:
    /// \see FastMatcher::T_channel
	typedef uchar  T_channel; 
	/// \see FastMatcher::T_inputPattern
	typedef Pairs_IsSimilarInputPattern T_inputPattern; 
    /// \see FastMatcher::T_maskLocation
    typedef typename T_inputPattern::T_maskLocation T_maskLocation;
    
    
    /// Functor of concept IsSimilar that checks if one pixel in the image
    /// is greater than another one (as was in the pattern).
    /// Where a is greater than b is defined as: "a > b + THRESH"
    /// \param placeInShuffledMask - the disparity of the two pixels in the image
	/// \param patternTopLeftOnImage - pointer to the top left pixel of the current window in the image.
	/// \return 0 for similar(the first pixel is greater) and 1 for non similar.
    int operator()(const T_inputPattern& placeInShuffledMask, 
                   const T_channel* patternTopLeftOnImage,
                   const int widthStep=0) const {
        
                           
        
//        if ( *(patternTopLeftOnImage+placeInShuffledMask.disparityA) > 
//             *(patternTopLeftOnImage+placeInShuffledMask.disparityB) + THRESH )
//        
//        patternTopLeftOnImage-= (widthStep+1);
//        if ( *(patternTopLeftOnImage+placeInShuffledMask.disparityA) > 
//             *(patternTopLeftOnImage+placeInShuffledMask.disparityB) + THRESH )
//            return 0;
//            
//        ++patternTopLeftOnImage;
//        if ( *(patternTopLeftOnImage+placeInShuffledMask.disparityA) > 
//             *(patternTopLeftOnImage+placeInShuffledMask.disparityB) + THRESH )
//            return 0;
//        
//        ++patternTopLeftOnImage;
//        if ( *(patternTopLeftOnImage+placeInShuffledMask.disparityA) > 
//             *(patternTopLeftOnImage+placeInShuffledMask.disparityB) + THRESH )
//            return 0;
//        
//        patternTopLeftOnImage+= widthStep;
//        if ( *(patternTopLeftOnImage+placeInShuffledMask.disparityA) > 
//             *(patternTopLeftOnImage+placeInShuffledMask.disparityB) + THRESH )
//            return 0;
//        
//        patternTopLeftOnImage+= 2;
//        if ( *(patternTopLeftOnImage+placeInShuffledMask.disparityA) > 
//             *(patternTopLeftOnImage+placeInShuffledMask.disparityB) + THRESH )
//            return 0;
//        
//        patternTopLeftOnImage+= widthStep;
//        if ( *(patternTopLeftOnImage+placeInShuffledMask.disparityA) > 
//             *(patternTopLeftOnImage+placeInShuffledMask.disparityB) + THRESH )
//            return 0;
//        
//        ++patternTopLeftOnImage;
//        if ( *(patternTopLeftOnImage+placeInShuffledMask.disparityA) > 
//             *(patternTopLeftOnImage+placeInShuffledMask.disparityB) + THRESH )
//            return 0;
//        
//        ++patternTopLeftOnImage;
//        return ( *(patternTopLeftOnImage+placeInShuffledMask.disparityA) <= 
//                *(patternTopLeftOnImage+placeInShuffledMask.disparityB) + THRESH );
//           
//                
        
        
        return ( *(patternTopLeftOnImage+placeInShuffledMask.disparityA) <= 
                 *(patternTopLeftOnImage+placeInShuffledMask.disparityB) + THRESH
               );
		
	}

};

#endif /*PAIRSGT_ISSIMILAR_UCHAR_H_*/


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
