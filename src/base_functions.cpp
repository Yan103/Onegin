/*!
    \file
    File with the read file function
*/

#include <stdlib.h>
#include <sys/stat.h>

#include "base_functions.h"
#include "files_input_output.h"
#include "memory_fill.h"
#include "my_assert.h"
#include "my_sort.h"
#include "return_codes.h"

/*!
    The function what read text from file
    \param [out] onegin_ptr - the pointer on struct with info about Onegin
*/
int read_text_from_file(Text* onegin_ptr) {
    ASSERT(onegin_ptr != NULL, ERR_MSG_NULL_PTR);

    FILE *text_input_file = fopen(onegin_ptr->file_input_name, "r");

    if (!text_input_file) {
        printf(RED("Error occured while opening file\n"));

        return FILE_ERROR;
    }

    size_t file_lenght = onegin_info_fill(onegin_ptr, text_input_file);

    //* -------IMPORTANT-------*
    //* the first element in the buffer with the original text is '\0'
    //* this is done so that the reverse comparator can recognize the end of the first line
    //* if the file starts with an empty line, it will be ignored
    //* for these reasons, the next cycle starts exactly with 1
    //* -----END-IMPORTANT-----*

    int j = 0;
    for (size_t i = 1; i < file_lenght - onegin_ptr->lines_count; i++) {
        if (onegin_ptr->buffer_ptr[i - 1] == '\0') {
            onegin_ptr->text_ptr[j].text_start = &onegin_ptr->buffer_ptr[i];
        }
        if (onegin_ptr->buffer_ptr[i + 1] == '\n') {
            onegin_ptr->text_ptr[j].text_end = &onegin_ptr->buffer_ptr[i];
            onegin_ptr->buffer_ptr[i + 1] = '\0';
            j++;
        }
    }

    fclose(text_input_file);

    return SUCCESS;
}

/*!
    The function what sorts the strings and writes them to a file
    \param [in]  onegin_ptr - the pointer on struct with info about Onegin
*/
int onegin_sort(Text* onegin_ptr) {
    ASSERT(onegin_ptr != NULL, ERR_MSG_NULL_PTR);

    FILE *text_output_file = fopen(onegin_ptr->file_output_name, "w");

    if (!text_output_file) {
        printf(RED("Error occured while opening file\n"));

        return FILE_ERROR;
    }

    my_comp_type comp_sort_string          = struct_comp_sort;
    my_comp_type comp_reversed_string_sort = struct_comp_reverse;

    my_quick_sort((void*)onegin_ptr->text_ptr, 0, (int)onegin_ptr->lines_count, sizeof(str_info), comp_sort_string);
    //!my_sort((void*)onegin_ptr->text_ptr, onegin_ptr->lines_count, sizeof(str_info), comp_sort_string);
    file_output(text_output_file, onegin_ptr->text_ptr, onegin_ptr->lines_count);

    my_quick_sort((void*)onegin_ptr->text_ptr, 0, (int)onegin_ptr->lines_count, sizeof(str_info), comp_reversed_string_sort);
    //!my_sort((void*)onegin_ptr->text_ptr, onegin_ptr->lines_count, sizeof(str_info), comp_reversed_string_sort);
    file_reversed_output(text_output_file, onegin_ptr->text_ptr, onegin_ptr->lines_count);

    //!my_sort((void*)onegin_ptr->text_ptr, onegin_ptr->lines_count, sizeof(str_info), correct_cmp_reverse);

    write_original_text(text_output_file, onegin_ptr->buffer_ptr, onegin_ptr->file_symbols);

    fclose(text_output_file);

    printf(GREEN("SUCCESSFUL REWRITE ONEGIN!!!\n"));

    FREE(onegin_ptr->buffer_ptr);
    FREE(onegin_ptr->text_ptr);

    return SUCCESS;
}
