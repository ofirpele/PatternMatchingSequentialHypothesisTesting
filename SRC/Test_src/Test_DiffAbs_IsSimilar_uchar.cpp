/**
=====================================================================
* @author Ofir Pele
=====================================================================
*/

/*******************************************************************
 Include files:
********************************************************************/
#include "Test_DiffAbs_IsSimilar_uchar.h"

#include <isSimilar/OneChannel_IsSimilarInputPattern.h>
#include <isSimilar/DiffAbs_IsSimilar_uchar.h>

#include <opencv/cv.h>
#include <opencv/highgui.h>

/*########################################################################
  Open namespace:
  ########################################################################*/
namespace Tests {

	/*==================== ctor & dtor ==============================*/
	Test_DiffAbs_IsSimilar_uchar::Test_DiffAbs_IsSimilar_uchar() {

		_funcs.push_back(&test1);
		_names.push_back("test1");
	}// end Ctor


	//==============================================================
	/**@name tests functions */

	/**
	*
	*/
	void Test_DiffAbs_IsSimilar_uchar::test1() {
		 
		 IplImage* im1= cvLoadImage("Test_input/im1.bmp", 0);
		 TEST_ASSERT_MSG(im1,"im1 not load");
		 TEST_ASSERT_EQUAL( im1->width , 6);
		 TEST_ASSERT_EQUAL( im1->height , 4);
		 
		 int imageWidthStep= im1->widthStep;
		 
		 IplImage* p1= cvLoadImage("Test_input/p1.bmp", 0);
		 TEST_ASSERT_MSG(p1,"p1 not load");
		 // isSimilarInputPattern to be fille11d each time
         OneChannel_IsSimilarInputPattern<uchar> ip;
	     std::vector<Point> points_vec;
	     	     	     	        
	     	 		 
		 DiffAbs_IsSimilar_uchar<20> t20;
		 DiffAbs_IsSimilar_uchar<69> t69;
		 DiffAbs_IsSimilar_uchar<70> t70;
		 
		 DiffAbs_IsSimilar_uchar<55> t55;
		 DiffAbs_IsSimilar_uchar<54> t54;
		 
		 DiffAbs_IsSimilar_uchar<0> t0;
		 
		 DiffAbs_IsSimilar_uchar<139> t139;
		 DiffAbs_IsSimilar_uchar<138> t138;
		 
		 
		 {
		 Point p(0,0); points_vec.clear(); points_vec.push_back(p); ip.fill(points_vec.begin(),imageWidthStep,p1);
		 Point pTopLeft(0,0); uchar* patternTopLeftOnImage= (uchar*)(im1->imageData+(pTopLeft.y*im1->widthStep)+pTopLeft.x);
		 TEST_ASSERT_EQUAL( t20(ip,patternTopLeftOnImage) ,  1 ); 
		 }
		 
		 
		 {
		 Point p(0,0); points_vec.clear(); points_vec.push_back(p); ip.fill(points_vec.begin(),imageWidthStep,p1);
		 Point pTopLeft(0,0); uchar* patternTopLeftOnImage= (uchar*)(im1->imageData+(pTopLeft.y*im1->widthStep)+pTopLeft.x);
		 TEST_ASSERT_EQUAL( t69(ip,patternTopLeftOnImage) ,  1 ); 
		 }
		 
		 
		 {
		 Point p(0,0); points_vec.clear(); points_vec.push_back(p); ip.fill(points_vec.begin(),imageWidthStep,p1);
		 Point pTopLeft(0,0); uchar* patternTopLeftOnImage= (uchar*)(im1->imageData+(pTopLeft.y*im1->widthStep)+pTopLeft.x);
		 TEST_ASSERT_EQUAL( t70(ip,patternTopLeftOnImage) ,  0 ); 
		 }
		 
		 
		 
		 
		 
		 
		 {
		 Point p(1,0); points_vec.clear(); points_vec.push_back(p); ip.fill(points_vec.begin(),imageWidthStep,p1);
		 Point pTopLeft(0,1); uchar* patternTopLeftOnImage= (uchar*)((im1->imageData)+(pTopLeft.y*im1->widthStep)+pTopLeft.x);
		 TEST_ASSERT_EQUAL( t55(ip,patternTopLeftOnImage) ,  0 ); 
		 }
		 
		 {
		 Point p(1,0); points_vec.clear(); points_vec.push_back(p); ip.fill(points_vec.begin(),imageWidthStep,p1);
		 Point pTopLeft(0,1); uchar* patternTopLeftOnImage= (uchar*)(im1->imageData+(pTopLeft.y*im1->widthStep)+pTopLeft.x);
		 TEST_ASSERT_EQUAL( t54(ip,patternTopLeftOnImage) ,  1 ); 
		 }
		 
		 
		 
		 
		 {
             for (int x= 0; x<3; ++x) {
                 for (int y= 0; y<2; ++y) {
                     Point p(x,y); points_vec.clear(); points_vec.push_back(p); ip.fill(points_vec.begin(),imageWidthStep,p1);
                     Point pTopLeft(2,0); uchar* patternTopLeftOnImage= (uchar*)(im1->imageData+(pTopLeft.y*im1->widthStep)+pTopLeft.x);
                     TEST_ASSERT_EQUAL( t0(ip,patternTopLeftOnImage) ,  0 ); 
                 }
             }
         }
         
         
		 {
		 Point p(2,1); points_vec.clear(); points_vec.push_back(p); ip.fill(points_vec.begin(),imageWidthStep,p1);
		 Point pTopLeft(3,2); uchar* patternTopLeftOnImage= (uchar*)(im1->imageData+(pTopLeft.y*im1->widthStep)+pTopLeft.x);
		 TEST_ASSERT_EQUAL( t139(ip,patternTopLeftOnImage) ,  0 ); 
		 }		 
		 {
		 Point p(2,1); points_vec.clear(); points_vec.push_back(p); ip.fill(points_vec.begin(),imageWidthStep,p1);
		 Point pTopLeft(3,2); uchar* patternTopLeftOnImage= (uchar*)(im1->imageData+(pTopLeft.y*im1->widthStep)+pTopLeft.x);
		 TEST_ASSERT_EQUAL( t138(ip,patternTopLeftOnImage) ,  1 ); 
		 }		 
		 
		 
		 
	} // end test1

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
