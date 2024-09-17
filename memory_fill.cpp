/*!
    \file
    File with the function, what fill memory in struct onegin
*/

#include "memory_fill.h"

#include "files_input_output.h"

/*!
    The function what fill full information about text, what already read
    \param [out]  onegin_ptr - the pointer on struct with info about Onegin
*/
size_t onegin_info_fill(Text *onegin_ptr) {
    ASSERT(onegin_ptr != NULL, "Null pointer was passed");

    struct stat st = {};
    stat(onegin_ptr->file_input_name, &st);
    size_t file_lenght = st.st_size;

    if (file_lenght == 0) {
        onegin_ptr->file_symbols = 0;
        
        return 0;
    }

    onegin_ptr->buffer_ptr = (char*) calloc(file_lenght + 1 + 1 , sizeof(char));
    ASSERT(onegin_ptr->buffer_ptr != NULL, "Memory error!");

    onegin_ptr->lines_count = file_input(onegin_ptr->file_input_name, onegin_ptr->buffer_ptr, file_lenght);

    onegin_ptr->text_start_ptr = (char**) calloc(onegin_ptr->lines_count, sizeof(char*));
    ASSERT(onegin_ptr->text_start_ptr != NULL, "Memory error!");

    onegin_ptr->text_end_ptr = (char**) calloc(onegin_ptr->lines_count, sizeof(char*));
    ASSERT(onegin_ptr->text_end_ptr != NULL, "Memory error!");

    onegin_ptr->file_symbols = (int)(file_lenght - onegin_ptr->lines_count);

    return file_lenght;
}
