/**
=====================================================================
* @author Ofir Pele
=====================================================================
*/

/*******************************************************************
 Include files:
********************************************************************/
#include "Test_MakePairsMask.h"

#include <opencv/highgui.h>
#include <runner/MakePairsMask.h>

/*########################################################################
  Open namespace:
  ########################################################################*/
//namespace Tests {
using namespace Tests;

	/*==================== ctor & dtor ==============================*/
	Test_MakePairsMask::Test_MakePairsMask() {

		_funcs.push_back(&test1);
		_names.push_back("test1");
		_funcs.push_back(&test2);
		_names.push_back("test2");
        _funcs.push_back(&test3);
        _names.push_back("test3");
	}// end Ctor
    

	//==============================================================
	/**@name tests functions */

	/**
	*
	*/
	void Test_MakePairsMask::test1() {
		 IplImage* im3= cvLoadImage("Test_input/im3.bmp", 0);
         TEST_ASSERT_MSG(im3,"im3 not load");
         TEST_ASSERT_EQUAL_EXACT( im3->width , 6);
		 TEST_ASSERT_EQUAL_EXACT( im3->height , 5);
		 
		 IplImage* origMask= cvLoadImage("Test_input/im3_mask.bmp", 0);
         TEST_ASSERT_MSG(origMask,"im3_mask not load");
         TEST_ASSERT_EQUAL_EXACT( origMask->width , 6);
		 TEST_ASSERT_EQUAL_EXACT( origMask->height , 5);
         
         IplImage* mask2= cvLoadImage("Test_input/im3_mask2.bmp", 0);
         TEST_ASSERT_MSG(mask2,"im3_mask2 not load");
         TEST_ASSERT_EQUAL_EXACT( mask2->width , 6);
		 TEST_ASSERT_EQUAL_EXACT( mask2->height , 5);
		 
         {std::vector< pair<Point,Point> > pairs;
         MakePairsMask mpm( 
             im3,
             origMask,
             
             99,//int gtNeighbor,
             2,//int maxNeighbor,
             2,//int minNeighbor,
             4,//int windowSize,
             60,//int maxFromWindow,
             
             pairs);
         
         TEST_ASSERT_EQUAL_EXACT( pairs.size() , 26);
                  
         TEST_ASSERT_EQUAL_EXACT( pairs[0].first.x , 0 );
         TEST_ASSERT_EQUAL_EXACT( pairs[0].first.y , 2 );
         TEST_ASSERT_EQUAL_EXACT( pairs[0].second.x , 2 );
         TEST_ASSERT_EQUAL_EXACT( pairs[0].second.y , 0 );
         
         TEST_ASSERT_EQUAL_EXACT( pairs[1].first.x , 0 );
         TEST_ASSERT_EQUAL_EXACT( pairs[1].first.y , 2 );
         TEST_ASSERT_EQUAL_EXACT( pairs[1].second.x , 0 );
         TEST_ASSERT_EQUAL_EXACT( pairs[1].second.y , 0 );
         
         TEST_ASSERT_EQUAL_EXACT( pairs[1].first.x , 0 );
         TEST_ASSERT_EQUAL_EXACT( pairs[1].first.y , 2 );
         TEST_ASSERT_EQUAL_EXACT( pairs[1].second.x , 0 );
         TEST_ASSERT_EQUAL_EXACT( pairs[1].second.y , 0 );
         
         TEST_ASSERT_EQUAL_EXACT( pairs[5].first.x , 1 );
         TEST_ASSERT_EQUAL_EXACT( pairs[5].first.y , 1 );
         TEST_ASSERT_EQUAL_EXACT( pairs[5].second.x , 3 );
         TEST_ASSERT_EQUAL_EXACT( pairs[5].second.y , 0 );
         }
         
         
         {std::vector< pair<Point,Point> > pairs;
         MakePairsMask mpm( 
             im3,
             origMask,
             
             100,//int gtNeighbor,
             2,//int maxNeighbor,
             2,//int minNeighbor,
             4,//int windowSize,
             60,//int maxFromWindow,
             
             pairs);
         
         
         TEST_ASSERT_EQUAL_EXACT( pairs.size() , 24);
         
         }
         
         
         {std::vector< pair<Point,Point> > pairs;
         MakePairsMask mpm( 
             im3,
             origMask,
             
             242,//int gtNeighbor,
             2,//int maxNeighbor,
             2,//int minNeighbor,
             4,//int windowSize,
             60,//int maxFromWindow,
             
             pairs);
         
         
         TEST_ASSERT_EQUAL_EXACT( pairs.size() , 1);
         
         }
         
         
         {std::vector< pair<Point,Point> > pairs;
         MakePairsMask mpm( 
             im3,
             origMask,
             
             0,//int gtNeighbor,
             2,//int maxNeighbor,
             2,//int minNeighbor,
             4,//int windowSize,
             1,//int maxFromWindow,
             
             pairs);
         
         
         TEST_ASSERT_EQUAL_EXACT( pairs.size() , 4);
         
         }
         
         {std::vector< pair<Point,Point> > pairs;
         MakePairsMask mpm( 
             im3,
             origMask,
             
             99,//int gtNeighbor,
             2,//int maxNeighbor,
             2,//int minNeighbor,
             4,//int windowSize,
             1,//int maxFromWindow,
             
             pairs);
         
         
         TEST_ASSERT_EQUAL_EXACT( pairs.size() , 3);
         
         }
         
         {std::vector< pair<Point,Point> > pairs;
         MakePairsMask mpm( 
             im3,
             origMask,
             
             100,//int gtNeighbor,
             2,//int maxNeighbor,
             2,//int minNeighbor,
             4,//int windowSize,
             1,//int maxFromWindow,
             
             pairs);
         
         
         TEST_ASSERT_EQUAL_EXACT( pairs.size() , 2);
         
         }
                  
         {std::vector< pair<Point,Point> > pairs;
         MakePairsMask mpm( 
             im3,
             mask2,
             
             99,//int gtNeighbor,
             2,//int maxNeighbor,
             2,//int minNeighbor,
             4,//int windowSize,
             60,//int maxFromWindow,
             
             pairs);
         
         TEST_ASSERT_EQUAL_EXACT( pairs.size() , 26-8-1-2);
                     
     }
         
//         for (unsigned int i=0; i<pairs.size(); ++i) {
//             cout << "("<<pairs[i].first.x << "," << pairs[i].first.y<<")       >         ";
//             cout << "("<<pairs[i].second.x << "," << pairs[i].second.y<<")        ";
//             cout << computeDiff(pairs[i],im3) << endl;
//         }
	} // end test1

	/**
	* Test LU
	*/
	void Test_MakePairsMask::test2() {
		 
         IplImage* im1= cvLoadImage("Test_input/LUim1.png", 0);
         TEST_ASSERT_MSG(im1,"im1 not load");
         TEST_ASSERT_EQUAL_EXACT( im1->width , 4);
         TEST_ASSERT_EQUAL_EXACT( im1->height , 4);
         
         IplImage* im2= cvLoadImage("Test_input/LUim2.png", 0);
         TEST_ASSERT_MSG(im2,"im2 not load");
         TEST_ASSERT_EQUAL_EXACT( im2->width , 4);
         TEST_ASSERT_EQUAL_EXACT( im2->height , 4);
         
         IplImage* im3= cvLoadImage("Test_input/LUim3.png", 0);
         TEST_ASSERT_MSG(im3,"im3 not load");
         TEST_ASSERT_EQUAL_EXACT( im3->width , 4);
         TEST_ASSERT_EQUAL_EXACT( im3->height , 4);
         
         IplImage* im4= cvLoadImage("Test_input/LUim4.png", 0);
         TEST_ASSERT_MSG(im4,"im4 not load");
         TEST_ASSERT_EQUAL_EXACT( im4->width , 9);
         TEST_ASSERT_EQUAL_EXACT( im4->height , 10);
         
         IplImage* im4_mask= cvLoadImage("Test_input/LUim4_mask.png", 0);
         TEST_ASSERT_MSG(im4_mask,"im4_mask not load");
         TEST_ASSERT_EQUAL_EXACT( im4_mask->width , 9);
         TEST_ASSERT_EQUAL_EXACT( im4_mask->height , 10);
         
         IplImage* im1_mask= cvLoadImage("Test_input/LUim1_mask.png", 0);
         TEST_ASSERT_MSG(im1_mask,"im1_mask not load");
         TEST_ASSERT_EQUAL_EXACT( im1_mask->width , 4);
         TEST_ASSERT_EQUAL_EXACT( im1_mask->height , 4);
         
         {
         std::vector< std::pair<Point,Point> > pairs;
         std::vector< std::pair<Point,Point> > LUpairs;
         int minLUvalInPairs;
         
         MakePairsMask mpm
        (im1,
         im1_mask,
         
         4,//gtNeighbor
         2,//maxNeighbor
         1,//minNeighbor
         1,//windowSize
         100,//maxFromWindow
                      
         pairs,
         
         0,//gtNeighborLU
         1,//minNumOfLuPixels
         LUpairs,
         minLUvalInPairs);
          
         TEST_ASSERT_EQUAL_EXACT( pairs.size() , 5);
         TEST_ASSERT_EQUAL_EXACT( LUpairs.size() , 4);

}
    
    
    
         
{
         std::vector< std::pair<Point,Point> > pairs;
         std::vector< std::pair<Point,Point> > LUpairs;
         int minLUvalInPairs;
         
         MakePairsMask mpm
        (im2,
         im1_mask,
         
         4,//gtNeighbor
         2,//maxNeighbor
         1,//minNeighbor
         1,//windowSize
         100,//maxFromWindow
                      
         pairs,
         
         0,//gtNeighborLU
         1,//minNumOfLuPixels
         LUpairs,
         minLUvalInPairs);
          
         TEST_ASSERT_EQUAL_EXACT( pairs.size() , 5);
         TEST_ASSERT_EQUAL_EXACT( LUpairs.size() , 5);
         

}
    {
         std::vector< std::pair<Point,Point> > pairs;
         std::vector< std::pair<Point,Point> > LUpairs;
         int minLUvalInPairs;
         
         MakePairsMask mpm
        (im3,
         im1_mask,
         
         4,//gtNeighbor
         2,//maxNeighbor
         1,//minNeighbor
         1,//windowSize
         100,//maxFromWindow
                      
         pairs,
         
         0,//gtNeighborLU
         1,//minNumOfLuPixels
         LUpairs,
         minLUvalInPairs);
          
         TEST_ASSERT_EQUAL_EXACT( pairs.size() , 1);
         TEST_ASSERT_EQUAL_EXACT( LUpairs.size() , 1);
     }
 
 
    {
         std::vector< std::pair<Point,Point> > pairs;
         std::vector< std::pair<Point,Point> > LUpairs;
         int minLUvalInPairs;
         
         MakePairsMask mpm
        (im4,
         im4_mask,
         
         4,//gtNeighbor
         3,//maxNeighbor
         2,//minNeighbor
         1,//windowSize
         100,//maxFromWindow
                      
         pairs,
         
         0,//gtNeighborLU
         1,//minNumOfLuPixels
         LUpairs,
         minLUvalInPairs);
          
         TEST_ASSERT_EQUAL_EXACT( pairs.size() , 2);
         TEST_ASSERT_EQUAL_EXACT( LUpairs.size() , 1);
         TEST_ASSERT_EQUAL_EXACT(minLUvalInPairs , 2);
         
//         for (int i= 0; i<pairs.size(); ++i) {
//             cout << "(" << pairs[i].first.y+1 << "," << pairs[i].first.x+1 << ")\t";
//             cout << "(" << pairs[i].second.y+1 << "," << pairs[i].second.x+1 << ")"<<endl;
//         }
//         cout << "------------" << endl;
//         for (int i= 0; i<LUpairs.size(); ++i) {
//             cout << "(" << LUpairs[i].first.y+1 << "," << LUpairs[i].first.x+1 << ")\t";
//             cout << "(" << LUpairs[i].second.y+1 << "," << LUpairs[i].second.x+1 << ")"<<endl;
//         }
    }
    
    {
         std::vector< std::pair<Point,Point> > pairs;
         std::vector< std::pair<Point,Point> > LUpairs;
         int minLUvalInPairs;
         
         MakePairsMask mpm
        (im4,
         im4_mask,
         
         4,//gtNeighbor
         3,//maxNeighbor
         2,//minNeighbor
         1,//windowSize
         100,//maxFromWindow
                      
         pairs,
         
         0,//gtNeighborLU
         2,//minNumOfLuPixels
         LUpairs,
         minLUvalInPairs);
          
         TEST_ASSERT_EQUAL_EXACT( pairs.size() , 2);
         TEST_ASSERT_EQUAL_EXACT( LUpairs.size() , 2);
         TEST_ASSERT_EQUAL_EXACT(minLUvalInPairs , 1);
         
//         for (int i= 0; i<pairs.size(); ++i) {
//             cout << "(" << pairs[i].first.y+1 << "," << pairs[i].first.x+1 << ")\t";
//             cout << "(" << pairs[i].second.y+1 << "," << pairs[i].second.x+1 << ")"<<endl;
//         }
//         cout << "------------" << endl;
//         for (int i= 0; i<LUpairs.size(); ++i) {
//             cout << "(" << LUpairs[i].first.y+1 << "," << LUpairs[i].first.x+1 << ")\t";
//             cout << "(" << LUpairs[i].second.y+1 << "," << LUpairs[i].second.x+1 << ")"<<endl;
//         }
    }
                         
	} // end test2

    /**
     * Test LUXY
     */
    void Test_MakePairsMask::test3() {
         {
         IplImage* im1= cvLoadImage("Test_input/LUXYIm1.png", 0);
         TEST_ASSERT_MSG(im1,"im1 not load");
         TEST_ASSERT_EQUAL_EXACT( im1->width , 8);
         TEST_ASSERT_EQUAL_EXACT( im1->height , 7);
         
         IplImage* im1_mask= cvLoadImage("Test_input/LUXYIm1_mask.png", 0);
         TEST_ASSERT_MSG(im1_mask,"im1 not load");
         TEST_ASSERT_EQUAL_EXACT( im1_mask->width , 8);
         TEST_ASSERT_EQUAL_EXACT( im1_mask->height , 7);
         
         std::vector< std::pair<Point,Point> > pairs;
         std::vector< std::pair<Point,Point> > LUpairs;
         int minLUvalInPairs;
         
         MakePairsMask mpm
        (im1,
         im1_mask,
         50, // gtNeighbor
         2,
         0,
         1,
         12000,
         pairs,
         50,
         1, //int minNumOfLuPixels,
         LUpairs,
         minLUvalInPairs);
                  
         std::vector< MakePairsMask::LURectangle > LUR_vec;
         mpm.fillLURVec(6,5, 4,3, 50, LUR_vec);
         
         TEST_ASSERT_EQUAL_EXACT( LUR_vec.size() , 2 );
         TEST_ASSERT_EQUAL_EXACT( LUR_vec[0]._LUY , 3 );
         TEST_ASSERT_EQUAL_EXACT( LUR_vec[0]._LUX , 1 );
         TEST_ASSERT_EQUAL_EXACT( LUR_vec[1]._LUY , 1 );
         TEST_ASSERT_EQUAL_EXACT( LUR_vec[1]._LUX , 3 );
         }
         
         {
         IplImage* im2= cvLoadImage("Test_input/LUXYIm2.png", 0);
         TEST_ASSERT_MSG(im2,"im2 not load");
         TEST_ASSERT_EQUAL_EXACT( im2->width , 16);
         TEST_ASSERT_EQUAL_EXACT( im2->height , 13);
         
         IplImage* im2_mask= cvLoadImage("Test_input/LUXYIm2_mask.png", 0);
         TEST_ASSERT_MSG(im2_mask,"im1 not load");
         TEST_ASSERT_EQUAL_EXACT( im2_mask->width , 16);
         TEST_ASSERT_EQUAL_EXACT( im2_mask->height , 13);
         
         std::vector< std::pair<Point,Point> > pairs;
         std::vector< std::pair<Point,Point> > LUpairs;
         int minLUvalInPairs;
         
         MakePairsMask mpm
        (im2,
         im2_mask,
         50, // gtNeighbor
         2,
         0,
         1,
         12000,
         pairs,
         50,
         1, //int minNumOfLuPixels,
         LUpairs,
         minLUvalInPairs);
                  
         std::vector< MakePairsMask::LURectangle > LUR_vec;
         mpm.fillLURVec(14,11, 12,9, 50, LUR_vec);
         
         TEST_ASSERT_EQUAL_EXACT( LUR_vec.size() , 2 );
         TEST_ASSERT_EQUAL_EXACT( LUR_vec[0]._LUY , 3 );
         TEST_ASSERT_EQUAL_EXACT( LUR_vec[0]._LUX , 1 );
         TEST_ASSERT_EQUAL_EXACT( LUR_vec[1]._LUY , 1 );
         TEST_ASSERT_EQUAL_EXACT( LUR_vec[1]._LUX , 4 );
         }
         
         {
         IplImage* im3= cvLoadImage("Test_input/LUXYIm3.png", 0);
         TEST_ASSERT_MSG(im3,"im3 not load");
         TEST_ASSERT_EQUAL_EXACT( im3->width , 16);
         TEST_ASSERT_EQUAL_EXACT( im3->height , 13);
         
         IplImage* im2_mask= cvLoadImage("Test_input/LUXYIm2_mask.png", 0);
         TEST_ASSERT_MSG(im2_mask,"im1 not load");
         TEST_ASSERT_EQUAL_EXACT( im2_mask->width , 16);
         TEST_ASSERT_EQUAL_EXACT( im2_mask->height , 13);
         
         std::vector< std::pair<Point,Point> > pairs;
         std::vector< std::pair<Point,Point> > LUpairs;
         int minLUvalInPairs;
         
         MakePairsMask mpm
        (im3,
         im2_mask,
         50, // gtNeighbor
         2,
         0,
         1,
         12000,
         pairs,
         50,
         1, //int minNumOfLuPixels,
         LUpairs,
         minLUvalInPairs);
                  
         std::vector< MakePairsMask::LURectangle > LUR_vec;
         mpm.fillLURVec(14,11, 11,8, 50, LUR_vec);
         
         TEST_ASSERT_EQUAL_EXACT( LUR_vec.size() , 3 );
         TEST_ASSERT_EQUAL_EXACT( LUR_vec[0]._LUY , 3 );
         TEST_ASSERT_EQUAL_EXACT( LUR_vec[0]._LUX , 1 );
         TEST_ASSERT_EQUAL_EXACT( LUR_vec[1]._LUY , 2 );
         TEST_ASSERT_EQUAL_EXACT( LUR_vec[1]._LUX , 2 );
         TEST_ASSERT_EQUAL_EXACT( LUR_vec[2]._LUY , 1 );
         TEST_ASSERT_EQUAL_EXACT( LUR_vec[2]._LUX , 4 );
         }
         
         {
         IplImage* im4= cvLoadImage("Test_input/LUXYIm4.png", 0);
         TEST_ASSERT_MSG(im4,"im4 not load");
         TEST_ASSERT_EQUAL_EXACT( im4->width , 5);
         TEST_ASSERT_EQUAL_EXACT( im4->height , 5);
         
         IplImage* im4_mask= cvLoadImage("Test_input/LUXYIm4_mask.png", 0);
         TEST_ASSERT_MSG(im4_mask,"im4_mask not load");
         TEST_ASSERT_EQUAL_EXACT( im4_mask->width , 5);
         TEST_ASSERT_EQUAL_EXACT( im4_mask->height , 5);
         
         std::vector< std::pair<Point,Point> > pairs;
         std::vector< std::pair<Point,Point> > LUpairs;
         int minLUvalInPairs;
         
         MakePairsMask mpm
        (im4,
         im4,
         50, // gtNeighbor
         2,
         0,
         1,
         12000,
         pairs,
         50,
         1, //int minNumOfLuPixels,
         LUpairs,
         minLUvalInPairs);
                  
         std::vector< MakePairsMask::LURectangle > LUR_vec;
         mpm.fillLURVec(4,4, 2,2, 50, LUR_vec);
         
         TEST_ASSERT_EQUAL_EXACT( LUR_vec.size() , 1 );
         TEST_ASSERT_EQUAL_EXACT( LUR_vec[0]._LUY , 0 );
         TEST_ASSERT_EQUAL_EXACT( LUR_vec[0]._LUX , 0 );
         
         CV_IMAGE_ELEM(im4,uchar,3,4)= 60;
         LUR_vec.clear();
         mpm.fillLURVec(4,4, 2,2, 50, LUR_vec);
         TEST_ASSERT_EQUAL_EXACT( LUR_vec.size() , 1 );
         TEST_ASSERT_EQUAL_EXACT( LUR_vec[0]._LUY , 1 );
         TEST_ASSERT_EQUAL_EXACT( LUR_vec[0]._LUX , 0 );
         
         CV_IMAGE_ELEM(im4,uchar,4,3)= 60;
         LUR_vec.clear();
         mpm.fillLURVec(4,4, 2,2, 50, LUR_vec);
         TEST_ASSERT_EQUAL_EXACT( LUR_vec.size() , 2 );
         TEST_ASSERT_EQUAL_EXACT( LUR_vec[0]._LUY , 1 );
         TEST_ASSERT_EQUAL_EXACT( LUR_vec[0]._LUX , 0 );
         TEST_ASSERT_EQUAL_EXACT( LUR_vec[1]._LUY , 0 );
         TEST_ASSERT_EQUAL_EXACT( LUR_vec[1]._LUX , 1 );
         
         CV_IMAGE_ELEM(im4,uchar,3,3)= 60;
         LUR_vec.clear();
         mpm.fillLURVec(4,4, 2,2, 50, LUR_vec);
         TEST_ASSERT_EQUAL_EXACT( LUR_vec.size() , 1 );
         TEST_ASSERT_EQUAL_EXACT( LUR_vec[0]._LUY , 1 );
         TEST_ASSERT_EQUAL_EXACT( LUR_vec[0]._LUX , 1 );
         
         
         
         }
         
    } // end test3
    
//@}
// ==============================================================

//}; // close namespace
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
