#ifndef DIFFABS_ISSIMILAR_UCHAR_H_
#define DIFFABS_ISSIMILAR_UCHAR_H_

#include <isSimilar/OneChannel_IsSimilarInputPattern.h>
#include <isSimilar/Point.h>

/// Functor of concept IsSimilar that checks if the absolute value of the
/// difference between two pixels of one channel is smaller or equal to
/// a given threshold.
/// \param THRESH - the given threshold.
template<uchar THRESH>
class DiffAbs_IsSimilar_uchar {

public:


    /// \see FastMatcher::T_channel
  typedef uchar  T_channel;
  /// \see FastMatcher::T_inputPattern
  typedef OneChannel_IsSimilarInputPattern<T_channel>
          T_inputPattern;
    /// \see FastMatcher::T_maskLocation
  typedef typename T_inputPattern::T_maskLocation T_maskLocation;


  /// Functor of concept IsSimilar that checks if the absolute value of the
  /// difference between two pixels of one channel is smaller or equal to
  /// a given threshold.
  /// \param placeInShuffledMask - the data of the current pixel in the pattern that is examined.
  /// \param patternTopLeftOnImage - pointer to the top left pixel of the current window in the image.
  /// \return 0 for similar and 1 for non similar.
    int operator()(const T_inputPattern& placeInShuffledMask,
                   const T_channel* patternTopLeftOnImage,
                   const int widthStep=0) const {

//        int intensity_diff= (*(patternTopLeftOnImage+placeInShuffledMask.disparity))
//            - (placeInShuffledMask.channel);
//        if (!((intensity_diff > THRESH)||(intensity_diff < -THRESH))) return 0;
//
//        patternTopLeftOnImage-= (widthStep+1);
//        intensity_diff= (*(patternTopLeftOnImage+placeInShuffledMask.disparity))
//            - (placeInShuffledMask.channel);
//        if (!((intensity_diff > THRESH)||(intensity_diff < -THRESH))) return 0;
//
//        ++patternTopLeftOnImage;
//        intensity_diff= (*(patternTopLeftOnImage+placeInShuffledMask.disparity))
//            - (placeInShuffledMask.channel);
//        if (!((intensity_diff > THRESH)||(intensity_diff < -THRESH))) return 0;
//
//        ++patternTopLeftOnImage;
//        intensity_diff= (*(patternTopLeftOnImage+placeInShuffledMask.disparity))
//            - (placeInShuffledMask.channel);
//        if (!((intensity_diff > THRESH)||(intensity_diff < -THRESH))) return 0;
//
//        patternTopLeftOnImage+= widthStep;
//        intensity_diff= (*(patternTopLeftOnImage+placeInShuffledMask.disparity))
//            - (placeInShuffledMask.channel);
//        if (!((intensity_diff > THRESH)||(intensity_diff < -THRESH))) return 0;
//
//        patternTopLeftOnImage+= 2;
//        intensity_diff= (*(patternTopLeftOnImage+placeInShuffledMask.disparity))
//            - (placeInShuffledMask.channel);
//        if (!((intensity_diff > THRESH)||(intensity_diff < -THRESH))) return 0;
//
//        patternTopLeftOnImage+= widthStep;
//        intensity_diff= (*(patternTopLeftOnImage+placeInShuffledMask.disparity))
//            - (placeInShuffledMask.channel);
//        if (!((intensity_diff > THRESH)||(intensity_diff < -THRESH))) return 0;
//
//        ++patternTopLeftOnImage;
//        intensity_diff= (*(patternTopLeftOnImage+placeInShuffledMask.disparity))
//            - (placeInShuffledMask.channel);
//        if (!((intensity_diff > THRESH)||(intensity_diff < -THRESH))) return 0;
//
//        ++patternTopLeftOnImage;
//        intensity_diff= (*(patternTopLeftOnImage+placeInShuffledMask.disparity))
//            - (placeInShuffledMask.channel);
//        if (!((intensity_diff > THRESH)||(intensity_diff < -THRESH))) return 0;
//
//        return 1;

//        cout << "image=="<<(int)(*(patternTopLeftOnImage+placeInShuffledMask.disparity)) << " pattern==" << (int)(placeInShuffledMask.channel) << endl;
        int intensity_diff= (*(patternTopLeftOnImage+placeInShuffledMask.disparity))
            - (placeInShuffledMask.channel);
        //THIS IS SLOWER -> return ((intensity_diff > THRESH)||(intensity_diff < -THRESH));
        if ((intensity_diff > THRESH)||(intensity_diff < -THRESH)) return 1;
        return 0;
    }



};

#endif /*DIFFABS_ISSIMILAR_H_*/


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
