clc; close all; clear all;

fn= 'GlobalRandsArr.h';

Global_rands_max= 2^15-1; % Gives better randomization of bits ???
Global_rands_arr_len= 2^15;

rands_arr= floor(Global_rands_max.*rand(Global_rands_arr_len,1));
rands_arr=uint32(rands_arr);

fid= fopen(fn,'wt');
fprintf(fid,'#ifndef _GLOBAL_RANDS_ARR_H \n');
fprintf(fid,'#define _GLOBAL_RANDS_ARR_H \n\n');

fprintf(fid,'const int Global_rands_arr[]= { ');
for i=1:length(rands_arr)-1
	fprintf(fid,'%d,',rands_arr(i));
end
fprintf(fid,'%d };\n',rands_arr(length(rands_arr)));

fprintf(fid,'// Maximum value in array of rands + 1\n');
fprintf(fid,'const int Global_rands_max_p1= %d;\n', Global_rands_max+1);
fprintf(fid,'const unsigned int Global_rands_arr_len= sizeof(Global_rands_arr)/sizeof(Global_rands_arr[0]);\n');
fprintf(fid,'const unsigned int Global_rands_arr_len_m1= Global_rands_arr_len - 1;\n');

fprintf(fid,'#endif\n');
fclose(fid);


% Copyright (c) 2012, Ofir Pele
% All rights reserved.

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are
% met: 
%    * Redistributions of source code must retain the above copyright
%    notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%    notice, this list of conditions and the following disclaimer in the
%    documentation and/or other materials provided with the distribution.
%    * Neither the name of the The Hebrew University of Jerusalem nor the
%    names of its contributors may be used to endorse or promote products
%    derived from this software without specific prior written permission.

% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
% IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
% CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
% EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
% PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
% PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
% LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
% NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
% SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
