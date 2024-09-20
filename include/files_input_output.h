/*!
    \file
    File with the input/output function
*/

#ifndef FILES_INPUT_OUTPUT_H
#define FILES_INPUT_OUTPUT_H

#include <stdio.h>

#include "my_string.h"
#include "struct_text.h"

/*!
    The function what read text from file
    \param  [in]    filename - the name of file to input
    \param [out]     arr_ptr - pointer to the buffer for original text
    \param  [in] file_lenght - the lenght of file
*/
size_t file_input(FILE* filename, char* arr_text, size_t file_lenght);

/*!
    The function of displaying text sorted in default mode
    \param [in]    filename - the name of file to output
    \param [in]    text_ptr - pointer to the array with pointers on lines
    \param [in] count_lines - count of the lines
*/
int file_output(FILE* filename, str_info* text_ptr, size_t count_lines);

/*!
    The function of displaying original text
    \param [in]     filename - the name of file to output
    \param [in]      arr_ptr - pointer to the array with original text
    \param [in] file_symbols - count of the symbols in file
*/
int write_original_text(FILE* filename, char* arr_text, size_t file_symbols);

/*!
    The function of displaying text sorted in reverse mode
    \param [in]    filename - the name of file to output
    \param [in]    text_ptr - pointer to the array with pointers on lines
    \param [in] count_lines - count of the lines
*/
int file_reversed_output(FILE* filename, str_info* text_ptr, size_t count_lines);

#endif // FILES_INPUT_OUTPUT_H