% rejectionLine= ...
%     RejectionLine(vecSize,...
%                   maxDiffPercentage,...
%                   falseNegativePercentage,...
%                   prior);
%
% Returns an array of rejection points (rejectionLine), using given prior
% or assuming uniform prior.
% This is an implementation of Algorithm 5 in the paper:
%  Robust Real Time Pattern Matching using Bayesian Sequential Hypothesis Testing
%	 Ofir Pele, Michael Werman
%    PAMI 2008
% Please cite the paper if you use this code.
%
% Input:
%
%   vecSize - Size of the vectors compared (the maximum number of binary
%   dis-similarity checks that we will do). 
%   Denoted in paper as |A|.
%   
%   maxDiffPercentage - The max percentage of the dis-similarities that we
%   allow for similar objects.  Values in the range [0,100).
%   Denoted in paper as (t/|A|).
%
%   falseNegativePercentage - The max percentage of undesired rejections
%   (the false-positive is always 0). Values in the range [0,100).  For
%   example, if it is 0.1, we expect 0.1/100 of the 'similar' object pairs
%   to be declared as non-similar.
%   Denoted in paper as alpha (beta, which represents false-positive in
%   paper is assumed zero here).
%
%   prior (optional) - An array of size 'vecSize+1' for each possible
%   d=1..vecSize+1, prior(d) is the prior probability that the distance is
%   equal to d-1.  If not given we assume uniform prior: prior(d)=
%   1/(vecSize+1)
%   Denoted in paper as P[d] (d of paper equals d+1 here).
%
% Output:
%
%   rejectionLine - An array of size vecSize. rejectionLine(i), means that if
%   you sampled i dis-similarties checks and out of them rejectionLine(i)
%   were true (there were rejectionLine(i) dis-similarties between the
%   objects), the two objects are classified as non-similar.

% Copyright (2011), The Hebrew University of Jerusalem.
% All Rights Reserved.

% Created by Ofir Pele
% The Hebrew University of Jerusalem

% This software is being made available for individual non-profit research use only.
% Any commercial use of this software requires a license from the Hebrew University
% of Jerusalem.

% For further details on obtaining a commercial license, contact Ofir Pele
% (ofirpele@cs.huji.ac.il) or Yissum, the technology transfer company of the
% Hebrew University of Jerusalem.

% THE HEBREW UNIVERSITY OF JERUSALEM MAKES NO REPRESENTATIONS OR WARRANTIES OF
% ANY KIND CONCERNING THIS SOFTWARE.

% IN NO EVENT SHALL THE HEBREW UNIVERSITY OF JERUSALEM BE LIABLE TO ANY PARTY FOR
% DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING LOST
% PROFITS, ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF
% THE THE HEBREW UNIVERSITY OF JERUSALEM HAS BEEN ADVISED OF THE POSSIBILITY OF
% SUCH DAMAGE. THE HEBREW UNIVERSITY OF JERUSALEM SPECIFICALLY DISCLAIMS ANY
% WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
% MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. THE SOFTWARE PROVIDED
% HEREUNDER IS ON AN "AS IS" BASIS, AND THE HEBREW UNIVERSITY OF JERUSALEM HAS NO
% OBLIGATIONS TO PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR
% MODIFICATIONS.
