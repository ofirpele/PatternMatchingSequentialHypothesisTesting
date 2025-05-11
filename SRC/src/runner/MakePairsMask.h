#ifndef MAKEPAIRSMASK_H_
#define MAKEPAIRSMASK_H_

#include <opencv/highgui.h> // TODO: remove
#include <opencv/cv.h>
 
#include <algorithm>

#include <isSimilar/Point.h>

#include <runner/PairsPointsComparator.h>

#include <iterator>
#include <vector>
#include <iostream>



/// Makes mask of pairs of Points that are neighbors and the first 
/// is greater in a given number than the second in the pattern.
class MakePairsMask {
   

   
public:
    
    
    friend class Test_MakePairsMask;
    
    /// Makes mask of pairs of Points that are neighbors and the first 
    /// is greater in gtNeighbor than the second in the pattern.
    /// \param pattern the pattern that the pairs are checked in.
    /// \param origMask all pairs of pixels must be in this mask.
    /// \param gtNeighbor In order for a pixel (x',y') to be greater than 
    ///        it's neighbor (x,y) this condition should hold: 
    ///        g(x,y) > g(x',y')+gtNeighbor.
    /// \param maxNeighbor Maximum distance of a neighbor. i.e: (x,y) 
    ///        can be a neighbor of (x',y') if 
    //         max(|x-x'|,|y-y'|) <= maxNeighbor.
    /// \param minNeighbor Minimum distance of a neighbor. i.e: (x,y) 
    ///        can be a neighbor of (x',y') if 
    ///        max(|x-x'|,|y-y'|) >= minNeighbor.
    /// \param windowSize The pattern is divided into windows of windowSize. 
    ///        Should be >0
    /// \param maxFromWindow From each window a maximum of maxFromWindow 
    ///        pixels is taken.
    /// \out pairs This vector will be filled with the pairs. First, it is emptied.
    MakePairsMask
        (IplImage* pattern,
         IplImage* origMask,
        
         int gtNeighbor,
         int maxNeighbor,
         int minNeighbor,
         int windowSize,
         int maxFromWindow,
         
         std::vector< std::pair<Point,Point> >& pairs) : 
        _pattern(pattern),
        _origMask(origMask),
        
        _gt(gtNeighbor),
        _maxN(maxNeighbor),
        _maxNPow2(maxNeighbor*maxNeighbor),
        _minN(minNeighbor),
        _minNPow2(minNeighbor*minNeighbor),
        _ws(windowSize),
        _mfw(maxFromWindow) {
        
        assert(windowSize>0);    
        clearAndfillAllPairs(pairs);
            
    } // end ctor   
        
    /// Same as MakePairsMask with one diffrence. 
    /// Gets also another vector in which it fills all pairs with 
    /// LU value greater than the returned LU value, which is the
    /// highest LU value that covers at least minNumOfLuPixels.
    ///
    /// \param gtNeighborLU - the LU strip requirement of greatness from neighbors
    /// \param minNumOfLuPixels see above
    /// \out LUpairs This vector will be filled with pairs that have 
    /// LU value greater than the returned LU value - minLUvalInPairs
    /// \out minLUvalInPairs
    MakePairsMask
        (IplImage* pattern,
         IplImage* origMask,
         
         int gtNeighbor,
         int maxNeighbor,
         int minNeighbor,
         int windowSize,
         int maxFromWindow,
         
         std::vector< std::pair<Point,Point> >& pairs,
         
         int gtNeighborLU,
         int minNumOfLuPixels,
         std::vector< std::pair<Point,Point> >& LUpairs,
         int& minLUvalInPairs)
          
        : _pattern(pattern),
        _origMask(origMask),
        
        _gt(gtNeighbor),
        _maxN(maxNeighbor),
        _maxNPow2(maxNeighbor*maxNeighbor),
        _minN(minNeighbor),
        _minNPow2(minNeighbor*minNeighbor),
        _ws(windowSize),
        _mfw(maxFromWindow) {
        
        
        assert(windowSize>0);
        assert(_pattern->width==_origMask->width);
        assert(_pattern->height==_origMask->height);
        
        clearAndfillAllPairs(pairs);
        
        //int LUX, LUY;
        //updateImSize(2048,1536);
        //clearAndfillLURPairs(pairs, gtNeighborLU, minNumOfLuPixels, LUpairs, LUX, LUY);               
        //std::cout << "LUX==" << LUX << " LUY==" << LUY << std::endl;     
                
        clearAndfillLUPairs (pairs, gtNeighborLU, minNumOfLuPixels, LUpairs, minLUvalInPairs);
        //std::cout << "LU==" << minLUvalInPairs << std::endl;
        
        //std::cout << "---" << numWindowsInIm(LUX,LUY) / double(numWindowsInIm(minLUvalInPairs,minLUvalInPairs)) << "---" << std::endl;
         
    } // end ctor
    
    
    /// LUX LUY 
    MakePairsMask
        (IplImage* pattern,
         IplImage* origMask,
         
         int gtNeighbor,
         int maxNeighbor,
         int minNeighbor,
         int windowSize,
         int maxFromWindow,
         
         std::vector< std::pair<Point,Point> >& pairs,
         
         int gtNeighborLU,
         int minNumOfLuPixels,
         int imWidth,
         int imHeight,
         std::vector< std::pair<Point,Point> >& LUpairs,
         int& LUX,
         int& LUY)
          
        : _pattern(pattern),
        _origMask(origMask),
        
        _gt(gtNeighbor),
        _maxN(maxNeighbor),
        _maxNPow2(maxNeighbor*maxNeighbor),
        _minN(minNeighbor),
        _minNPow2(minNeighbor*minNeighbor),
        _ws(windowSize),
        _mfw(maxFromWindow)
        
        {
        
        
        assert(windowSize>0);
        assert(_pattern->width==_origMask->width);
        assert(_pattern->height==_origMask->height);
        
        updateImSize(imWidth,imHeight);
        
        clearAndfillAllPairs(pairs);

        clearAndfillLURPairs(pairs, gtNeighborLU, minNumOfLuPixels, LUpairs, LUX, LUY);               
        
        
        
        
        IplImage* pairs_im = cvCloneImage(_pattern);
        cvSet( pairs_im, cvScalar(0));
        for (unsigned int i= 0; i<pairs.size(); ++i) {
            CV_IMAGE_ELEM(pairs_im,uchar,pairs[i].first.y,pairs[i].first.x)= CV_IMAGE_ELEM(_pattern,uchar,pairs[i].first.y,pairs[i].first.x);
            CV_IMAGE_ELEM(pairs_im,uchar,pairs[i].second.y,pairs[i].second.x)= CV_IMAGE_ELEM(_pattern,uchar,pairs[i].second.y,pairs[i].second.x);
        }
        //cvSaveImage("pairs_im.png",pairs_im);
                       
         
    } // end ctor
        
        
private:
    
    class LURectangle {
    public:
        int _LUX, _LUY;
        LURectangle(int LUX, int LUY) : _LUX(LUX), _LUY(LUY) {} 
    };
    
    void clearAndfillAllPairs(std::vector< std::pair<Point,Point> >& pairs);     
    void clearAndfillLUPairs(const std::vector< std::pair<Point,Point> >& pairs,
                             int gtNeighborLU,
                             int minNumOfLuPixels,
                             std::vector< std::pair<Point,Point> >& LUpairs,
                             int& minLUvalInPairs);
    
    //---------------------------------------------------------------------
    // LUR
    void clearAndfillLURPairs
        (const std::vector< std::pair<Point,Point> >& pairs,
         int gtNeighborLU,
         int minNumOfLuPixels,
         std::vector< std::pair<Point,Point> >& LUpairs,
         int& LUX,
         int& LUY);
    
    void findCharacharesticLUXLUY
        (const std::vector< std::vector< LURectangle > >& pairs_LUR_vecs,
         int minNumOfLuPixels,
         int& LUX, int& LUY);
    
    int countPairs
        (int LUX, int LUY,
         const std::vector< std::vector< LURectangle > >& pairs_LUR_vecs);
    
    void fillLURPairs
        (const std::vector< std::vector< LURectangle > >& pairs_LUR_vecs, 
         int LUX, int LUY, 
         const std::vector< std::pair<Point,Point> >& pairs,
         std::vector< std::pair<Point,Point> >& LUpairs);
    
    int numWindowsInIm(int LUX, int LUY) {
        
        return static_cast<int>
            ( ceil(_numOrigWindowsInRow/(LUX+1)) * ceil(_numOrigWindowsInCol/(LUY+1)) );
        
    } // end numWindowsInIm
        
    void fillLURVec(int x1, int y1, int x2, int y2, int gtLU, 
                    std::vector< LURectangle >& LUR_vec);
    //---------------------------------------------------------------------
    
            
    bool inOrigMask( int x,  int y) {
        return CV_IMAGE_ELEM(_origMask,uchar,y,x); 
    }
    
    // computes the diff in gray values of the pattern between points of p
    int computeDiff(const std::pair<Point,Point>& p) {
        
        return (int)(CV_IMAGE_ELEM(_pattern,uchar, p.first.y, p.first.x)) - 
            (int)(CV_IMAGE_ELEM(_pattern,uchar, p.second.y, p.second.x)); 
    } // end computeDiff
    
    
        
    
    
    
    
    
    // adds to _windowPairs pairs that are neigbors of x,y and ok
    void fillNeighborsPairs( int x, int y);
    
    
    // checks if xn,yn is in mask and if the pair is good. 
    // If true inserts the pair of points into _windowPairs
    void insertPairIfGood(int x,int y,int xn,int yn);
    
    // checks if the given pair difference is high enough
    // i.e: g(x,y) > g(x',y')+gtNeighbor
    bool goodPair(int x,int y,int xn,int yn) {
        return ( computeDiff(std::make_pair(Point(x,y),Point(xn,yn))) > _gt ); 
    } // goodPair
    
    bool goodLUPair(int x,int y,int xn,int yn,int gtLU) {
        return ( computeDiff(std::make_pair(Point(x,y),Point(xn,yn))) > gtLU ); 
    } // goodPair
    
    void updateImSize(int imWidth, int imHeight) {
        _numOrigWindowsInRow= imWidth - _pattern->width + 1;
        _numOrigWindowsInCol= imHeight - _pattern->height + 1;
    }
    //---------------------------------------------------
    
    
    
    //---------------------------------------------------
    // fields
    //---------------------------------------------------
    IplImage* _pattern;
    IplImage* _origMask;
    
    int _gt,_maxN,_maxNPow2,_minN,_minNPow2,_ws,_mfw;
    
    std::vector< std::pair<Point,Point> > _windowPairs;
    
    // important to be double as we don't want integer divide!
    double _numOrigWindowsInRow, _numOrigWindowsInCol;
    //---------------------------------------------------


};

#endif /*MAKEPAIRSMASK_H_*/


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
