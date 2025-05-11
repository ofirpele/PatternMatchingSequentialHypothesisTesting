/**
=====================================================================
* @author Ofir Pele
=====================================================================
*/

/*******************************************************************
 Include files:
********************************************************************/
#include "Test_PairsGt_IsSimilar_uchar.h"

#include <isSimilar/Pairs_IsSimilarInputPattern.h>
#include <isSimilar/PairsGt_IsSimilar_uchar.h>

#include <opencv/cv.h>
#include <opencv/highgui.h>

/*########################################################################
  Open namespace:
  ########################################################################*/
namespace Tests {

	/*==================== ctor & dtor ==============================*/
	Test_PairsGt_IsSimilar_uchar::Test_PairsGt_IsSimilar_uchar() {

		_funcs.push_back(&test1);
		_names.push_back("test1");
		_funcs.push_back(&test2);
		_names.push_back("test2");
	}// end Ctor


	//==============================================================
	/**@name tests functions */

	/**
	*
	*/
	void Test_PairsGt_IsSimilar_uchar::test1() {
		 IplImage* im1= cvLoadImage("Test_input/im1.bmp", 0);
		 TEST_ASSERT_MSG(im1,"im1 not load");
		 TEST_ASSERT_EQUAL( im1->width , 6);
		 TEST_ASSERT_EQUAL( im1->height , 4);
		 
		 int imageWidthStep= im1->widthStep;
		 
		 // isSimilarInputPattern to be filled each time
         Pairs_IsSimilarInputPattern ip;
	     std::vector<Pairs_IsSimilarInputPattern::T_maskLocation> pairs_points_vec;
         
         PairsGt_IsSimilar_uchar<0> pgt;
         PairsGt_IsSimilar_uchar<40> pgt40;
         PairsGt_IsSimilar_uchar<39> pgt39;
         PairsGt_IsSimilar_uchar<130> pgt130;
         PairsGt_IsSimilar_uchar<129> pgt129;
         PairsGt_IsSimilar_uchar<64> pgt64;
         PairsGt_IsSimilar_uchar<65> pgt65;
         
         
         {
		 Point p1(1,1); Point p2(4,0); pairs_points_vec.clear(); pairs_points_vec.push_back( make_pair(p1,p2) ); ip.fill(pairs_points_vec.begin(),imageWidthStep,NULL);
		 Point pTopLeft(0,0); uchar* patternTopLeftOnImage= (uchar*)(im1->imageData+(pTopLeft.y*im1->widthStep)+pTopLeft.x);
		 TEST_ASSERT_EQUAL( pgt(ip,patternTopLeftOnImage) ,  0 ); 
         }
		 {       // 127            62
		 Point p1(1,0); Point p2(0,1); pairs_points_vec.clear(); pairs_points_vec.push_back( make_pair(p1,p2) ); ip.fill(pairs_points_vec.begin(),imageWidthStep,NULL);
		 Point pTopLeft(3,2); uchar* patternTopLeftOnImage= (uchar*)(im1->imageData+(pTopLeft.y*im1->widthStep)+pTopLeft.x);
		 TEST_ASSERT_EQUAL( pgt64(ip,patternTopLeftOnImage) ,  0 ); 
		 TEST_ASSERT_EQUAL( pgt65(ip,patternTopLeftOnImage) ,  1 ); 
		 
		 }
		 
		 
		 
         {
		 Point p1(0,0); Point p2(2,1); pairs_points_vec.clear(); pairs_points_vec.push_back( make_pair(p1,p2) ); ip.fill(pairs_points_vec.begin(),imageWidthStep,NULL);
		 Point pTopLeft(0,0); uchar* patternTopLeftOnImage= (uchar*)(im1->imageData+(pTopLeft.y*im1->widthStep)+pTopLeft.x);
		 TEST_ASSERT_EQUAL( pgt40(ip,patternTopLeftOnImage) ,  1 ); 
		 TEST_ASSERT_EQUAL( pgt39(ip,patternTopLeftOnImage) ,  0 ); 
		 }
		 
		 
		 {
		 Point p1(5,3); Point p2(0,0); pairs_points_vec.clear(); pairs_points_vec.push_back( make_pair(p1,p2) ); ip.fill(pairs_points_vec.begin(),imageWidthStep,NULL);
		 Point pTopLeft(0,0); uchar* patternTopLeftOnImage= (uchar*)(im1->imageData+(pTopLeft.y*im1->widthStep)+pTopLeft.x);
		 TEST_ASSERT_EQUAL( pgt130(ip,patternTopLeftOnImage) ,  1 ); 
		 TEST_ASSERT_EQUAL( pgt129(ip,patternTopLeftOnImage) ,  0 ); 
		 }
         
         
	} // end test1

	/**
	*
	*/
	void Test_PairsGt_IsSimilar_uchar::test2() {
		 
	} // end test2

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
