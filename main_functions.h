/*!
    \file
    File with the read file function
*/

#ifndef MAIN_FUNCTIONS_H
#define MAIN_FUNCTIONS_H

#include <stdio.h>

#include "struct_text.h"

/*!
    The function what read text from file
    \param [out] onegin_ptr - the pointer on struct with info about Onegin
*/
void read_text_from_file(Text* onegin_ptr);

/*!
    The function what write sorted and original texts to file
    \param [in]  onegin_ptr - the pointer on struct with info about Onegin
*/
int write_test_to_file(Text* onegin_ptr);

#endif //MAIN_FUNCTIONS_H