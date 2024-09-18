/*!
    \file
    File with the main function
*/

#include <stdio.h>
#include <unistd.h>

#include "color_printf.h"
#include "files_input_output.h"
#include "main_functions.h"
#include "my_assert.h"
#include "my_sort.h"
#include "my_string.h"
#include "return_codes.h"
#include "struct_text.h"
#include "terminal_calls.h"

typedef int (*my_cmp_t) (const void*, const void*);

/*!
    The main function
    \param [in] argc - number of command line arguments
    \param [in] argv - command line arguments
    \return Returns the status of the main program execution
*/
int main(const int argc, char* const *argv) {
    ASSERT(argv != nullptr, "Null pointer was passed");

    Text onegin = {.file_output_name = FILE_OUTPUT_NAME};

    int opt = 0;
    bool have_args = false;

    while((opt = getopt(argc, argv, "fhc")) != -1) {
        have_args = true;
        switch (opt) {
            case 'h':
                printf(YELLOW("%s"), HELP_TEXT);

                return SUCCESS;

            case 'f':
                if (argc == 3) {
                    onegin.file_input_name  = argv[2];
                    read_text_from_file(&onegin);
                } else {
                    printf(RED("Your file has not been found! The standard test file (text.txt) is launched:\n"));
                    onegin.file_input_name  = FILE_INPUT_NAME;
                    read_text_from_file(&onegin);
                }
                break;

            case 'c' :
                printf("%s", CAT);

                return SUCCESS;

            default:
                printf(RED("Flag error!\n"));

                return UNKNOWN_FLAG;
        }
    }

    if (!have_args) {
        printf(BLUE("Command line arguments are not received, default file (text.txt) are launched\n"));
        onegin.file_input_name  = FILE_INPUT_NAME;

        read_text_from_file(&onegin);
    }

    if (onegin.file_symbols == 0) {                 //!
        printf(RED("No founded your file!\n"));

        return FILE_ERROR;
    }

    // int (*string_cmp)(const void*, const void*) = default_compare;
    //my_cmp_t string_cmp  = default_compare;
    my_cmp_t correct_cmp = struct_cmp;
    my_sort((void*)onegin.text_ptr, onegin.lines_count, sizeof(str_info), correct_cmp); //!

    //my_cmp_t correct_cmp_reverse = struct_cmp_reverse;
    //my_sort((void*)onegin.text_ptr, onegin.lines_count, sizeof(str_info), correct_cmp_reverse); //!


    //my_sort((void*)onegin.text_ptr->text_start, onegin.lines_count, sizeof(char*), reversed_compare);

    write_test_to_file(&onegin);

    return SUCCESS;
}
