#ifndef FILLLUMASKLOCATIONSVEC_H_
#define FILLLUMASKLOCATIONSVEC_H_

#include <isSimilar/Point.h>
#include <vector>
#include <stdlib.h>

class fillLUmaskLocationsVec { 

public:
    
    
    
    static void fill(std::vector<Point>& LUmaskLocationsVec,
                     int& LUX,
                     int& LUY,
                     
                     const std::vector<Point>& maskLocationsVec,
                     
                     const IplImage* pattern,
                     const IplImage* mask,
                     
                     int threshLU,
                     int minNumOfLUPixels) {
        
        int minLUvalInPixels= 0; // for init
        if (maskLocationsVec.size()==0) return;
        
        //--------------------------------------------------
        // computes LU for each pixel and max LU
        //--------------------------------------------------
        std::vector<int> LUPixelsVals( maskLocationsVec.size() , 0 );
        int maxLU= 0;
        for (unsigned int i= 0; i<maskLocationsVec.size(); ++i) {
        
            using std::max;
            using std::min;
            
            int x= maskLocationsVec[i].x;
            int y= maskLocationsVec[i].y;
            
            int minXY= min(x,y);
        
            int currTryLU= 1;   
            bool LUNotOk= false;
            while (currTryLU<=minXY) {
            
            // row strip of LU i.e the xxx in:
            // xxx
            // |
            // | o
            int yn= y-currTryLU; 
            int xn= x-currTryLU; // start
            while (xn<=x) {
                if (!goodLUPixel(x, y, xn, yn, threshLU,pattern,mask)) {
                    LUNotOk= true;
                    break;
                } 
                ++xn;
            }
            if (LUNotOk) break;
            
            // coloumn strip of LU i.e the xxx in:
            // ---
            // x
            // x o
            yn= y-currTryLU+1; // start
            xn= x-currTryLU; 
            while (yn<=y) {
                if (!goodLUPixel(x, y, xn, yn, threshLU,pattern,mask)) {
                    LUNotOk= true;
                    break;
                } 
                ++yn;
            }
            if (LUNotOk) break;
            
            LUPixelsVals[i]= currTryLU;
            if (maxLU<currTryLU) maxLU= currTryLU;
            ++currTryLU;
            
        } // end currTryLU
        
        
    } // for i
    //--------------------------------------------------
    
    //--------------------------------------------------
    // Find minLUvalInPixels that we return and fill up
    // LUPixels
    //--------------------------------------------------
    
    // count how many of each LU
    std::vector<int> numOfPixelsWithLU(maxLU+1,0);
    for (unsigned int i= 0; i<LUPixelsVals.size(); ++i) {
        ++numOfPixelsWithLU[ LUPixelsVals[i] ];
    }
    // do reverse cumsum (Pixel that have LU1>LU2 have also LU2...
    for (int i= numOfPixelsWithLU.size()-2; i>=0; --i) {
        numOfPixelsWithLU[i]+= numOfPixelsWithLU[i+1];
    }
    assert(numOfPixelsWithLU[0]==(int)maskLocationsVec.size());
    
    // find minLUvalInPixels
    minLUvalInPixels= numOfPixelsWithLU.size()-1;
    while (numOfPixelsWithLU[minLUvalInPixels]<minNumOfLUPixels&&minLUvalInPixels>0) {
        --minLUvalInPixels;
    }
    
    // fill LUPixels
    for (unsigned int i= 0; i<maskLocationsVec.size(); ++i) {
        if (LUPixelsVals[i]>=minLUvalInPixels) {
            LUmaskLocationsVec.push_back( maskLocationsVec[i] ); 
        }
    }
    
    //std::cout << "maskLocationsVec.size() == " << maskLocationsVec.size() << std::endl;
    //std::cout << "LU used == " << minLUvalInPixels << std::endl;
    //std::cout << "LUmaskLocationsVec.size() == " << LUmaskLocationsVec.size() << std::endl;
     
    //assert( (int)LUPixels.size()==numOfPixelsWithLU[minLUvalInPixels] );
    
    //--------------------------------------------------
        
    LUX=minLUvalInPixels;
    LUY=minLUvalInPixels;    
    } // end fill

private:
    
  
    
    static bool goodLUPixel(int x,int y,int xn,int yn,int threshLU,const IplImage* pattern,const IplImage* mask) {
        
        if (!CV_IMAGE_ELEM(mask,uchar,y,x)) return false;
        if (!CV_IMAGE_ELEM(mask,uchar,yn,xn)) return false;
        
        int absDiff= abs((int)(CV_IMAGE_ELEM(pattern,uchar, y , x)) - 
                         (int)(CV_IMAGE_ELEM(pattern,uchar, yn, xn)));
        return (absDiff<=threshLU);
    } // goodPixel
};
#endif /*FILLLUMASKLOCATIONSVEC_H_*/


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
