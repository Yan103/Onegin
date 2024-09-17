/*!
    \file
    File with the read file function
*/

#include "main_functions.h"

#include <stdlib.h>
#include <sys/stat.h>

#include "files_input_output.h"
#include "memory_fill.h"
#include "my_assert.h"
#include "return_codes.h"

/*!
    The function what read text from file
    \param [out] onegin_ptr - the pointer on struct with info about Onegin
*/
void read_text_from_file(Text* onegin_ptr) {
    ASSERT(onegin_ptr != NULL, "Null pointer was passed");

    size_t file_lenght = onegin_info_fill(onegin_ptr);

    int j = 0;
    for (size_t i = 1; i < file_lenght - onegin_ptr->lines_count; i++) {
        if (onegin_ptr->buffer_ptr[i - 1] == '\0') {
            onegin_ptr->text_start_ptr[j] = &onegin_ptr->buffer_ptr[i];
        }
        if (onegin_ptr->buffer_ptr[i + 1] == '\n') {
            onegin_ptr->text_end_ptr[j] = &onegin_ptr->buffer_ptr[i];
            onegin_ptr->buffer_ptr[i + 1] = '\0';
            j++;
        }
    }
}

/*!
    The function what write sorted and original texts to file
    \param [in]  onegin_ptr - the pointer on struct with info about Onegin
*/
int write_test_to_file(Text* onegin_ptr){
    ASSERT(onegin_ptr != NULL, "Null pointer was passed");

    FILE *text_output_file = fopen(onegin_ptr->file_output_name, "w");

    if (!text_output_file) {
        printf(RED("Error occured while opening file\n"));

        return FILE_ERROR;
    }

    file_output(text_output_file, onegin_ptr->text_start_ptr, onegin_ptr->lines_count);

    file_reversed_output(text_output_file, onegin_ptr->text_end_ptr, onegin_ptr->lines_count);

    write_original_text(text_output_file, onegin_ptr->buffer_ptr, onegin_ptr->file_symbols);

    fclose(text_output_file);

    printf(GREEN("SUCCESSFUL REWRITE ONEGIN LINES IN 3 MODES!!!\n"));

    FREE(onegin_ptr->buffer_ptr);
    FREE(onegin_ptr->text_start_ptr);
    FREE(onegin_ptr->text_end_ptr);

    return SUCCESS;
}
