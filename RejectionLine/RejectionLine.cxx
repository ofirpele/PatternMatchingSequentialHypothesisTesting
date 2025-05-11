#include "OP_utils.hpp"
#include "RejectionLine.hpp"

#ifndef MATLAB_MEX_FILE
#define MATLAB_MEX_FILE
#endif


void mexFunction(int nout, mxArray *out[],
                 int nin, const mxArray *in[]) {
    
    //==================================================================================
    enum { VEC_SIZE_IND,
           MAX_DIFF_IND,
           FALSE_NEGATIVE_IND,
           PRIOR_IND,
           NUM_INPUT};
    
    enum { REJECTION_LINE_IND };
    //==================================================================================
    

    //==================================================================================
    const int vecSize= *(static_cast<const double*>((mxGetData(in[VEC_SIZE_IND]))));
    // Following checks that we really got an integer number
    mc_assert_eq( vecSize , *(static_cast<const double*>((mxGetData(in[VEC_SIZE_IND])))) );

    const double falseNegative= *(static_cast<const double*>((mxGetData(in[FALSE_NEGATIVE_IND]))));

    const double maxDiff= *(static_cast<const double*>((mxGetData(in[MAX_DIFF_IND]))));
    //==================================================================================

    
    //==================================================================================
    mwIndex rejectLineDims[]= {vecSize};
    out[REJECTION_LINE_IND]= mxCreateNumericArray(1, rejectLineDims, mxDOUBLE_CLASS, mxREAL);
    double* rejectLine= static_cast<double*>(mxGetData(out[REJECTION_LINE_IND]));
    //==================================================================================

    
    //==================================================================================
    RejectionLine rg;
    if (nin==NUM_INPUT) {
        const double* prior= static_cast<const double*>((mxGetData(in[PRIOR_IND])));
        rg.sprtRejectionLineGivenPrior(prior,
                                       vecSize,
                                       falseNegative,
                                       maxDiff,
                                       rejectLine);
    } else {
        mc_assert_eq( nin , NUM_INPUT-1 );
        rg.sprtRejectionLineUniformPrior(vecSize,
                                         falseNegative,
                                         maxDiff,
                                         rejectLine);
    }
    //==================================================================================

    
} // end mexFunction

// Copyright (c) 2011, Ofir Pele
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

