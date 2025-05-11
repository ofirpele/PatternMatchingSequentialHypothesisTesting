------------------------------------------------------------------------------------------------------------------
Folders:
------------------------------------------------------------------------------------------------------------------
Test/ Test_input/ Test_src/             Testing related...
Debug/                                  Contains an eclipse makefile, objects and executable) for debug mode
Release/                                Same as Debug for Release mode
src/                                    Contains all the sources of the project
------------------------------------------------------------------------------------------------------------------


------------------------------------------------------------------------------------------------------------------
Files in src:
------------------------------------------------------------------------------------------------------------------
GLOBALS.cpp                             Used to collect statistics on the program iterations. Should be of no interest to others.
HSMain.cpp                              Contains the main which calls the Runner.
GlobalRandsArr.h                        Pseudo random numbers.
MasksMakers.h                           Converts the pattern to a "Mask" (bad name). A "Mask" contains the features of the pattern
                                        (pixels or pairs of pixels) with information about the image. i.e: instead of storing the
                                        spatial location of a pixel we store the spatial disparity we need to add to a top left location
                                        pixel in the big image. In other words we cache the computation of disparity=y*imageWidthStep+x
                                        where imageWidthStep is the big image width.
                                        The class also shuffles and duplicates it to the end.
RejectGrades.h                          Produces rejection grades. i.e: Points that if touched returns non-similar.
TRandomaNumberGenerator.h               Random numbers generator 

ExactFastMatcher.h                      Does exact matching, slow.
SeqFastMatcher.h                        Does fast matching as described in the PAMI paper.
cvHammingMatchTemplate.impl.h           Implementation of the matching in the above two files.
LUSeqFastMatcher.h                      Does fast matching as described in the ACCV paper. i.e: same as PAMI, but with the LU technique which makes it faster
------------------------------------------------------------------------------------------------------------------
                                        
------------------------------------------------------------------------------------------------------------------
Interesting files in src/runner (all other files are related to the executable)
------------------------------------------------------------------------------------------------------------------
MakePairsMask.cpp                       See documentation
fillLUmaskLocationsVec.h                For the ACCV technique - computes LU rank
------------------------------------------------------------------------------------------------------------------


------------------------------------------------------------------------------------------------------------------
src/isSimilar folder
------------------------------------------------------------------------------------------------------------------
This folder contains functors that checks if two features (pixels or pairs of pixels) are similar.
In addition it contains InputPatterns which are classes that have a fill method that convert the pattern info into
a mask info.
------------------------------------------------------------------------------------------------------------------
