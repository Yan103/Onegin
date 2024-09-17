/*!
    \file
    File with the declaration of the struct Text (full information about Onegin)
*/

#ifndef STRUCT_TEXT_H
#define STRUCT_TEXT_H

#include <stdio.h>

/// The struct Text (full information about Onegin)
struct Text {
    char*             buffer_ptr;
    char**        text_start_ptr;
    char**          text_end_ptr;
    int              lines_count;
    int             file_symbols;
    const char*  file_input_name;
    const char* file_output_name;
};

#endif //STRUCT_TEXT_H