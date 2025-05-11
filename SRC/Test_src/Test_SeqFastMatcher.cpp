/**
=====================================================================
* @author Ofir Pele
=====================================================================
*/

/*******************************************************************
 Include files:
********************************************************************/
#include "Test_SeqFastMatcher.h"

#include <SeqFastMatcher.h> // Father
#include <isSimilar/Point.h>

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <isSimilar/DiffAbs_IsSimilar_uchar.h>
#include <isSimilar/PairsGt_IsSimilar_uchar.h>

/*########################################################################
  Open namespace:
  ########################################################################*/
namespace Tests {

	/*==================== ctor & dtor ==============================*/
	Test_SeqFastMatcher::Test_SeqFastMatcher() {

		_funcs.push_back(&test1);
		_names.push_back("test1");
		_funcs.push_back(&test2);
		_names.push_back("test2");
		_funcs.push_back(&test3);
		_names.push_back("test3");
		_funcs.push_back(&test4);
		_names.push_back("test4");
	}// end Ctor


	//==============================================================
	/**@name tests functions */

	/**
	*
	*/
	void Test_SeqFastMatcher::test1() {
		 
		 IplImage* im1= cvLoadImage("Test_input/im1.bmp", 0);
		 TEST_ASSERT_MSG(im1,"im1 not load");
		 TEST_ASSERT_EQUAL( im1->width , 6);
		 TEST_ASSERT_EQUAL( im1->height , 4);
         int imageWidthStep= im1->widthStep;
         
         IplImage* im2= cvLoadImage("Test_input/im2.bmp", 0);
		 TEST_ASSERT_MSG(im2,"im2 not load");
		 TEST_ASSERT_EQUAL( im2->width , 6);
		 TEST_ASSERT_EQUAL( im2->height , 4);

         IplImage* p1= cvLoadImage("Test_input/p1.bmp", 0);
		 TEST_ASSERT_MSG(p1,"p1 not load");

         CvMat* result= cvCreateMat(
             im1->height - p1->height + 1,
             im1->width  - p1->width  + 1,
             CV_32SC1);


         { 
             std::vector<Point> maskLocations;
             maskLocations.push_back(Point(0,0));
             maskLocations.push_back(Point(1,1));
             maskLocations.push_back(Point(2,0));

             typedef DiffAbs_IsSimilar_uchar<100> T100;
             SeqFastMatcher<T100> efm(
                 imageWidthStep,
                 p1,
                 maskLocations,
                 0.0,
                 100.0);

             efm.cvHammingSamplingMatchTemplate(im1,result);
             TEST_ASSERT_EQUAL_EXACT( result->rows , 3 );
             TEST_ASSERT_EQUAL_EXACT( result->cols , 4 );

             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,0) , 2 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,1) , 1 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,2) , 0 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,3) , 1 );

             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,0) , 0 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,1) , 1 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,2) , 1 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,3) , 0 );

             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,0) , 2 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,1) , 1 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,2) , 0 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,3) , 1 );









             efm.cvHammingSamplingMatchTemplate(im2,result);
             TEST_ASSERT_EQUAL_EXACT( result->rows , 3 );
             TEST_ASSERT_EQUAL_EXACT( result->cols , 4 );

             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,0) , 0 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,1) , 1 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,2) , 2 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,3) , 2 );

             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,0) , 1 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,1) , 1 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,2) , 0 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,3) , 2 );

             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,0) , 0 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,1) , 2 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,2) , 1 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,3) , 0 );

         }
         
         
	} // end test1

	/**
	*
	*/
	void Test_SeqFastMatcher::test2() {
        IplImage* im1= cvLoadImage("Test_input/im1.bmp", 0);
		 TEST_ASSERT_MSG(im1,"im1 not load");
		 TEST_ASSERT_EQUAL( im1->width , 6);
		 TEST_ASSERT_EQUAL( im1->height , 4);
         int imageWidthStep= im1->widthStep;
         
         IplImage* im2= cvLoadImage("Test_input/im2.bmp", 0);
		 TEST_ASSERT_MSG(im2,"im2 not load");
		 TEST_ASSERT_EQUAL( im2->width , 6);
		 TEST_ASSERT_EQUAL( im2->height , 4);

         IplImage* p1= cvLoadImage("Test_input/p1.bmp", 0);
		 TEST_ASSERT_MSG(p1,"p1 not load");

         CvMat* result= cvCreateMat(
             im1->height - p1->height + 1,
             im1->width  - p1->width  + 1,
             CV_32SC1);
         
         {
             std::vector<Point> maskLocations;
             for (int x= 0; x<3; ++x) {
                 for (int y= 0; y<2; ++y) {
                     maskLocations.push_back(Point(x,y));
                 }
             }
             
             typedef DiffAbs_IsSimilar_uchar<0> T0;
             SeqFastMatcher<T0> efm(
                 imageWidthStep,
                 p1,
                 maskLocations,
                 0.0,
                 100.0);

             
             efm.cvHammingSamplingMatchTemplate(im1,result);
             TEST_ASSERT_EQUAL_EXACT( result->rows , 3 );
             TEST_ASSERT_EQUAL_EXACT( result->cols , 4 );

             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,0) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,1) , 5 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,2) , 0 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,3) , 6 );

             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,0) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,1) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,2) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,3) , 6 );

             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,0) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,1) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,2) , 5 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,3) , 6 );









             efm.cvHammingSamplingMatchTemplate(im2,result);
             TEST_ASSERT_EQUAL_EXACT( result->rows , 3 );
             TEST_ASSERT_EQUAL_EXACT( result->cols , 4 );

             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,0) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,1) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,2) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,3) , 6 );

             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,0) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,1) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,2) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,3) , 6 );

             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,0) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,1) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,2) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,3) , 6 );

         }
         
         
         
         
         
         
         
         
         
         
         
         {
             std::vector<Point> maskLocations;
             for (int x= 0; x<3; ++x) {
                 for (int y= 0; y<2; ++y) {
                     maskLocations.push_back(Point(x,y));
                 }
             }
             
             typedef DiffAbs_IsSimilar_uchar<2> T2;
             SeqFastMatcher<T2> efm(
                 imageWidthStep,
                 p1,
                 maskLocations,
                 0.0,
                 100.0);

             
             efm.cvHammingSamplingMatchTemplate(im1,result);
             TEST_ASSERT_EQUAL_EXACT( result->rows , 3 );
             TEST_ASSERT_EQUAL_EXACT( result->cols , 4 );

             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,0) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,1) , 4 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,2) , 0 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,3) , 5 );

             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,0) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,1) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,2) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,3) , 6 );

             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,0) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,1) , 5 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,2) , 0 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,3) , 6 );









             efm.cvHammingSamplingMatchTemplate(im2,result);
             TEST_ASSERT_EQUAL_EXACT( result->rows , 3 );
             TEST_ASSERT_EQUAL_EXACT( result->cols , 4 );

             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,0) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,1) , 5 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,2) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,3) , 6 );

             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,0) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,1) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,2) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,3) , 6 );

             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,0) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,1) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,2) , 6 );
             TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,3) , 6 );

         }
	} // end test2
    
    
    
    void Test_SeqFastMatcher::test3() {
        IplImage* im1= cvLoadImage("Test_input/im1.bmp", 0);
        TEST_ASSERT_MSG(im1,"im1 not load");
        TEST_ASSERT_EQUAL( im1->width , 6);
        TEST_ASSERT_EQUAL( im1->height , 4);
        int imageWidthStep= im1->widthStep;
        
        IplImage* pattern= cvLoadImage("Test_input/p1.bmp", 0);
        TEST_ASSERT_MSG(pattern,"pattern not load");
        
        CvMat* result= cvCreateMat(
            im1->height - pattern->height + 1,
            im1->width  - pattern->width + 1,
            CV_32SC1);
        
        {
        	std::vector< pair<Point,Point> > maskLocations;
            Point p1(2,1); Point p2(0,0); maskLocations.push_back( make_pair(p1,p2) );
            Point p12(1,0); Point p22(1,1); maskLocations.push_back( make_pair(p12,p22) );
            
            typedef PairsGt_IsSimilar_uchar<0> pgt;
            
            
            SeqFastMatcher<pgt> efm(
                imageWidthStep,
                pattern,
                maskLocations,
                0.0,
                100);
            
              
            efm.cvHammingSamplingMatchTemplate(im1,result);
            
            TEST_ASSERT_EQUAL_EXACT( result->rows , 3 );
            TEST_ASSERT_EQUAL_EXACT( result->cols , 4 );
            
            TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,0) , 2 );
            TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,1) , 1 );
            TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,2) , 0 );
            TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,3) , 1 );
            
            TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,0) , 1 );
            TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,1) , 0 );
            TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,2) , 1 );
            TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,3) , 1 );

            TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,0) , 1 );
            TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,1) , 1 );
            TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,2) , 0 );
            TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,3) , 1 );
            
        }
    } // end test3
    
    
    
    void Test_SeqFastMatcher::test4() {
        
        IplImage* im1= cvLoadImage("Test_input/im1.bmp", 0);
        TEST_ASSERT_MSG(im1,"im1 not load");
        TEST_ASSERT_EQUAL( im1->width , 6);
        TEST_ASSERT_EQUAL( im1->height , 4);
        int imageWidthStep= im1->widthStep;
        
        IplImage* im2= cvLoadImage("Test_input/im2.bmp", 0);
        TEST_ASSERT_MSG(im2,"im2 not load");
        TEST_ASSERT_EQUAL( im2->width , 6);
        TEST_ASSERT_EQUAL( im2->height , 4);
        
        IplImage* p1= cvLoadImage("Test_input/p1.bmp", 0);
        TEST_ASSERT_MSG(p1,"p1 not load");
        
        CvMat* result= cvCreateMat(
            im1->height - p1->height + 1,
            im1->width  - p1->width  + 1,
            CV_32SC1);

        
        { 
            std::vector<Point> maskLocations;
            maskLocations.push_back(Point(0,0));
            maskLocations.push_back(Point(1,1));
            maskLocations.push_back(Point(2,0));
            
            typedef DiffAbs_IsSimilar_uchar<100> T100;
            SeqFastMatcher<T100> efm(
                imageWidthStep,
                p1,
                maskLocations,
                0.0,
                50.0);
            
            efm.cvHammingSamplingMatchTemplate(im1,result);
            TEST_ASSERT_EQUAL_EXACT( result->rows , 3 );
            TEST_ASSERT_EQUAL_EXACT( result->cols , 4 );
            
            TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,0) , 2+1 );
            TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,1) , 1 );
            TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,2) , 0 );
            TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,0,3) , 1 );
            
            TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,0) , 0 );
            TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,1) , 1 );
            TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,2) , 1 );
            TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,1,3) , 0 );
            
            TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,0) , 2+1 );
            TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,1) , 1 );
            TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,2) , 0 );
            TEST_ASSERT_EQUAL_EXACT( CV_MAT_ELEM(*result,int,2,3) , 1 );
        } 
    }
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
