#ifndef RESULTSIMAGEMAKER_H_
#define RESULTSIMAGEMAKER_H_

#include <opencv/cv.h>
#include <vector>
#include "/cs/phd/ofirpele/vis/hs/src/isSimilar/Point.h"

class ResultsImageMaker {

private:
    IplImage* _borderMask;
    int _thick;

    // paints the bordered mask on the (xtl,ytl) top left 
    // corner of the image. Notice: only white pixels are painted!!!
    void paintBorderMask(IplImage* im, int xtl, int ytl) {
    
        for (int x=0; x<_borderMask->width; ++x) {
        	for (int y=0; y<_borderMask->height; ++y) {
                
                int xOnIm= xtl+x;
                int yOnIm= ytl+y;
                if ((xOnIm>=0)&&(xOnIm<im->width)&&
                    (yOnIm>=0)&&(yOnIm<im->height)) {
                    
                    if (CV_IMAGE_ELEM(_borderMask,uchar,y,x)==255) {
                        CV_IMAGE_ELEM(im,uchar,yOnIm,xOnIm)= 0;
                    }
                    
                }
                
                
            } // end y
        } // end x
    } // end paintBorderMask
    
public:

        
    ResultsImageMaker(const IplImage* mask, int thick) :_thick(thick) {
        //thick=20;
        // creates newMask with black border
        CvSize sz= cvSize(
            mask->width+thick*2,
            mask->height+thick*2);
        IplImage* newMask= cvCreateImage(sz,mask->depth,1);
        cvSetZero(newMask);
        for (int y= 0; y<mask->height; ++y )     {
            for (int x= 0; x<mask->width; ++x){
                CV_IMAGE_ELEM(newMask,uchar,y+thick,x+thick)=
                    CV_IMAGE_ELEM(mask,uchar,y,x);
            }
        }
                
        // takes border
        _borderMask= cvCreateImage(sz,mask->depth,1);
        for (int y= 0; y<newMask->height; ++y )     {
            for (int x= 0; x<newMask->width; ++x){
                
                uchar pixel= CV_IMAGE_ELEM(newMask,uchar,y,x);
                CV_IMAGE_ELEM(_borderMask,uchar,y,x)= 0;
                if (pixel==0) {
                    for (int yp=-1; yp<=+1; ++yp) {
                        for (int xp=-1; xp<=+1; ++xp) {
                            if ((x+xp>=0)&&(x+xp<newMask->width)&&
                                (y+yp>=0)&&(y+yp<newMask->height)) {
                                if (CV_IMAGE_ELEM(newMask,uchar,y+yp,x+xp)!=0) {
                                    CV_IMAGE_ELEM(_borderMask,uchar,y,x)= 255;
                                }
                            }
                        }
                    }
                }
                
            } // x
        } // y
        
        
        cvDilate(_borderMask,_borderMask,NULL,thick-1);
        
//        char* win_name= "tmp";
//        cvNamedWindow(win_name, CV_WINDOW_AUTOSIZE);
//        cvMoveWindow(win_name, 300, 200);
//        cvShowImage(win_name, _borderMask);
//        cvWaitKey(0);
//        cvDestroyAllWindows();
//        
          
        cvReleaseImage(&newMask);
               
    } // end Ctor
    
    IplImage* makeResIm(const IplImage* im,std::vector<Point>& similarPoints) {
        
        typedef std::vector<Point> T_POINTS_VEC;
        typedef T_POINTS_VEC::const_iterator T_POINTS_VEC_ITERATOR;
        
        IplImage* res=cvCloneImage(im);
        
        for (T_POINTS_VEC_ITERATOR it= similarPoints.begin();
             it!= similarPoints.end(); ++it) {
            
            int xtl= it->x - _thick;
            int ytl= it->y - _thick;
            
            paintBorderMask(res,xtl,ytl);
            
        }
        
        return res;
    } // end makeResIm
    
    
    
    
    
    
    ~ResultsImageMaker() {
        cvReleaseImage(&_borderMask);
    } // end dtor

};
#endif /*RESULTSIMAGEMAKER_H_*/


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
