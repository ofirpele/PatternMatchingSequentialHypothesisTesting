#ifndef _TRANDOMA_NUMBER_GENERATOR
#define _TRANDOMA_NUMBER_GENERATOR

#include <sys/time.h>
#include <time.h>

#include "GlobalRandsArr.h"
   
/// A functor in the concept of std Random Number Generator that uses boost
class TRandomaNumberGenerator {
public:
    
    /// Ctor that seeds randomality by time in microseconds since Epoch (see gettimeofday).
    /// operator () will return an integer less than N and greater than or equal to 0.
    TRandomaNumberGenerator(int N, int seed = -1) {
        
        assert(N!=0);
        if (N<=0) {
            return;
        }
        
        if (seed==-1) {
            timeval tv; 
            gettimeofday(&tv,NULL);
            seed= tv.tv_sec*1000 + tv.tv_usec;
        }
        _curr_place_in_rands_arr= seed % Global_rands_arr_len;
        
        for (unsigned int i= 0; i< Global_rands_arr_len; ++i) {
            // This is supposed to be more random but then I'll need to cast to double rand_max_p1 - less efficient
            //return ( (N-1) * (rands_arr[i] / rands_max_p1));
            _my_rands_arr[i]= Global_rands_arr[i] % N;
        }
        
    } // Ctor
    
    
    /// 
    int operator()() {
        
        ++_curr_place_in_rands_arr;
        // TODO: add here assertion that size of array is 2^N
	// Then & with Global_rands_arr_len_m1 is the same as modulo Global_rands_arr_len
        _curr_place_in_rands_arr= _curr_place_in_rands_arr & Global_rands_arr_len_m1;
                
        return _my_rands_arr[_curr_place_in_rands_arr];
    }
    
private:
     
     int _curr_place_in_rands_arr;
     int _my_rands_arr[Global_rands_arr_len];

};

//#include <gmp.h>
//
///// A functor in the concept of std Random Number Generator that uses boost
//class TRandomaNumberGenerator {
//public:
//    
//    /// Ctor that seeds randomality by time in microseconds since Epoch (see gettimeofday).
//    TRandomaNumberGenerator() {
//        timeval tv;
//        gettimeofday(&tv,NULL);
//        unsigned int seed= tv.tv_sec*1000 + tv.tv_usec;
//        gmp_randinit_mt (_state);   
//        gmp_randseed_ui (_state, seed);
//    }
//    
//    
//    /// Returns an integer less than N and greater than or equal to 0.
//    int operator()(int N) {
//        return gmp_urandomm_ui(_state, N);
//    }
//private:
//gmp_randstate_t _state;
//   
//};



//#include <boost/random/uniform_int.hpp>
//#include <boost/random/mersenne_twister.hpp>
//#include <boost/random/variate_generator.hpp>
//#include <boost/random/linear_congruential.hpp>
//
///// A functor in the concept of std Random Number Generator that uses boost
//class TRandomaNumberGenerator {
//public:
//    
//    /// Ctor that seeds randomality by time in microseconds since Epoch (see gettimeofday).
//    TRandomaNumberGenerator() {
//        timeval tv;
//        gettimeofday(&tv,NULL);
//        unsigned int seed= tv.tv_sec*1000 + tv.tv_usec;
//        _rng.seed(seed);
//    }
//    
//    /// Ctor that seeds randomality.
//    /// \param seed - the given seed.
//    TRandomaNumberGenerator(unsigned int seed) {
//        _rng.seed(seed);
//    }
//    
//    /// Returns an integer less than N and greater than or equal to 0.
//    int operator()(int N) {
//        typedef boost::uniform_smallint<> NUMS_T;
//        NUMS_T nums(0,N-1);    
//        boost::variate_generator<GEN_T&, NUMS_T >
//           die(_rng, nums);  
//        return die();
//    }
//private:
//    typedef boost::mt19937 GEN_T;
//    GEN_T _rng;
//};


//#include <randoma/randoma.h>
//
//#include <sys/time.h>
//#include <time.h>
//
//
//
///// A functor in the concept of std Random Number Generator that uses the Mersenne Twister algorithm as was implemented in the randoma library.
//class TRandomaNumberGenerator {
//public:
//    
//    /// Ctor that seeds randomality by time in microseconds since Epoch (see gettimeofday).
//    TRandomaNumberGenerator() {
//    	timeval tv;
//    	gettimeofday(&tv,NULL);
//        int seed= tv.tv_sec*1000 + tv.tv_usec;
//        //cerr << seed << endl;
//        TRandomInit(seed);
//    }
//    
//    /// Ctor that seeds randomality.
//    /// \param seed - the given seed.
//	TRandomaNumberGenerator(int seed) {
//        TRandomInit(seed);
//    }
//    
//    /// Returns an integer less than N and greater than or equal to 0.
//    int operator()(int N) const {
//        return TIRandom (0, N-1);
//    }
//        
//};

#endif


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
