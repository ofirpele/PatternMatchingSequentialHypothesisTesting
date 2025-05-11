#include "MakePairsMask.h"
#include <iostream>
#include <math.h>

void MakePairsMask::clearAndfillAllPairs
    (std::vector< std::pair<Point,Point> >& pairs) 
    {
    
    pairs.clear();
    
    for ( int ytl=0; ytl<_pattern->height; ytl+= _ws) {
        for ( int xtl= 0; xtl<_pattern->width; xtl+=_ws) {
            
            _windowPairs.clear();
            for ( int y= ytl; (y<_pattern->height)&&(y<ytl+_ws); ++y) {
                for ( int x= xtl; (x<_pattern->width)&&(x<xtl+_ws); ++x) {
                    if (inOrigMask(x,y)) fillNeighborsPairs(x,y);
                } // x
            } // y
            
            
            PairsPointsComparator comp(_pattern);
            sort(_windowPairs.begin(),_windowPairs.end(),comp);
            
            // TODO: check this caused seg fault
            // because over the top iterator
            if (_windowPairs.size()>(unsigned int)_mfw) {
                pairs.insert(
                             pairs.end(),
                             _windowPairs.begin(), 
                             _windowPairs.begin()+_mfw);
            } else {
                pairs.insert(
                             pairs.end(),
                             _windowPairs.begin(), 
                             _windowPairs.end());
            }
            
        } // xtl
    } // ytl
    
} // end clearAndfillAllPairs




void MakePairsMask::clearAndfillLUPairs
    (const std::vector< std::pair<Point,Point> >& pairs,
     int gtNeighborLU,
     int minNumOfLuPixels,
     std::vector< std::pair<Point,Point> >& LUpairs,
     int& minLUvalInPairs) {
    
    LUpairs.clear();
    minLUvalInPairs= 0;
    
    if (pairs.size()==0) return;
    
    //--------------------------------------------------
    // computes LU for each pair and max LU
    //--------------------------------------------------
    std::vector<int> LUpairsVals( pairs.size() , 0 );
    int maxLU= 0;
    for (unsigned int i= 0; i<pairs.size(); ++i) {
        
        using std::max;
        using std::min;
        
        int x1= pairs[i].first.x;
        int y1= pairs[i].first.y;
        int x2= pairs[i].second.x;
        int y2= pairs[i].second.y;
        
        int minX= min(x1, x2);
        int minY= min(y1, y2);
        int minXY= min(minX, minY);
        
        int currTryLU= 1;
        bool LUNotOk= false;
        while (currTryLU<=minXY) {
            
            // row strip of LU i.e the xxx in:
            // xxx
            // |
            // | o
            int y1n= y1-currTryLU; 
            int y2n= y2-currTryLU; 
            int x1n= x1-currTryLU; // start
            int x2n= x2-currTryLU; // start
            while (x1n<=x1) {
                if (!goodLUPair(x1n, y1n, x2n, y2n, gtNeighborLU)) {
                    LUNotOk= true;
                    break;
                } 
                ++x1n;
                ++x2n;
            }
            if (LUNotOk) break;
            
            // coloumn strip of LU i.e the xxx in:
            // ---
            // x
            // x o
            y1n= y1-currTryLU+1; // start
            y2n= y2-currTryLU+1; // start
            x1n= x1-currTryLU; 
            x2n= x2-currTryLU; 
            while (y1n<=y1) {
                if (!goodLUPair(x1n, y1n, x2n, y2n, gtNeighborLU)) {
                    LUNotOk= true;
                    break;
                } 
                ++y1n;
                ++y2n;
            }
            if (LUNotOk) break;
            
            LUpairsVals[i]= currTryLU;
            if (maxLU<currTryLU) maxLU= currTryLU;
            ++currTryLU;
            
        } // end currTryLU
        
        
    } // for i
    //--------------------------------------------------
    
    //--------------------------------------------------
    // Find minLUvalInPairs that we return and fill up
    // LUpairs
    //--------------------------------------------------
    
    // count how many of each LU
    std::vector<int> numOfPairsWithLU(maxLU+1,0);
    for (unsigned int i= 0; i<LUpairsVals.size(); ++i) {
        ++numOfPairsWithLU[ LUpairsVals[i] ];
    }
    // do reverse cumsum (pair that have LU1>LU2 have also LU2...
    for (int i= numOfPairsWithLU.size()-2; i>=0; --i) {
        numOfPairsWithLU[i]+= numOfPairsWithLU[i+1];
    }
    assert(numOfPairsWithLU[0]==(int)pairs.size());
    
    // find minLUvalInPairs
    minLUvalInPairs= numOfPairsWithLU.size()-1;
    while (numOfPairsWithLU[minLUvalInPairs]<minNumOfLuPixels&&minLUvalInPairs>0) {
        --minLUvalInPairs;
    }
    
    // fill LUpairs
    for (unsigned int i= 0; i<pairs.size(); ++i) {
        if (LUpairsVals[i]>=minLUvalInPairs) {
            LUpairs.push_back( pairs[i] ); 
        }
    }
    
    //std::cout << "pairs.size() == " << pairs.size() << std::endl;
    //std::cout << "LU used == " << minLUvalInPairs << std::endl;
    //std::cout << "LUpairs.size() == " << LUpairs.size() << std::endl;
     
    assert( (int)LUpairs.size()==numOfPairsWithLU[minLUvalInPairs] );
    
    //--------------------------------------------------
    
} // clearAndfillLUPairs



void MakePairsMask::clearAndfillLURPairs
    (const std::vector< std::pair<Point,Point> >& pairs,
     int gtNeighborLU,
     int minNumOfLuPixels,
     std::vector< std::pair<Point,Point> >& LUpairs,
     int& LUX,
     int& LUY) {
    
    LUpairs.clear();
    LUX= 0;
    LUY= 0;
    
    if (pairs.size()==0) return;
    
    
    
    // find all rectangles                                        
    std::vector< std::vector< LURectangle > > pairs_LUR_vecs( pairs.size() );
    for (unsigned int i= 0; i<pairs_LUR_vecs.size(); ++i) {
        fillLURVec(pairs[i].first.x, pairs[i].first.y,
                   pairs[i].second.x, pairs[i].second.y,
                   gtNeighborLU,
                   pairs_LUR_vecs[i]);
    }
    
    findCharacharesticLUXLUY(pairs_LUR_vecs, minNumOfLuPixels, LUX,LUY);
    
    LUpairs.clear();
    fillLURPairs(pairs_LUR_vecs, LUX,LUY, pairs, LUpairs);
    
    

} // end clearAndfillLUPairs
    
void MakePairsMask::findCharacharesticLUXLUY
    (const std::vector< std::vector< LURectangle > >& pairs_LUR_vecs,
     int minNumOfLuPixels,
     int& LUX, int& LUY) {
    
    LUX= LUY= 0;
    int minNumWindowsInIm= numWindowsInIm(LUX,LUY);
    
    for (unsigned int i= 0; i<pairs_LUR_vecs.size(); ++i) {
        for (unsigned int j= 0; j<pairs_LUR_vecs[i].size(); ++j) {
            
            int LUX_checked= pairs_LUR_vecs[i][j]._LUX;
            int LUY_checked= pairs_LUR_vecs[i][j]._LUY;
            
            // TODO: remove this !!!
            //if (!((LUX_checked==6)&&(LUY_checked==6))) continue;
            if ( (LUX_checked-LUY_checked > 1) || (LUY_checked-LUX_checked > 1) ) continue;
                        
            if ((numWindowsInIm(LUX_checked,LUY_checked) < minNumWindowsInIm) &&
                (countPairs(LUX_checked,LUY_checked,pairs_LUR_vecs) >= minNumOfLuPixels)) {
                LUX= LUX_checked;
                LUY= LUY_checked;
                minNumWindowsInIm= numWindowsInIm(LUX_checked,LUY_checked);
            } 
            
        } // j
    } // i

} // end findCharacharesticLUXLUY

int MakePairsMask::countPairs
    (int LUX, int LUY,
     const std::vector< std::vector< LURectangle > >& pairs_LUR_vecs) {
    
    int numPairs= 0;
    for (unsigned int i= 0; i<pairs_LUR_vecs.size(); ++i) {
        
        unsigned int j=0;
        bool notFoundPair= true;
        while (j<pairs_LUR_vecs[i].size()&&notFoundPair) {
            
            int LUX_checked= pairs_LUR_vecs[i][j]._LUX;
            int LUY_checked= pairs_LUR_vecs[i][j]._LUY;
            if ( LUX_checked>=LUX && LUY_checked>=LUY ) {
                notFoundPair= false;
                ++numPairs;
            }
            ++j;
        
        } // j
        
    } // i
    
    return numPairs;

} // end countPairs

void MakePairsMask::fillLURPairs
    (const std::vector< std::vector< LURectangle > >& pairs_LUR_vecs, 
     int LUX, int LUY, 
     const std::vector< std::pair<Point,Point> >& pairs,
     std::vector< std::pair<Point,Point> >& LUpairs) {

    for (unsigned int i= 0; i<pairs_LUR_vecs.size(); ++i) {
        
        unsigned int j=0;
        bool notFoundPair= true;
        while (j<pairs_LUR_vecs[i].size()&&notFoundPair) {
            
            int LUX_checked= pairs_LUR_vecs[i][j]._LUX;
            int LUY_checked= pairs_LUR_vecs[i][j]._LUY;
            if ( LUX_checked>=LUX && LUY_checked>=LUY ) {
                LUpairs.push_back( pairs[i] );
                notFoundPair= false;
            }
            ++j;
        
        } // j
        
    } // i

} // end fillLURPairs

void MakePairsMask::fillLURVec(int x1, int y1, int x2, int y2, int gtLU, 
                               std::vector< LURectangle >& LUR_vec) {
    using std::max;
    using std::min;
    
    int LUY_max= min(y1,y2);
    int LUX_max= min(x1,x2);
    
    int LUX= 0;
    while (LUX<=LUX_max) {
        
        int LUY= 0;
        while (LUY<=LUY_max) {
            
            if (!goodLUPair(x1-LUX, y1-LUY, x2-LUX, y2-LUY, gtLU)) {
                if (LUY==0) goto endFillLURVec;
                LUY_max= LUY-1;
                break;
            }
            ++LUY;
            
        } // end LUY
        
        if ( (!LUR_vec.empty()) && ((LUR_vec.back()._LUY)==(LUY-1)) ) {
            LUR_vec.back()._LUX= LUX;
        } else {
            LUR_vec.push_back( LURectangle(LUX,LUY-1) );
        }
        
        ++LUX;
            
    } // end LUX

endFillLURVec:
    return;
} // end fillLURVec



void MakePairsMask::fillNeighborsPairs( int x, int y) {
    
    using std::max;
    using std::min;
    
    int xol= max(0,x-_maxN);
    int xil= max(0,x-_minN+1);
    int xir= min(_pattern->width,x+_minN);
    int xorr= min(_pattern->width,x+_maxN+1);
    
    int you= max(0,y-_maxN);
    int yiu= max(0,y-_minN+1);
    int yid= min(_pattern->height,y+_minN);
    int yod= min(_pattern->height,y+_maxN+1);
    
    
    
    for (int yn= you; yn<yiu; ++yn) {
        for (int xn= xol; xn<xorr; ++xn) {
            insertPairIfGood(x,y,xn,yn);
        }
    }
    
    
    
    for (int yn= yiu; yn<yid; ++yn) {
        for (int xn= xol; xn<xil; ++xn) {
            insertPairIfGood(x,y,xn,yn);
        }
    }
    
    
    
    for (int yn= yiu; yn<yid; ++yn) {
        for (int xn= xir; xn<xorr; ++xn) {
            insertPairIfGood(x,y,xn,yn);
        }
    }
    
    
    
    for (int yn= yid; yn<yod; ++yn) {
        for (int xn= xol; xn<xorr; ++xn) {
            insertPairIfGood(x,y,xn,yn);
        }
    }
    
} // end fillNeighborsPairs

void MakePairsMask::insertPairIfGood(int x,int y,int xn,int yn) {
    int distPow2= ((x-xn)*(x-xn)+(y-yn)*(y-yn)); 
    //std::cout << _minNPow2 << std::endl;
    if ( distPow2>_maxNPow2||
        distPow2<_minNPow2 ) {
        return;
    }
    
    
    if (inOrigMask(xn,yn)&&goodPair(x,y,xn,yn)) {
        _windowPairs.push_back( std::make_pair( Point(x,y) , Point(xn,yn) ) );
    }
}


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
