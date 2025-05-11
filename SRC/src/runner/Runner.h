#ifndef RUNNER_H_
#define RUNNER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <opencv/highgui.h>
#include <opencv/cv.h>

#include <runner/images_names_directory_LINUX.h>
#include <runner/cmdline.h>

#include <isSimilar/Point.h>

//----------------------------------------
#include <runner/matchers/ExactAbsMatchersRunner.h>
#include <runner/matchers/SeqAbsMatchersRunner.h>
#include <runner/matchers/SeqAbsMatchersRunnerStat.h>

#include <runner/matchers/ExactGtPairsMatchersRunner.h>
#include <runner/matchers/SeqGtPairsMatchersRunner.h>
#include <runner/matchers/SeqGtPairsMatchersRunnerStat.h>
#include <runner/matchers/LUSeqGtPairsMatchersRunner.h>
#include <runner/matchers/LUSeqGtPairsMatchersRunnerStat.h>
#include <runner/matchers/LUSeqABSMatchersRunner.h>
#include <runner/matchers/LUSeqABSMatchersRunnerStat.h>
//----------------------------------------

#include <runner/MakePairsMask.h>

#include <runner/ResultsImageMaker.h>

// for checking time of program
#include <sys/param.h>
#include <sys/times.h>
#include <sys/types.h>
#include <runner/Timer.h>

#include <runner/StatisticsMaker.h>

/// This class does the parsing of the input from the user and runs everything.
class Runner {
public:
    
    
    
    /// Ctor. 
    Runner(int argc, char *argv[]) 
        : _argc(argc),
        _argv(argv),
        
        _pattern(NULL),
        
        _patternWithMask(NULL),
        
        _mask(NULL), 
        _currIm(NULL), // free after each step
        
        
        _imsFileNamesPtr(NULL),
        
        _currResult(NULL),
        _currDistResult(NULL),
        
        _resultsImageMakerPtr(NULL),
        
        _expectedDetectionsIm(NULL)
        
        {}
        
    
    
    /// Dtor.
    ~Runner() {
        clearResources();
    }
    
    
    
    
    
    
    
    
    
    /// Does the parsing of the input from the user and runs everything.
    void run();
    
    
private:
    
    
    
    
    
    //---------------------------------------
    // private methods
    //---------------------------------------
    void clearResources();
    
    IplImage* imLoadChooseColor(const char* imFileName, 
                                char* type, 
                                int iscolor);
            
    IplImage* imLoad(const char* imFileName, char* type) {
        return imLoadChooseColor(imFileName, type,_CV_LOAD_IMAGE_GRAYSCALE);
    } // end imLoadChoose
    
    /* TODO: leak and mv not work
     * Creates an autosize window with the given name \
     * and shows the given image in it.
     *
     * @param im given image
     * @param win_name given window name
     */
    void cvImShow(
        IplImage const * const im,
        char const * const win_name,
        int mvX=300,
        int mvY=200) {

        cvNamedWindow(win_name, CV_WINDOW_AUTOSIZE);
        cvMoveWindow(win_name, 100, 30);


        IplImage* im_resized= cvCreateImage(cvSize(1024,768), IPL_DEPTH_8U, 1);
        // TODO:leak here...
        cvResize(im, im_resized);

        cvShowImage(win_name, im_resized);
    }
    
        
    void cvPause() {
        cvWaitKey(0);
        cvDestroyAllWindows();
    }
    
    
    void init();
    
    // Creates one results of the current image
    void currMatch(bool forceExact=false) {
        
        
        
        if (strEq(_argsInfo.dist_arg,"abs")) {
            if (strEq(_argsInfo.match_arg,"seq")&&!forceExact) {
                if (!_argsInfo.LU_off_flag) {
                    if (_argsInfo.statistics_arg<=0) {
                        _LUseqABSMatchersRunner.match(_currIm, _currResult);
                    } else {
                        _LUseqABSMatchersRunnerStat.match(_currIm, _currResult);
                    }
                } else {
                    if (_argsInfo.statistics_arg<=0) {
                        _seqAbsMatchersRunner.match(_currIm, _currResult);
                    } else {
                        _seqAbsMatchersRunnerStat.match(_currIm, _currResult);
                    }
                } // else LU
            } else if (strEq(_argsInfo.match_arg,"exact")||forceExact) {
                _exactAbsMatchersRunner.match(_currIm, _currResult);
            }
        } else if (strEq(_argsInfo.dist_arg,"gt-pairs")) {
            if (strEq(_argsInfo.match_arg,"seq")&&!forceExact) {
                if (!_argsInfo.LU_off_flag) {
                    if (_argsInfo.statistics_arg<=0) {
                        _LUseqGtPairsMatchersRunner.match(_currIm, _currResult);
                    } else {
                        _LUseqGtPairsMatchersRunnerStat.match(_currIm, _currResult);
                    }
                } else {
                    if (_argsInfo.statistics_arg<=0) {
                        _seqGtPairsMatchersRunner.match(_currIm, _currResult);
                    } else {
                        _seqGtPairsMatchersRunnerStat.match(_currIm, _currResult);
                    }
                } // else LU
            } else if (strEq(_argsInfo.match_arg,"exact")||forceExact) {
                _exactGtPairsMatchersRunner.match(_currIm, _currResult);
            }
        }
    } // end currMatch
    
    
    
    //-------------------------------------------------------------
    // Find results for show or saving or both
    //-------------------------------------------------------------
    void clearAndFillSimilarPoint(std::vector<Point>& similarPoints);
        
    void makeCurrDistResult();
            
    void match_loop();
    
    void checkErr(bool cond, const char* msg=NULL);
    
    void moreChecksCmdline();
    
    
    
    
    
    //---------------------------------------
    // fields
    //---------------------------------------
    int _argc;
    char** _argv;
    gengetopt_args_info _argsInfo;
    
    IplImage* _pattern;
    IplImage* _patternWithMask;
    
    IplImage* _mask;
    IplImage* _currIm;
    std::string _currImFileName;
        
    images_names_directory* _imsFileNamesPtr;
    
    int _maskSize;
        
    CvMat* _currResult;
    IplImage* _currDistResult;
    int _ub;
    int _showLessThan;
     
    StatisticsMaker _fn; 
     
    ExactAbsMatchersRunner _exactAbsMatchersRunner;
    SeqAbsMatchersRunner _seqAbsMatchersRunner;
    SeqAbsMatchersRunnerStat _seqAbsMatchersRunnerStat;
    ExactGtPairsMatchersRunner _exactGtPairsMatchersRunner;
    SeqGtPairsMatchersRunner _seqGtPairsMatchersRunner;
    SeqGtPairsMatchersRunnerStat _seqGtPairsMatchersRunnerStat;
    LUSeqGtPairsMatchersRunner _LUseqGtPairsMatchersRunner;
    LUSeqGtPairsMatchersRunnerStat _LUseqGtPairsMatchersRunnerStat;
    LUSeqABSMatchersRunner _LUseqABSMatchersRunner;
    LUSeqABSMatchersRunnerStat _LUseqABSMatchersRunnerStat;
    
    
    ResultsImageMaker* _resultsImageMakerPtr;
    
    IplImage* _expectedDetectionsIm;
    // The two vectors are built from _expectedDetectionsIm
    vector<Point> _expectedDetectionsPoints;
    vector<Point> _notExpectedDetectionsPoints;
    int _detectionsIt;
    // An event of false detections in image -> per image how much finding where not expected
    StatisticsMaker _falseDetectionsInImg;
    // An event of false detection -> per image if finding where not expected
    StatisticsMaker _falseDetections;
    // An event of detection -> per image finding where expected
    StatisticsMaker _detections; 
     // An event of detection -> per expected place
    StatisticsMaker _detectionsAll; 
    
    long double _total_expected_detections;
    long double _total_found_expected_detections;
    long double _total_expected_detections_per_image;
    long double _total_found_expected_detections_per_image;
    
    int _LUX,_LUY;  
      
    //---------------------------------------
    // consts
    //---------------------------------------
    static const int _CV_LOAD_IMAGE_COLOR= 1;
    static const int _CV_LOAD_IMAGE_GRAYSCALE= 0;
    static const int _CMD_LINE_ERR= 1;
    
    static const uchar EXPECTED_DETECT= 255;
    static const uchar NOT_EXPECTED_DETECT= 0;
    static const uchar DOES_NOT_MATTER_EXPECTED_DETECT= 100;
    //---------------------------------------
    
        
    
    //---------------------------------------
    // private static 
    //---------------------------------------
    static bool strEq(const char* s1, const char* s2) {
        return (!strcmp(s1,s2));
    }
    
    static std::string shortFileName(const std::string& fullFileName) {
        std::string::size_type b= fullFileName.find_last_of('/')+1;
        return fullFileName.substr(b);
    }
    
    static std::string shortFileNameNoExt(const std::string& fullFileName) {
        std::string sFileName= shortFileName(fullFileName);
        std::string::size_type e= sFileName.find_last_of('.');
        return sFileName.substr(0,e);
    }
    //---------------------------------------
};
#endif /*RUNNER_H_*/


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
