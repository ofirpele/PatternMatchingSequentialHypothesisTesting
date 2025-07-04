#ifndef OP_UTILS_HPP_
#define OP_UTILS_HPP_

#include <math.h>

//====================================================
// Assert
//====================================================
#ifdef MATLAB_MEX_FILE
#include <mex.h>
#else
#include <cassert>
#endif

// Note: In MATLAB_MEX_FILE mxAssert is active ONLY when -g is active
// Note: assert is active ONLY if NDEBUG is not defined

#ifdef MATLAB_MEX_FILE
#define mc_assert(expr) mxAssert((expr),"")
#else
#define mc_assert(expr) assert((expr))
#endif

#define ASSERT_EQUAL_EPSILON 0.0001

#ifdef MATLAB_MEX_FILE
#define mc_assert_eq(a,b) mxAssert((fabs((a)-(b)))<ASSERT_EQUAL_EPSILON,"")
#else
#define mc_assert_eq(a,b) assert((fabs((a)-(b)))<ASSERT_EQUAL_EPSILON)
#endif

#ifdef MATLAB_MEX_FILE
#define mc_assert_geq(a,b) mxAssert((a)>=((b)-ASSERT_EQUAL_EPSILON),"")
#else
#define mc_assert_geq(a,b) assert((a)>=((b)-ASSERT_EQUAL_EPSILON))
#endif
//====================================================

#endif



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
