/*!
    \file
    File with the input/output function
*/

#include "files_input_output.h"

#include <stdio.h>

#include "color_printf.h"
#include "my_assert.h"
#include "return_codes.h"
#include "struct_text.h"

/*!
    The function what read text from file
    \param  [in]    filename - the name of file to input
    \param [out]     arr_ptr - pointer to the buffer for original text
    \param  [in] file_lenght - the lenght of file
*/
int file_input(const char* filename, char* arr_text, size_t file_lenght) {
    ASSERT(filename != NULL, "Null pointer was passed");
    ASSERT(arr_text != NULL, "Null pointer was passed");

    FILE *text_input_file = fopen(filename, "r");

    if (!text_input_file) {
        printf(RED("Error occured while opening file\n"));

        return FILE_ERROR;
    }

    *arr_text++ = '\0';

    size_t result = fread(arr_text, sizeof(char), file_lenght, text_input_file);
    ASSERT(result <= file_lenght, "Memory error!");

    int count_lines = 0;
    for (size_t i = 1; i <= result; i++) if (arr_text[i] == '\n') count_lines++;

    return count_lines;
}

/*!
    The function of displaying text sorted in default mode
    \param [in]    filename - the name of file to output
    \param [in]    text_ptr - pointer to the array with pointers on lines
    \param [in] count_lines - count of the lines
*/
void file_output(FILE* filename, str_info* text_ptr, int count_lines) {
    ASSERT(filename != NULL, "Null pointer was passed");
    ASSERT(text_ptr != NULL, "Null pointer was passed");

    fputs("Default sorted Onegin text:\n", filename);

    for (int i = 0; i < count_lines; i++) {
        fputs(text_ptr[i].text_start, filename);
        fputc('\n', filename);
    }
    fputc('\n', filename);
}

/*!
    The function of displaying text sorted in reverse mode
    \param [in]    filename - the name of file to output
    \param [in]    text_ptr - pointer to the array with pointers on lines
    \param [in] count_lines - count of the lines
*/
void file_reversed_output(FILE* filename, str_info* text_ptr, int count_lines) {
    ASSERT(filename != NULL, "Null pointer was passed");
    ASSERT(text_ptr != NULL, "Null pointer was passed");

    fputs("Reversed sorted Onegin text:\n", filename);

    for (int i = 0; i < count_lines; i++) {
        while (*text_ptr[i].text_end) { *text_ptr[i].text_end--; }
        *text_ptr[i].text_end++;
        fputs(text_ptr[i].text_end, filename);
        fputc('\n', filename);
    }
    fputc('\n', filename);
}

/*!
    The function of displaying original text
    \param [in]     filename - the name of file to output
    \param [in]      arr_ptr - pointer to the array with original text
    \param [in] file_symbols - count of the symbols in file
*/
void write_original_text(FILE* filename, char* arr_text, int file_symbols) {
    ASSERT(filename != NULL, "Null pointer was passed");
    ASSERT(arr_text != NULL, "Null pointer was passed");

    fputs("Original Onegin text:\n", filename);

    for (int i = 1; i < file_symbols; i++) {
        if (arr_text[i] == '\0') fputc('\n', filename);
        else fputc(arr_text[i], filename);
    }
}
