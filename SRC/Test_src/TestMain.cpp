/**
=========================================================================

 * Excerise: bioinformatics project

 * Writer's login + name + id: yevgenyd, Yevgeny Doctor, 31068165-5
                               eranm13,  Eran Maryuma  , 03148970-1
			       ofirpele, Ofir Pele, 034089300

=========================================================================
*/

//#define _GLIBCXX_CONCEPT_CHECKS

// NOTICE: here add all the tests files 
// #include "Test_$$$.h"
//---------------------------------------
#include "Test_DiffAbs_IsSimilar_uchar.h"
#include "Test_MasksMakers.h"
#include "Test_ExactFastMatcher.h"
#include "Test_PairsGt_IsSimilar_uchar.h"
#include "Test_SeqFastMatcher.h"
#include "Test_MakePairsMask.h"
//---------------------------------------

// used namespace:
using namespace Tests;

/**
-----------------------------------------
 main function that runs all tests
-----------------------------------------
*/
int main() { 
      
      // the tests classes to use:
      typedef vector<TestRunner*> tests_list;
      tests_list tests;
      
      // moves some lines and  
      cerr<<endl<<endl<<endl;
      
      // NOTICE: here add all your tests
      // write:
      // Test_$$$ t_num; tests.push_back(&t_num);
      //--------------------------------------------
      Test_DiffAbs_IsSimilar_uchar t_1; tests.push_back(&t_1);
      Test_MasksMakers             t_2; tests.push_back(&t_2);
      Test_ExactFastMatcher        t_3; tests.push_back(&t_3);
      Test_PairsGt_IsSimilar_uchar t_4; tests.push_back(&t_4);
      Test_SeqFastMatcher          t_5; tests.push_back(&t_5);
      ::Test_MakePairsMask           t_6; tests.push_back(&t_6);
      //--------------------------------------------
      
      // runs the tests:
      for (tests_list::iterator i=tests.begin(); i<tests.end(); ++i)
     {
	(*i)->run();
     }
      
      // write how much tests files were
      cout << "\033[1;32m";
      cout << tests.size() << " Tests files were done" << endl;
      cout << TestRunner::_num_funcs_run << " Tests functions were done"<<endl;
      cout << "\033[0;39m";
      return 0;
}



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
