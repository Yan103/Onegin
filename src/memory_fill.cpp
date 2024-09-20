/*!
    \file
    File with the function, what fill memory in struct onegin
*/

#include "memory_fill.h"
#include "files_input_output.h"

/*!
    The function that measures the file size
    \param [out]  onegin_ptr - the pointer on struct with info about Onegin
*/
size_t get_file_info(Text* onegin_ptr) {
    ASSERT(onegin_ptr != NULL, ERR_MSG_NULL_PTR);

    struct stat st = {};
    stat(onegin_ptr->file_input_name, &st);

    return st.st_size;
}

/*!
    The function what fill full information about text, what already read
    \param [out]  onegin_ptr - the pointer on struct with info about Onegin
    \param  [in]    filename - the pointer on struct with info about Onegin
*/
size_t onegin_info_fill(Text *onegin_ptr, FILE* filename) {
    ASSERT(onegin_ptr != NULL, ERR_MSG_NULL_PTR);
    ASSERT(filename   != NULL, ERR_MSG_NULL_PTR);

    size_t file_lenght = get_file_info(onegin_ptr);

    onegin_ptr->buffer_ptr = (char*)(calloc(file_lenght + 1 + 1 , sizeof(char)));
    ASSERT(onegin_ptr->buffer_ptr != NULL, "Memory error!");

    onegin_ptr->lines_count = file_input(filename, onegin_ptr->buffer_ptr, file_lenght);

    onegin_ptr->text_ptr = (str_info*)(calloc(onegin_ptr->lines_count, sizeof(str_info)));
    ASSERT(onegin_ptr->text_ptr != NULL, "Memory error!");

    onegin_ptr->file_symbols = (int)(file_lenght - onegin_ptr->lines_count);

    return file_lenght;
}
