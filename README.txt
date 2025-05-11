Code for Robust Real Time Pattern Matching using Bayesian Sequential Hypothesis Testing
---------------------------------------------------------------------------------------
Ofir Pele 
Contact: ofirpele@cis.upenn.edu
Version: 1.0, Mar 2012

This directory contains the source code and executable for the papers:
Robust Real Time Pattern Matching using Bayesian Sequential Hypothesis Testing
 Ofir Pele, Michael Werman
 PAMI 2008 
Accelerating Pattern Matching or How Much Can You Slide?
 Ofir Pele, Michael Werman
 ACCV 2007

Clean code and matlab wrapper for the rejection line computation is available at the folder:
RejectionLine\

Please cite these papers if you use this code.

Easy startup
------------
See/run example.csh

Compiling
---------
This might be a problem as last time I compiled it was 5 years ago and it uses an old version of the OpenCV
library. I hope one day to make a decent distribution, but I have no idea when... As written I written above,
clean code and matlab wrapper for the rejection line computation is available at the folder:
RejectionLine\


Tips
----
Increase value of --outliers if you want more matches (possibly increasing also false positives).

Use a folder name instead of a single file with -I as then the offline time is amortized. Note that in
general the offline could have been done only for size of images (e.g. all patterns of size 3600 pixels) but
the executable don't allow this.

Licensing conditions
--------------------
See the file LICENSE.txt in this directory for conditions of use.
