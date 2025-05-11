clc; clear all;

% This demo efficiently computes rejection lines as described in section
% 4.4 and algorithm 5 in the paper:
%  Robust Real Time Pattern Matching using Bayesian Sequential Hypothesis Testing
%	 Ofir Pele, Michael Werman
%    PAMI 2008
% Please see RejectionLine.m for more details and documentation.

if (exist('RejectionLine')~=3)
    warning(['RejectionLine compiled function, does not exist. Trying to compile with ' ...
           'compile_all']);
    compile_all;
end

for vecSize= [1000 10000]
    maxDiffPercentage= 20;
    
    % Typical usage
    falseNegativePercentage_a= 0.01;
    tic        
    rejectionLine_a= RejectionLine(vecSize, maxDiffPercentage, falseNegativePercentage_a);
    fprintf('Time for computing rejection line for vecSize==%d is:%f seconds\n',vecSize,toc);
    
    % We increase the chance of falseNegative
    falseNegativePercentage_b= 10;
    rejectionLine_b= RejectionLine(vecSize, maxDiffPercentage, falseNegativePercentage_b);
    % Thus the rejectionLine values should be smaller
    assert(all( rejectionLine_b(:)<=rejectionLine_a(:) ));
        
    % Using unbalanced prior (much more likely to see non-similar), this is
    % typical in pattern matching
    prior= ones(vecSize,1);
    prior(rejectionLine_b(end):end)= 200;
    prior= prior./sum(prior(:));
    rejectionLine_c= RejectionLine(vecSize, maxDiffPercentage, falseNegativePercentage_a, prior);
    % Thus the rejectionLine values should be larger
    assert(all( rejectionLine_c(:)>=rejectionLine_a(:) ));
    
end

scrsz= get(0, 'ScreenSize'); 
figure('Position', [1 scrsz(4) scrsz(3) scrsz(4)]);
plot(rejectionLine_a,'b-');
hold on;
plot(rejectionLine_b,'r--');
hold on;
plot(rejectionLine_c,'g-.');
legend('falseNegativePercentage==0.01, uniform prior',...
       'falseNegativePercentage==10, uniform prior',...
       'falseNegativePercentage==10, unbalanced prior (much more likely to see non-similar)',...
       'Location','NorthWest');

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
