Code for Computing Prior-Based Sequential Probability Ratio Test Rejection Line
-------------------------------------------------------------------------------
Ofir Pele 
Contact: ofirpele@cs.huji.ac.il
Version: 1.0, Jul 2011

This directory contains the source code for efficiently computing Prior-Based Sequential
Probability Ratio Test (PB-SPRT) rejection line and examples of usage.

This is an implementation of Algorithm 5, section 4.4 in the paper:
  Robust Real Time Pattern Matching using Bayesian Sequential Hypothesis Testing
    Ofir Pele, Michael Werman
    PAMI 2008
Please cite this paper if you use this code.

bibTex:
@article{Pele-pami2008,
 title     = {Robust Real Time Pattern Matching using Bayesian Sequential Hypothesis Testing},
 author    = {Ofir Pele and Michael Werman},
 journal   = {IEEE Trans. Pattern Analysis and Machine Intelligence.},
 volume    = {30},
 number    = {8},
 pages     = {1427--1443},
 year      = {2008}
}

Easy startup
------------
Within Matlab:
>> demo_RejectionLine

Compiling (the folder contains compiled binaries, thus you might not have to compile)
-------------------------------------------------------------------------------------
Within Matlab:
>> compile_all

Usage within Matlab
------------------- 
Type "help RejectionLine" in Matlab.

Usage within C++
----------------
See RejectionLine.hpp documentation.

Licensing conditions
--------------------
See the file LICENSE.txt in this directory for conditions of use.
