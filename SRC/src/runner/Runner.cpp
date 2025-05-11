#include "Runner.h"
#include <runner/fillLUmaskLocationsVec.h>

void Runner::run() {
    
    bool cmdline_parser_err=
        cmdline_parser(_argc, _argv, &_argsInfo);
    checkErr(cmdline_parser_err);
    moreChecksCmdline();
    
    init();
    
    match_loop();
    
    // TODO: move from here?
    if (_argsInfo.statistics_arg>0) {
        cout << "Avg false negative for all windows == " << _fn.avg()*100 << "%"<<endl;
        if (_argsInfo.false_negative_filename_given) {
            ofstream outFile(_argsInfo.false_negative_filename_arg);
            checkErr(!outFile, "Avg false negative filename did not open");
            outFile << _fn.avg()*100 << endl;
            outFile.close();
        }
    }
    
    //cout << "Num elements   " << GLOBAL_num_iterations.num_elements() << endl;
}// end run



//---------------------------------------
// private methods
//---------------------------------------
    
void Runner::clearResources() {
    delete _imsFileNamesPtr;
    cvReleaseImage(&_mask);
    cvReleaseImage(&_pattern);
    cvReleaseImage(&_patternWithMask);
    cvReleaseMat(&_currResult);
    cvReleaseImage(&_currDistResult);
    delete _resultsImageMakerPtr;
    cvReleaseImage(&_currDistResult);
    cvReleaseImage(&_expectedDetectionsIm);
}

IplImage* Runner::imLoadChooseColor(const char* imFileName, char* type, int iscolor) {
    IplImage* im= cvLoadImage(imFileName,iscolor);
    if (!im) {
        std::string errStr= type; 
        errStr+= " image: ";
        errStr+= imFileName;
        errStr+= " not load.";
        checkErr(true,errStr.c_str());
    }
    return im;
} // end imLoadChooseColor





// contains defaults and inits of the data
void Runner::init() {
        
        if (!_argsInfo.thresh_given) {
            if (strEq(_argsInfo.dist_arg,"gt-pairs")) _argsInfo.thresh_arg=0;
            else if (strEq(_argsInfo.dist_arg,"abs")) _argsInfo.thresh_arg=20;
        }
        
        if (!_argsInfo.outliers_given) {
            if (strEq(_argsInfo.dist_arg,"gt-pairs")) _argsInfo.outliers_arg=25;
            else if (strEq(_argsInfo.dist_arg,"abs")) _argsInfo.outliers_arg=40;
        }
        
        // Note: should be after outliers_given !!!
        if (!_argsInfo.LU_outliers_given) {
            _argsInfo.LU_outliers_arg= _argsInfo.outliers_arg;
        }
        
        if (!_argsInfo.LU_gt_neighbor_given) {
            if (strEq(_argsInfo.dist_arg,"gt-pairs")) _argsInfo.LU_gt_neighbor_arg= 20;
            else if (strEq(_argsInfo.dist_arg,"abs")) _argsInfo.LU_gt_neighbor_arg= 5;
        }
        
        
        // if not given -> maximum possible...
        if (!_argsInfo.max_from_window_given) {
            _argsInfo.max_from_window_arg= 
                (((2*_argsInfo.max_neighbor_arg+1)*(2*_argsInfo.max_neighbor_arg+1))-
                 ((2*(_argsInfo.min_neighbor_arg-1)+1)*(2*(_argsInfo.min_neighbor_arg-1)+1))
                )*_argsInfo.window_size_arg;
            //cout << _argsInfo.max_from_window_arg << endl;
        }
        
        _pattern= imLoad(_argsInfo.pattern_arg,"Pattern");
        
        // orig mask
        if (_argsInfo.mask_given) {
            _mask= imLoadChooseColor(_argsInfo.mask_arg,"Mask",_CV_LOAD_IMAGE_GRAYSCALE); // pattern always gray;
            checkErr (_mask->width!=_pattern->width,"Mask image width is not the same as the pattern image width !");
            checkErr (_mask->height!=_pattern->height,"Mask image height is not the same as the pattern image height !");
        } else {
            CvSize sz= cvGetSize(_pattern);
            _mask= cvCreateImage(sz,_pattern->depth, 1);
            cvSet(_mask, cvRealScalar(1));
        }
                
        
        _resultsImageMakerPtr= new ResultsImageMaker(_mask,_argsInfo.show_dilate_border_arg);
        
        // TODO: change here to save with black
        std::vector<Point> similarPoints(1,Point(0,0));
        _patternWithMask= _resultsImageMakerPtr->makeResIm(_pattern,similarPoints); 
        //if (_argsInfo.save_given) {
        //       std::string saveFullFileName= _argsInfo.save_arg;
        //       saveFullFileName+= "/";
        //       saveFullFileName+= shortFileNameNoExt(_argsInfo.pattern_arg);
        //       saveFullFileName+= ".bmp";
        //       cvSaveImage(saveFullFileName.c_str(),_patternWithMask);
        //}
        
        
        // load first big image + init iterator if directory
        if ( _argsInfo.images_arg[ strlen(_argsInfo.images_arg)-1 ]=='/') {
            
            checkErr( _argsInfo.expected_detections_image_given , 
                       "expected-detections given with folder of images" );
            
            checkErr( _argsInfo.detections_it_given , 
                       "expected-detections given with folder of images" );
            
                        
            _imsFileNamesPtr = 
                new images_names_directory(_argsInfo.images_arg);
            
            std::string errStr= "The directory: ";
            errStr+= _argsInfo.images_arg;
            errStr+= " has no images.";
            checkErr(!_imsFileNamesPtr->there_is_more_images_file_names(),errStr.c_str()); 
            
            _currImFileName= _imsFileNamesPtr->next_file_name();
                                   
        } else {
            _currImFileName= _argsInfo.images_arg;
        }
        
        _currIm= imLoad(_currImFileName.c_str(),"Big ");
        
        checkErr( (_pattern->height > _currIm->height) , "Pattern height is bigger than image height");
        checkErr( (_pattern->width > _currIm->width) , "Pattern width is bigger than image width");
        
        
        _currResult= cvCreateMat(
            _currIm->height - _pattern->height + 1,
            _currIm->width  - _pattern->width  + 1,
            CV_32SC1);
        
        _currDistResult= cvCreateImage( cvSize(_currResult->width,_currResult->height), IPL_DEPTH_8U, 1);
        
        
        
        //-----------------------------------------------------------
        // check which kind of distance =>
        // which kind of mask and create as needed
        //-----------------------------------------------------------
        std::vector<Point> maskLocationsVec;
        std::vector<Point> LUmaskLocationsVec;
        std::vector< pair<Point,Point> > maskPairsVec;
        std::vector< pair<Point,Point> > LUmaskPairsVec;
        
        if (strEq(_argsInfo.dist_arg,"abs")) {
            
            for (int x=0; x<_pattern->width; ++x) {
                for (int y=0; y<_pattern->height; ++y) {
                    if (static_cast<int>(((uchar*)(_mask->imageData + _mask->widthStep*y))[x])!=0) {
                        maskLocationsVec.push_back(Point(x,y));
                    }
                }
            }
            _maskSize= maskLocationsVec.size();
            
            if (_maskSize==0) {
                checkErr( true , "Mask contains zero features");
            }
            
            if (!_argsInfo.LU_off_flag) {
                fillLUmaskLocationsVec::fill(LUmaskLocationsVec,
                                            _LUX,
                                            _LUY,
                                            
                                            maskLocationsVec,
                                            
                                            _pattern,
                                            _mask,
                                            
                                            _argsInfo.LU_gt_neighbor_arg,
                                            _argsInfo.LU_min_num_of_LU_pixels_arg
                                            );
            }
            if (LUmaskLocationsVec.size()==0) {
                _argsInfo.LU_off_flag= true;
            }
            
            
                        
            if (strEq(_argsInfo.match_arg,"seq")) {
                if (_argsInfo.statistics_arg<=0) {
                    if (!_argsInfo.LU_off_flag) {
                        _LUseqABSMatchersRunner.init(_argsInfo.thresh_arg,
                                                     _currIm->widthStep,
                                                     _currIm->width,
                                                     _currIm->height,
                                                     _pattern,
                                                     maskLocationsVec,
                                                     _argsInfo.fn_arg, _argsInfo.outliers_arg,
                                                     LUmaskLocationsVec,
                                                     _argsInfo.LU_fn_arg,
                                                     _argsInfo.LU_outliers_arg,
                                                     _LUX,
                                                     _LUY);
                    } else {
                        _seqAbsMatchersRunner.init(_argsInfo.thresh_arg,_currIm->widthStep,_pattern,maskLocationsVec,
                                                   _argsInfo.fn_arg, _argsInfo.outliers_arg);
                    }
                    
//                    // TODO: offline time measure
//                    struct tms b,e;
//                    long br,er;
//                    br= times(&b);
//                    for (int t=0; t<_argsInfo.run_time_arg; ++t) {
//                        _seqAbsMatchersRunner.init(_argsInfo.thresh_arg,_currIm->widthStep,_pattern,maskLocationsVec,
//                                                   _argsInfo.fn_arg, _argsInfo.outliers_arg);
//                    }
//                    er= times(&e);
//                    
//                    double avgTime=
//                        ((long double)(e.tms_utime-b.tms_utime))
//                        / (_argsInfo.run_time_arg*HZ);
//                    if (_argsInfo.run_time_arg>0) cout << "Offline, init seqFastMatcher == " << avgTime << endl;
//                
                    
                
                
                } else {
                    
                    if (!_argsInfo.LU_off_flag) {
                        _LUseqABSMatchersRunnerStat.init(_argsInfo.thresh_arg,
                                                         _currIm->widthStep,
                                                         _currIm->width,
                                                         _currIm->height,
                                                         _pattern,
                                                         maskLocationsVec,
                                                         _argsInfo.fn_arg, _argsInfo.outliers_arg,
                                                         LUmaskLocationsVec,
                                                         _argsInfo.LU_fn_arg,
                                                         _argsInfo.LU_outliers_arg,
                                                         _LUX,
                                                         _LUY);
                    } else {
                        _seqAbsMatchersRunnerStat.init(_argsInfo.thresh_arg,_currIm->widthStep,_pattern,maskLocationsVec,
                                                       _argsInfo.fn_arg, _argsInfo.outliers_arg);
                    }
                }
            } 
            // exact is init anyway for the stat
            _exactAbsMatchersRunner.init(_argsInfo.thresh_arg,_currIm->widthStep,_pattern,maskLocationsVec);
                    
        }         
        else if (strEq(_argsInfo.dist_arg,"gt-pairs")) {
            
            
            
            
            if (!_argsInfo.LU_off_flag) {
                
                MakePairsMask(_pattern,_mask,        
                              _argsInfo.gt_neighbor_arg,
                              _argsInfo.max_neighbor_arg,
                              _argsInfo.min_neighbor_arg,
                              _argsInfo.window_size_arg,
                              _argsInfo.max_from_window_arg,      
                              maskPairsVec,
                              _argsInfo.LU_gt_neighbor_arg,
                              _argsInfo.LU_min_num_of_LU_pixels_arg,
                              _currIm->width,
                              _currIm->height,
                              LUmaskPairsVec,
                              _LUX,
                              _LUY);
//                cout << "LUX==" << _LUX << " LUY==" << _LUY <<endl;
//                cout << "#LU-PAIRS=="<<LUmaskPairsVec.size() << endl;
                if (LUmaskPairsVec.size()==0) {
                    _argsInfo.LU_off_flag= true;
                }
            } else {
                MakePairsMask(_pattern,_mask,        
                              _argsInfo.gt_neighbor_arg,
                              _argsInfo.max_neighbor_arg,
                              _argsInfo.min_neighbor_arg,
                              _argsInfo.window_size_arg,
                              _argsInfo.max_from_window_arg,      
                              maskPairsVec);
            }
            
          
            
//            struct tms b,e;
//            long br,er;
//            br= times(&b);
//            for (int t=0; t<_argsInfo.run_time_arg; ++t) {
//                if (!_argsInfo.LU_off_flag) {
//                    MakePairsMask(_pattern,_mask,        
//                              _argsInfo.gt_neighbor_arg,
//                              _argsInfo.max_neighbor_arg,
//                              _argsInfo.min_neighbor_arg,
//                              _argsInfo.window_size_arg,
//                              _argsInfo.max_from_window_arg,      
//                              maskPairsVec,
//                              _argsInfo.LU_gt_neighbor_arg,
//                              _argsInfo.LU_min_num_of_LU_pixels_arg,
//                              _currIm->width,
//                              _currIm->height,
//                              LUmaskPairsVec,
//                              _LUX,
//                              _LUY);
//                } else {
//                    MakePairsMask(_pattern,_mask,        
//                                  _argsInfo.gt_neighbor_arg,
//                                  _argsInfo.max_neighbor_arg,
//                                  _argsInfo.min_neighbor_arg,
//                                  _argsInfo.window_size_arg,
//                                  _argsInfo.max_from_window_arg,      
//                                  maskPairsVec);
//                }
//            }
//            er= times(&e);
//            
//            double avgTime=
//                ((long double)(e.tms_utime-b.tms_utime))
//                / (_argsInfo.run_time_arg*HZ);
//            if (_argsInfo.run_time_arg>0) cout << "Offline, making mask time == " << avgTime << endl;
            
            _maskSize= maskPairsVec.size();
            if (_maskSize==0) {
                checkErr( true , "Mask contains zero features !");
            }
            
            if (strEq(_argsInfo.match_arg,"seq")) {
                if (_argsInfo.statistics_arg<=0) {
                    
                    if (!_argsInfo.LU_off_flag) {
                        _LUseqGtPairsMatchersRunner.init(_argsInfo.thresh_arg,
                                                         _currIm->widthStep,
                                                         _currIm->width,
                                                         _currIm->height,
                                                         _pattern,maskPairsVec,
                                                         _argsInfo.fn_arg, _argsInfo.outliers_arg,
                                                         LUmaskPairsVec,
                                                         _argsInfo.LU_fn_arg,
                                                         _argsInfo.LU_outliers_arg,
                                                         _LUX,
                                                         _LUY);
                    } else {
                        _seqGtPairsMatchersRunner.init(_argsInfo.thresh_arg,_currIm->widthStep,_pattern,maskPairsVec,
                                                       _argsInfo.fn_arg, _argsInfo.outliers_arg);
                    }
                    
//                    // TODO: add here check of offline 
//                    // same also for every place
//                    struct tms b,e;
//                    long br,er;
//                    br= times(&b);
//                    for (int t=0; t<_argsInfo.run_time_arg; ++t) {
//                        if (!_argsInfo.LU_off_flag) {
//                            _LUseqGtPairsMatchersRunner.init(_argsInfo.thresh_arg,
//                                                             _currIm->widthStep,
//                                                             _currIm->width,
//                                                             _currIm->height,
//                                                             _pattern,maskPairsVec,
//                                                             _argsInfo.fn_arg, _argsInfo.outliers_arg,
//                                                             LUmaskPairsVec,
//                                                             _argsInfo.LU_fn_arg,
//                                                             _argsInfo.LU_outliers_arg,
//                                                             _LUX,
//                                                             _LUY);
//                        } else {
//                            _seqGtPairsMatchersRunner.init(_argsInfo.thresh_arg,_currIm->widthStep,_pattern,maskPairsVec,
//                                                           _argsInfo.fn_arg, _argsInfo.outliers_arg);
//                        }
//                    }
//                    er= times(&e);
//                    
//                    double avgTime=
//                        ((double)(e.tms_utime-b.tms_utime))
//                        / (_argsInfo.run_time_arg*HZ);
//                    
//                    
//                    if (_argsInfo.run_time_arg>0) cout << "Offline, init seqFastMatcher == " << avgTime << endl;
//                    //----------------------------------------------------------
                } else {
                    if (!_argsInfo.LU_off_flag) {
                        _LUseqGtPairsMatchersRunnerStat.init
                            (_argsInfo.thresh_arg,
                             _currIm->widthStep,
                             _currIm->width,
                             _currIm->height,
                             _pattern,maskPairsVec,
                             _argsInfo.fn_arg, _argsInfo.outliers_arg,
                             LUmaskPairsVec,
                             _argsInfo.LU_fn_arg,
                             _argsInfo.LU_outliers_arg,
                             _LUX,
                             _LUY);
                    } else {
                        _seqGtPairsMatchersRunnerStat.init(_argsInfo.thresh_arg,_currIm->widthStep,_pattern,maskPairsVec,
                                                       _argsInfo.fn_arg, _argsInfo.outliers_arg);
                    }
                }
            }
            // exact is init anyway for the stat
            _exactGtPairsMatchersRunner.init(_argsInfo.thresh_arg,_currIm->widthStep,_pattern,maskPairsVec);
            
            
        }
         
        
        _ub= static_cast<int>(floor( (_argsInfo.outliers_arg/100.0)*_maskSize ));    
            
        if (strEq(_argsInfo.find_arg,"lessOutliers")) {
            _showLessThan= _ub;
        } 
        
        
        if (_argsInfo.expected_detections_image_given) {
            
            _expectedDetectionsIm= imLoadChooseColor(_argsInfo.expected_detections_image_arg,"Expected detections",_CV_LOAD_IMAGE_GRAYSCALE); // expected detections always gray;
            checkErr (_expectedDetectionsIm->width !=_currIm->width,"Expected detections image width is not the same as the current image width !");
            checkErr (_expectedDetectionsIm->height!=_currIm->height,"Expected detections image height is not the same as the current image height !");
            
            
            
            for (int y=0; y<_expectedDetectionsIm->height; ++y) {
                for (int x=0; x<_expectedDetectionsIm->width; ++x) {
                    uchar val = CV_IMAGE_ELEM(_expectedDetectionsIm,uchar,y,x);
                    switch (val) {
                        case EXPECTED_DETECT:
                            _expectedDetectionsPoints.push_back( Point(x,y) );
                            //cout << "Expect: " << x << " " << y  << endl;
                            break;
                        case NOT_EXPECTED_DETECT:
                            _notExpectedDetectionsPoints.push_back( Point(x,y) );
                            break;
                        case DOES_NOT_MATTER_EXPECTED_DETECT:
                            break;
                        default:
                            checkErr(true,"Expected detections image contained a not legal value (0,100,255) !");
                            break;
                        } // end switch
                } //x
            }// y
        } // expected
        
        //cout << "Num of features == " << _maskSize << endl;
        //cout << "Ub == " << _ub << endl;
        
} // end init
    
    

    
    
    
    
//-------------------------------------------------------------
// Find results for show or saving or both
//-------------------------------------------------------------
void Runner::clearAndFillSimilarPoint(std::vector<Point>& similarPoints) {
    
    similarPoints.clear();
    
    if (strEq(_argsInfo.find_arg,"min")) {
        
        int minVal= _maskSize-1; // never wants to see all...
        
        for (int y= 0; y<_currResult->rows; ++y )     {
            for (int x= 0; x<_currResult->cols; ++x){
                
                if ( CV_MAT_ELEM(*_currResult,int,y,x) <= minVal ) {
                    if (CV_MAT_ELEM(*_currResult,int,y,x) < minVal) {
                        minVal= CV_MAT_ELEM(*_currResult,int,y,x);
                        similarPoints.clear();
                    }
                    similarPoints.push_back( Point(x,y) );
                }
                
            } //x
        } //y
        
        _showLessThan= minVal;
    } // if find_arg=="min"
    
    
    if (strEq(_argsInfo.find_arg,"lessOutliers")) {
        
        for (int y= 0; y<_currResult->rows; ++y )     {
            for (int x= 0; x<_currResult->cols; ++x){
                if ( CV_MAT_ELEM(*_currResult,int,y,x) <= _ub ) {
                    similarPoints.push_back( Point(x,y) );
                }
            }
        }
    } // end find lessOutliers
    
    if (_argsInfo.print_found_windows_flag) {
        //cout << "Similar points (y x dist ) : " << endl;
        for (unsigned int i= 0; i<similarPoints.size(); ++i) {
            cout << similarPoints[i].y << " " << similarPoints[i].x << " ";
            cout << CV_MAT_ELEM(*_currResult,int,similarPoints[i].y,similarPoints[i].x) << endl;
        }
        cout << endl;
    }
    
    
} // end clearAndFillSimilarPoint



void Runner::makeCurrDistResult() {
    for (int y=0; y<_currResult->height; ++y) {
        for (int x=0; x<_currResult->width; ++x) {
            ((uchar*)(_currDistResult->imageData + _currDistResult->widthStep*y))[x]=
                CV_MAT_ELEM(*_currResult, int, y, x)*255/_maskSize;
        }
    }
}






void Runner::match_loop() {
        
        // show || save || show-min (TODO: CHECK if show-min does not create problems here)
        if (!_argsInfo.no_show_flag||
            _argsInfo.save_given||
            _argsInfo.print_found_windows_given) {
            
            
            currMatch();
                        
                                                
            std::vector<Point> similarPoints;
            clearAndFillSimilarPoint(similarPoints);
            
            IplImage* imPaintedFound= _resultsImageMakerPtr->makeResIm(_currIm,similarPoints);
            
            
            // if saves and min distance - save cropped occurnce
            if ((_argsInfo.save_given)&&
                ((strEq(_argsInfo.find_arg,"min")))) {
                IplImage* occurnceOfPatternInImage= cvCloneImage(_pattern);
                for (int y=0; y<occurnceOfPatternInImage->height; ++y) {
                    for (int x=0; x<occurnceOfPatternInImage->width; ++x) {
                        CV_IMAGE_ELEM(occurnceOfPatternInImage,uchar,y,x)= 
                            CV_IMAGE_ELEM(_currIm,uchar,similarPoints[0].y+y,similarPoints[0].x+x);
                                  // LINE UP CREATES SEG FAULT!!!
                    }
                }
                std::string saveFullFileName= _argsInfo.save_arg;
                saveFullFileName+= "/";
                saveFullFileName+= shortFileNameNoExt(_currImFileName);
                saveFullFileName+= "_res_cropped.png";
                
                cvSaveImage(saveFullFileName.c_str(),occurnceOfPatternInImage);
                cvReleaseImage(&occurnceOfPatternInImage);
            }
            
            makeCurrDistResult();
            
            if (!_argsInfo.no_show_flag) {
                std::string showTitle= shortFileName(_currImFileName);
                showTitle+= ". Distance";
                if (strEq(_argsInfo.find_arg,"min")) {
                    showTitle+= "==";
                    showTitle+= num_2_str::convert( floor(_showLessThan*100/(double)_maskSize) );
                } else if (strEq(_argsInfo.find_arg,"lessOutliers")) {
                    showTitle+= "<=";
                    showTitle+= num_2_str::convert( _argsInfo.outliers_arg );
                }
                showTitle+= "%";
                cvImShow(imPaintedFound, showTitle.c_str(),300,0 );
                //cvImShow(_patternWithMask, "pattern",300+650,0);
                //cvImShow(_currDistResult, "distance map",300,700);
                cvPause();
            }
            
            if (_argsInfo.save_given) {
                std::string saveFullFileName= _argsInfo.save_arg;
                saveFullFileName+= "/";
                //saveFullFileName+= shortFileNameNoExt(_argsInfo.pattern_arg);
                //saveFullFileName+= "_in_";
                saveFullFileName+= shortFileNameNoExt(_currImFileName);
                saveFullFileName+= ".png";
                cvSaveImage(saveFullFileName.c_str(),imPaintedFound);
            }
            
            cvReleaseImage(&imPaintedFound);
        } // show and save
        
        // if needs to check time
        if (_argsInfo.run_time_arg>0) {
            struct tms b,e;
            long br,er;
            br= times(&b);
            for (int t=0; t<_argsInfo.run_time_arg; ++t) {
                currMatch();
            }
            er= times(&e);
            
            double avgTime=  
                ((long double)(e.tms_utime-b.tms_utime))
                /
                (_argsInfo.run_time_arg*HZ);
            
            //double avgTime= 
            //    ((double)(er-br))/
            //    (_argsInfo.run_time_arg*HZ);
            cout << shortFileName(_currImFileName) << " average running time in seconds == " << avgTime << endl;
            if (_argsInfo.run_time_file_name_given) {
                ofstream outFile(_argsInfo.run_time_file_name_arg);
                checkErr(!outFile, "Average running time file did not open");
                outFile << avgTime << endl;
                outFile.close();
            }
        } // checking time
            
        // statistics
        if (_argsInfo.statistics_arg>0) {
            
            // it 
            for (int t=0; t<_argsInfo.statistics_arg; ++t) {
                currMatch();
            }
            
            cout << "After (including all past images statistics about iterations) " << shortFileName(_currImFileName) << " avg number of iterations per window == " << GLOBAL_num_iterations.avg() << endl;
            if (_argsInfo.iterations_filename_given) {
                ofstream outFile(_argsInfo.iterations_filename_arg);
                checkErr(!outFile, "Avg number of iterations filename did not open");
                outFile << GLOBAL_num_iterations.avg() << endl;
                outFile.close();
            }
            
            
            // fn
            currMatch(true);
            CvMat* exactResults= cvCloneMat(_currResult);
            
            for (int t=0; t<_argsInfo.statistics_arg; ++t) {
                currMatch();
            
                for (int y=0; y<exactResults->height; ++y) {
                    for (int x= 0; x<exactResults->width; ++x) {
                        
                                                    
                        if ( CV_MAT_ELEM(*exactResults,int,y,x) <= _ub )  {
                            if ( CV_MAT_ELEM(*_currResult,int,y,x) <= _ub ) {
                                _fn.update(0);
                            } else {
                                _fn.update(1);
                            }
                        }
                    
                    } // x
                } // y
            } // t
                        
            cvReleaseMat(&exactResults);
        } // statistics
        
        
        // expected detections
        if ( _argsInfo.expected_detections_image_given&&_argsInfo.detections_it_arg>0) {            
             
             _total_expected_detections= 0;
             _total_found_expected_detections= 0;
             
             _total_expected_detections_per_image= 0;
             _total_found_expected_detections_per_image= 0;
             
             if (_expectedDetectionsPoints.size()>0) {
                 _total_expected_detections_per_image= _argsInfo.detections_it_arg;
             }
             
             std::vector<Point> similarPoints;
            
             for (int t=0; t<_argsInfo.detections_it_arg; ++t) {
                
                currMatch();
                clearAndFillSimilarPoint(similarPoints);
                
                unsigned int e_i= 0;
                bool foundAtLeastOneSimilarWhereExpected= false;
                while (e_i<_expectedDetectionsPoints.size()) {
                    
                    ++_total_expected_detections;               
                    
                    unsigned int sp_i= 0;
                    int x_expected_similar= _expectedDetectionsPoints[e_i].x;
                    int y_expected_similar= _expectedDetectionsPoints[e_i].y;
                    bool foundCurrExpected= false;
                    while (sp_i<similarPoints.size()&&!foundCurrExpected) {
                        
                        int x_found_as_similar= similarPoints[sp_i].x;
                        int y_found_as_similar= similarPoints[sp_i].y;
                        
                        if (x_found_as_similar==x_expected_similar&&
                            y_found_as_similar==y_expected_similar) {
                            foundCurrExpected= (foundAtLeastOneSimilarWhereExpected= true);
                        }
                        
                        ++sp_i;
                    }
                    if (foundCurrExpected) {
                        _detectionsAll.update(1);
                        ++_total_found_expected_detections;
                    } else {
                        _detectionsAll.update(0);
                    }
                    ++e_i;
                } 
                if (!_expectedDetectionsPoints.empty()) {
                    if (foundAtLeastOneSimilarWhereExpected) {
                        _detections.update(1);
                        ++_total_found_expected_detections_per_image;
                    } else {
                        _detections.update(0);
                    }
                }
                
                unsigned int en_i= 0;
                bool foundAtLeastOneSimilarWhereNotExpected= false;
                while (en_i<_notExpectedDetectionsPoints.size()) {
                    
                    unsigned int sp_i= 0;
                    int x_expected_not_similar= _notExpectedDetectionsPoints[en_i].x;
                    int y_expected_not_similar= _notExpectedDetectionsPoints[en_i].y;
                    bool currNotExpectedFoundAsSimilar= false;
                    while (sp_i<similarPoints.size()&&!currNotExpectedFoundAsSimilar) {
                        
                        int x_found_as_similar= similarPoints[sp_i].x;
                        int y_found_as_similar= similarPoints[sp_i].y;
                        
                        if (x_found_as_similar==x_expected_not_similar&&
                            y_found_as_similar==y_expected_not_similar) {
                            foundAtLeastOneSimilarWhereNotExpected= true;
                            currNotExpectedFoundAsSimilar= true;
                        }
                        ++sp_i;
                    }
                    if (currNotExpectedFoundAsSimilar) {
                        _falseDetectionsInImg.update(1);
                    } else {
                        _falseDetectionsInImg.update(0);
                    }
                    ++en_i;
                }
                if (!_notExpectedDetectionsPoints.empty()) {
                    if (foundAtLeastOneSimilarWhereNotExpected) {
                        _falseDetections.update(1);
                    } else {
                        _falseDetections.update(0);
                    }
                }
                                    
            } // end detections it
                
            if (_argsInfo.detections_rate_filename_given) {
                ofstream outFile(_argsInfo.detections_rate_filename_arg);
                checkErr(!outFile, "Detection rate filename did not open");
                outFile << _detections.avg()*100 << endl;
                outFile << _detectionsAll.avg()*100 << endl;
                outFile << (_total_found_expected_detections_per_image/_total_expected_detections_per_image)*100 << endl;
                outFile << (_total_found_expected_detections/_total_expected_detections)*100 << endl;
                outFile.close();
            } 
            
            if (_argsInfo.false_detections_rate_filename_given) {
                ofstream outFile(_argsInfo.false_detections_rate_filename_arg);
                checkErr(!outFile, "False detection rate filename did not open");
                outFile << _falseDetections.avg()*100 << endl;
                outFile.close();
            } 
            
            if (_argsInfo.false_detections_rate_in_image_filename_given) {
                ofstream outFile(_argsInfo.false_detections_rate_in_image_filename_arg);
                checkErr(!outFile, "False detection in image rate filename did not open");
                outFile << _falseDetectionsInImg.avg()*100 << endl;
                outFile.close();
            } 
                                   
            cout << shortFileName(_currImFileName) << " avg detection rate == " << endl <<_detections.avg()*100 <<"%"<< endl;
            cout << shortFileName(_currImFileName) << " avg false detection rate == " << endl << _falseDetections.avg()*100 <<"%"<< endl;
            cout << shortFileName(_currImFileName) << " avg false detection rate in image == " << endl << _falseDetectionsInImg.avg()*100 <<"%"<< endl;
            
        } // expected detections
            
        
        
        // repeat for all images
        if (_imsFileNamesPtr!=NULL) {
            if (_imsFileNamesPtr->there_is_more_images_file_names()) {
                _currImFileName= _imsFileNamesPtr->next_file_name();
                cvReleaseImage(&_currIm);
                _currIm= imLoad(_currImFileName.c_str(),"Big ");
                match_loop();
            }
        }
        
} // end match_loop


void Runner::checkErr(bool cond, const char* msg) {
    if (cond) {
        if (msg!=NULL) {
            std::cerr << "\033[1;31m" << _argv[0] << ": " << msg << "\033[0;39m" << std::endl;
        }
        clearResources();
        exit(_CMD_LINE_ERR);
    }
} // end checkErr
    
// Does nore checking of the input (not everything).
void Runner::moreChecksCmdline() {
    
    if (strEq(_argsInfo.match_arg,"seq")) {
        checkErr(_argsInfo.fn_arg<0,"fn<0"); 
        checkErr(_argsInfo.fn_arg>100,"fn>100"); 
    } else if (strEq(_argsInfo.match_arg,"exact")) {
        checkErr(_argsInfo.fn_given,"fn given with exact");
        checkErr(_argsInfo.statistics_given,"statistics given with exact");
    } else {
        checkErr(true, "match is not \"seq\" or \"exact\""); 
    }
    
    checkErr((_argsInfo.outliers_given&&_argsInfo.outliers_arg<0),"outliers<0");
    checkErr((_argsInfo.outliers_given&&_argsInfo.outliers_arg>100),"outliers>100");
    
    checkErr((_argsInfo.thresh_given&&_argsInfo.thresh_arg<0),"thresh < 0");
    checkErr((_argsInfo.thresh_given)&&(_argsInfo.thresh_arg>50)&&(_argsInfo.thresh_arg!=100),"thresh > 50 and thresh != 100");
    
    if (strEq(_argsInfo.dist_arg,"gt-pairs")) {
        checkErr(
                 _argsInfo.gt_neighbor_arg<0,
                 "gt-neighbor < 0");
        checkErr(
                 _argsInfo.min_neighbor_arg > _argsInfo.max_neighbor_arg,
                 "min-neighbor > max-neighbor");
        checkErr(
                 _argsInfo.thresh_given&&_argsInfo.gt_neighbor_arg<_argsInfo.thresh_arg,
                 "gt-neighbor < thresh");
        checkErr(
                 _argsInfo.min_neighbor_arg<1,
                 "min-neighbor < 1");
        checkErr(
                 _argsInfo.max_neighbor_arg<1,
                 "max-neighbor < 1");
        checkErr(
                 _argsInfo.window_size_arg<1,
                 "window-size < 1");
        checkErr(
                 ((_argsInfo.max_from_window_arg<1)&&(_argsInfo.max_from_window_given)),
                 "max-from-window < 1");
    }
    
    if (!strEq(_argsInfo.dist_arg,"gt-pairs")&&
        !strEq(_argsInfo.dist_arg,"abs") ) {   
        checkErr(true, "dist is not \"abs\" or \"gt-pairs\""); 
    }
    // if it's not gt-pairs it's options should not be given
    if (!strEq(_argsInfo.dist_arg,"gt-pairs")) {
        checkErr(
                 _argsInfo.gt_neighbor_given,
                 "Distance is not gt-pairs, so it's option \"gt-neighbor\" should not be given.");
        checkErr(
                 _argsInfo.max_neighbor_given,
                 "Distance is not gt-pairs, so it's option \"max-neighbor\" should not be given.");
        checkErr(
                 _argsInfo.min_neighbor_given,
                 "Distance is not gt-pairs, so it's option \"min-neighbor\" should not be given.");
        checkErr(
                 _argsInfo.window_size_given,
                 "Distance is not gt-pairs, so it's option \"window-size\" should not be given.");
        checkErr(
                 _argsInfo.max_from_window_given,
                 "Distance is not gt-pairs, so it's option \"max-from-window\" should not be given.");
        
    }
    
    if (!strEq(_argsInfo.find_arg,"min")&&
        !strEq(_argsInfo.find_arg,"lessOutliers")) { 
        checkErr(true,"find is not \"min\" or \"lessOutliers\"");
    }
    
    // TODO: check what problem
    //checkErr(_argsInfo.show_dilate_border_given&&(!!_argsInfo.no_show_flag||!_argsInfo.save_given),"show-dilate-border given without show or save flags.");
    
    checkErr(_argsInfo.show_dilate_border_arg<=0,"\"show-dilate-border\" should be >0.");
    
    checkErr(((_argsInfo.statistics_arg>0)&&(strEq(_argsInfo.match_arg,"exact"))),"match==exact and statistics>0.");
    
    
    checkErr ( (_argsInfo.expected_detections_image_given&&
                !_argsInfo.detections_it_given) , 
              "expected-detections given without detections-it");
    checkErr ( (!_argsInfo.expected_detections_image_given&&
                _argsInfo.detections_it_given) , 
              "detections-it given without expected-detections");
    //       checkErr ( (_argsInfo.expected_detections_image_given&&
                         //                   _argsInfo.detections_it_given&&
                         //                   !strEq(_argsInfo.find_arg,"min")) , 
                       //                   "detections-it and expected-detections given and find!=\"min\"");
    //                   
    
    
} // end moreChecksCmdline
//---------------------------------------
    
   


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
