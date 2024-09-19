/*!
    \file
    File with the read file function
*/

#ifndef BASE_FUNCTIONS_H
#define BASE_FUNCTIONS_H

#include <stdio.h>

#include "struct_text.h"

/*!
    The function what read text from file
    \param [out] onegin_ptr - the pointer on struct with info about Onegin
*/
int read_text_from_file(Text* onegin_ptr);

/*!
    The function what sorts the strings and writes them to a file
    \param [in]  onegin_ptr - the pointer on struct with info about Onegin
*/
int onegin_sort(Text* onegin_ptr);

#endif //BASE_FUNCTIONS_H