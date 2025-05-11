#ifndef __STATISTICS_MAKER__H
#define __STATISTICS_MAKER__H

/********************************************************
 includes
********************************************************/

#include <cmath> // for sqrt



/**
====================================================================
 The class makes statistics on numbers entered into it.
====================================================================
*/
class StatisticsMaker {
    
    // field
    double _num_elements;
    double _sum;
    double _sum_elements_pow_2;
    

public:
    
    
    /**
      ---------------------------------------------
       Ctor which makes an empty StatisticsMaker. 
       i.e: No elements at all
      ---------------------------------------------
    */
    StatisticsMaker():_num_elements(0),_sum(0),_sum_elements_pow_2(0){
    }
    
    
    
    
    /**
      ---------------------------------------------
       Add one element.
      ---------------------------------------------
    */  
    void update(const double& elem) {
    
        // num of elems
        ++_num_elements;
        
        // avg
        _sum+= elem;
        
        // sd
        _sum_elements_pow_2+= elem*elem;
        
    
    } // end update
//    
//    /**
//      ---------------------------------------------
//       Clears everything. i.e: Sets everything to 0
//      ---------------------------------------------
//    */
//    void clear() {
//        mpq_set_d(_num_elements,0);
//        mpq_set_d(_sum,0);
//        mpq_set_d(_sum_elements_pow_2,0);
//    } // end clear

    /**
      ---------------------------------------------
       Returns the average 
       If no update was called returns 0
      ---------------------------------------------
    */  
    double avg() {
        
        if (_num_elements==0) return 0;
        
        return _sum/_num_elements;
        
    }


    /**
      ---------------------------------------------
       Returns the sd
      ---------------------------------------------
    */  
    double sd() {
        
        //     sqrt(           E[x^2]                    -   (E[X])^2) 
        return sqrt( (_sum_elements_pow_2/_num_elements) - (avg()*avg())   );
    
    } // end sd

    

}; // end StatisticsMaker
#endif /*STATISTICSMAKER_H_*/


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
