/**
   =====================================================================

   Author: Ofir Pele

   Email: ofirpele@cs.huji.ac.il

   ======================================================================
*/

#ifndef __IMAGES_NAMES_DIRECTORY__H
#define __IMAGES_NAMES_DIRECTORY__H


#include <fnmatch.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string> // field
#include <iostream>
//using namespace std;

/*******************************************************************
 This class implements an iterator that returns the names of 
 images file names in a given directory
********************************************************************/
class images_names_directory {
	
      
      std::string _dir_path;
      
      bool _found_image_file_name;
      
      struct dirent **_name_list;
      
      int _num_of_files_left;
      int _total_num_of_files;
      
      std::string _full_file_name;
      
      
      
      /*
	----------------------------------
	finds next file name 
	----------------------------------
      */
      void find_next_file_name() {
	    
	    _found_image_file_name= false;
	    while (_num_of_files_left>0) {
		  
		  --_num_of_files_left;
		  
		  _full_file_name=_dir_path;
		  _full_file_name+= "/";
		  _full_file_name+= _name_list[_num_of_files_left]->d_name;
		  
		  struct stat curr_file_buf;
		  stat(_full_file_name.c_str(),&curr_file_buf);
		  
		  
		  // check that it regular file and that it does not start with .
		  // and that it's an image type
		  if ( (S_ISREG(curr_file_buf.st_mode))&&
		       ((_name_list[_num_of_files_left]->d_name)[0]!='.')&&
		       (
			(!fnmatch("*.ppm",_name_list[_num_of_files_left]->d_name,FNM_CASEFOLD))||
			(!fnmatch("*.pgm",_name_list[_num_of_files_left]->d_name,FNM_CASEFOLD))||
			(!fnmatch("*.bmp",_name_list[_num_of_files_left]->d_name,FNM_CASEFOLD))||
			(!fnmatch("*.gif",_name_list[_num_of_files_left]->d_name,FNM_CASEFOLD))||
			(!fnmatch("*.jpeg",_name_list[_num_of_files_left]->d_name,FNM_CASEFOLD))||
			(!fnmatch("*.jpg",_name_list[_num_of_files_left]->d_name,FNM_CASEFOLD))||
			(!fnmatch("*.JPG",_name_list[_num_of_files_left]->d_name,FNM_CASEFOLD))||
            (!fnmatch("*.png",_name_list[_num_of_files_left]->d_name,FNM_CASEFOLD))||
			(!fnmatch("*.tiff",_name_list[_num_of_files_left]->d_name,FNM_CASEFOLD))
			)
		       ) {

			
			_found_image_file_name= true;
			return;
		  }
		  
	    } // while _num_of_files_left
	    return;
	    
	    
	    
      } // end find_next_file_name
      
 public:
	
      
      /**
	 ------------------------------------------------
	 Ctor
	 ------------------------------------------------
      */
      images_names_directory(const char* dir_path) :
	    _dir_path(dir_path) {
		  
	    _num_of_files_left= scandir(dir_path, &_name_list, 0, alphasort);
	    _total_num_of_files= _num_of_files_left;
		  
	    // find first image file name
	    find_next_file_name();
		  
      } // end Ctor
		  
	    /**
	       ------------------------------------------------
	       Dtor
	       ------------------------------------------------
	    */
	    ~images_names_directory() {
		  for (int i=0; i< _total_num_of_files; ++i) {
			free(_name_list[i]);
		  }
		  free(_name_list);
	    }

	    /**
	       ------------------------------------
	       returns the next file name if 
	       there is one.


	       ------------------------------------
	    */
	    std::string next_file_name() {
	       
		  std::string file_name= _full_file_name;
		  find_next_file_name();
		  return file_name;
	    }
		
	    /**
	       ------------------------------------
	       returns if there is more file names
	       ------------------------------------
	    */
	    bool there_is_more_images_file_names() {
		  return _found_image_file_name;
	    }


};
#endif
/*******************************************************************
         EOF
*******************************************************************/


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
