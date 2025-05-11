/**
=====================================================================
* @author Ofir Pele
=====================================================================
*/

/*******************************************************************
 Include files:
********************************************************************/
#include "Test_MasksMakers.h"

#include <MasksMakers.h>

#include <isSimilar/OneChannel_IsSimilarInputPattern.h>

#include <opencv/cv.h>
#include <opencv/highgui.h>

#include <vector>

/*########################################################################
  Open namespace:
  ########################################################################*/
namespace Tests {

	/*==================== ctor & dtor ==============================*/
	Test_MasksMakers::Test_MasksMakers() {

		_funcs.push_back(&testMakeMask);
		_names.push_back("testMakeMask");
		_funcs.push_back(&testMakeShuffledMask);
		_names.push_back("testMakeShuffledMask");
	}// end Ctor


	//==============================================================
	/**@name tests functions */

    /**
     *
     */
    void Test_MasksMakers::testMakeMask() {
        
        int imageWidthStep= 7;
        
        IplImage* p1= cvLoadImage("Test_input/p1.bmp", 0);
        TEST_ASSERT_MSG(p1,"p1 not load");
        typedef OneChannel_IsSimilarInputPattern<uchar> T_IsSimilarInputPattern;
        std::vector<T_IsSimilarInputPattern::T_maskLocation> maskLocations;
        
        std::vector<T_IsSimilarInputPattern> maskVector; 
        
        typedef MasksMakers<T_IsSimilarInputPattern> MaskMaker;
        
        
        
        maskLocations.clear();
        maskLocations.push_back( Point(0,0) );
        MaskMaker::MakeMask(imageWidthStep,p1,maskLocations, maskVector);
        TEST_ASSERT_EQUAL(maskVector.size(),1);
        TEST_ASSERT_EQUAL(maskVector[0].disparity, 0);
        TEST_ASSERT_EQUAL((int)(maskVector[0].channel), 0);
                
        maskLocations.clear();
        maskLocations.push_back( Point(2,1) );
        maskLocations.push_back( Point(1,0) );
        maskLocations.push_back( Point(0,1) );
        
        MaskMaker::MakeMask(imageWidthStep,p1,maskLocations, maskVector);
        TEST_ASSERT_EQUAL(maskVector.size(),3);
        TEST_ASSERT_EQUAL(maskVector[0].disparity, 9);
        TEST_ASSERT_EQUAL((int)(maskVector[0].channel), 61);
        TEST_ASSERT_EQUAL(maskVector[1].disparity, 1);
        TEST_ASSERT_EQUAL((int)(maskVector[1].channel), 255);
        TEST_ASSERT_EQUAL(maskVector[2].disparity, 7);
        TEST_ASSERT_EQUAL((int)(maskVector[2].channel), 30);
                
    } // end testMakeMask

	/**
	*
	*/
	void Test_MasksMakers::testMakeShuffledMask() {
		 
        int imageWidthStep= 7;
        
        IplImage* p1= cvLoadImage("Test_input/p1.bmp", 0);
        TEST_ASSERT_MSG(p1,"p1 not load");
        typedef OneChannel_IsSimilarInputPattern<uchar> T_IsSimilarInputPattern;
        std::vector<T_IsSimilarInputPattern::T_maskLocation> maskLocations;
        
        std::vector<T_IsSimilarInputPattern> maskVector; 
        
        typedef MasksMakers<T_IsSimilarInputPattern> MaskMaker;
                
        // One entry - no shuffle...
        maskLocations.clear();
        maskLocations.push_back( Point(0,0) );
        MaskMaker::MakeShuffledMask(imageWidthStep,p1,maskLocations, maskVector);
        TEST_ASSERT_EQUAL(maskVector.size(),2);
        TEST_ASSERT_EQUAL(maskVector[0].disparity, 0);
        TEST_ASSERT_EQUAL((int)(maskVector[0].channel), 0);
		
		
		
		maskLocations.clear();
        maskLocations.push_back( Point(2,1) );
        maskLocations.push_back( Point(1,0) );
        maskLocations.push_back( Point(0,1) );
        MaskMaker::MakeShuffledMask(imageWidthStep,p1,maskLocations, maskVector);
          
        TEST_ASSERT_EQUAL_EXACT(maskVector.size(),6);
        TEST_ASSERT_EQUAL_EXACT(maskVector[0].disparity,maskVector[3].disparity);
        TEST_ASSERT_EQUAL_EXACT(maskVector[1].disparity,maskVector[4].disparity);
        TEST_ASSERT_EQUAL_EXACT(maskVector[2].disparity,maskVector[5].disparity);
        TEST_ASSERT_EQUAL_EXACT((int)(maskVector[0].channel),(int)(maskVector[3].channel) );
        
        double avg[]= {0,0,0,0,0,0};
        
        if (0) {
        // check randomness of permutations
        const int RAND_TIMES= 1000000;
        for (int i=0; i<RAND_TIMES; ++i) {
            MaskMaker::MakeShuffledMask(imageWidthStep,p1,maskLocations, maskVector);
            
            if (maskVector[0].disparity==9) {
                if (maskVector[1].disparity==7) {
                    ++avg[0];
                } else {
                    ++avg[1];
                }
            }
            
            if (maskVector[0].disparity==7) {
                if (maskVector[1].disparity==9) {
                    ++avg[2];
                } else {
                    ++avg[3];
                }
            }
            
            if (maskVector[0].disparity==1) {
                if (maskVector[1].disparity==7) {
                    ++avg[4];
                } else {
                    ++avg[5];
                }
            }
                                      
        } // end for i
        
        for (int i= 0; i<6; ++i) {
        	TEST_ASSERT_EQUAL( (int)(round(avg[i]/RAND_TIMES*100)) , 17 );			
		}
    }
	} // end testMakeShuffledMask

//@}
// ==============================================================

}; // close namespace
/*********************************************************************
                                    EOF
**********************************************************************/


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
