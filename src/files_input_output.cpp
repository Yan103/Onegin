/*!
    \file
    File with the input/output function
*/

#include <stdio.h>

#include "color_printf.h"
#include "files_input_output.h"
#include "my_assert.h"
#include "return_codes.h"
#include "struct_text.h"

/*!
    The function what read text from file
    \param  [in]    filename - the name of file to input
    \param [out]     arr_ptr - pointer to the buffer for original text
    \param  [in] file_lenght - the lenght of file
*/
size_t file_input(FILE* filename, char* arr_text, size_t file_lenght) {
    ASSERT(filename != NULL, ERR_MSG_NULL_PTR);
    ASSERT(arr_text != NULL, ERR_MSG_NULL_PTR);

    *arr_text++ = '\0';

    size_t fread_result = fread(arr_text, sizeof(char), file_lenght, filename);
    ASSERT(fread_result <= file_lenght, "Memory error!");

    //* -------IMPORTANT-------*
    //* the first element in the buffer with the original text is '\0'
    //* this is done so that the reverse comparator can recognize the end of the first line
    //* if the file starts with an empty line, it will be ignored
    //* for these reasons, the next cycle starts exactly with 1

    size_t count_lines = 0;
    for (size_t i = 1; i <= fread_result; i++) if (arr_text[i] == '\n') count_lines++;

    return count_lines;
}

/*!
    The function of displaying text sorted in default mode
    \param [in]    filename - the name of file to output
    \param [in]    text_ptr - pointer to the array with pointers on lines
    \param [in] count_lines - count of the lines
*/
int file_output(FILE* filename, str_info* text_ptr, size_t count_lines) {
    ASSERT(filename != NULL, ERR_MSG_NULL_PTR);
    ASSERT(text_ptr != NULL, ERR_MSG_NULL_PTR);

    fputs("DEFAULT SORTED ONEGIN TEXT:\n", filename);

    for (size_t i = 0; i < count_lines; i++) {
        fputs(text_ptr[i].text_start, filename);
        fputc('\n', filename);
    }
    fputc('\n', filename);

    return SUCCESS;
}

/*!
    The function of displaying text sorted in reverse mode
    \param [in]    filename - the name of file to output
    \param [in]    text_ptr - pointer to the array with pointers on lines
    \param [in] count_lines - count of the lines
*/
int file_reversed_output(FILE* filename, str_info* text_ptr, size_t count_lines) {
    ASSERT(filename != NULL, ERR_MSG_NULL_PTR);
    ASSERT(text_ptr != NULL, ERR_MSG_NULL_PTR);

    fputs("REVERSED SORTED ONEGIN TEXT:\n", filename);

    for (size_t i = 0; i < count_lines; i++) {
        while (*text_ptr[i].text_end) { *text_ptr[i].text_end--; }
        *text_ptr[i].text_end++;
        fputs(text_ptr[i].text_end, filename);
        fputc('\n', filename);
    }
    fputc('\n', filename);

    return SUCCESS;
}

/*!
    The function of displaying original text
    \param [in]     filename - the name of file to output
    \param [in]      arr_ptr - pointer to the array with original text
    \param [in] file_symbols - count of the symbols in file
*/
int write_original_text(FILE* filename, char* arr_text, size_t file_symbols) {
    ASSERT(filename != NULL, ERR_MSG_NULL_PTR);
    ASSERT(arr_text != NULL, ERR_MSG_NULL_PTR);

    fputs("ORIGINAL ONEGIN TEXT:\n", filename);

    for (size_t i = 1; i < file_symbols; i++) {
        if (arr_text[i] == '\0') fputc('\n', filename);
        else fputc(arr_text[i], filename);
    }
    fputc('\n', filename);

    return SUCCESS;
}
