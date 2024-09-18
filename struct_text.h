/*!
    \file
    File with the declaration of the struct Text (full information about Onegin)
*/

#ifndef STRUCT_TEXT_H
#define STRUCT_TEXT_H

#include <stdio.h>

struct str_info {
    char* text_start;
    char*   text_end;
};

/// The struct Text (full information about Onegin)
struct Text {
    char*             buffer_ptr;
    str_info*           text_ptr;
    int              lines_count;
    int             file_symbols;
    const char*  file_input_name;
    const char* file_output_name;
};

#endif //STRUCT_TEXT_H