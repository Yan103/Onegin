/*!
    \file
    File with the main function
*/

#include <stdio.h>
#include <unistd.h>

#include "base_functions.h"
#include "color_printf.h"
#include "my_assert.h"
#include "return_codes.h"
#include "struct_text.h"
#include "terminal_calls.h"

/*!
    The main function
    \param [in] argc - number of command line arguments
    \param [in] argv - command line arguments
    \return Returns the status of the main program execution
*/
int main(const int argc, char* const *argv) {
    ASSERT(argv != nullptr, ERR_MSG_NULL_PTR);

    Text onegin = {.file_output_name = FILE_OUTPUT_NAME};

    int          opt = 0;
    int    have_args = 0;
    int  read_status = 0;

    while((opt = getopt(argc, argv, "fhc")) != -1) {
        have_args = true;
        switch (opt) {
            case 'h':
                printf(YELLOW("%s"), HELP_TEXT);

                return SUCCESS;

            case 'f':
                if (argc == 3) {
                    onegin.file_input_name = argv[2];
                    read_status = read_text_from_file(&onegin);
                } else {
                    printf(RED("Your file has not been found! The standard text file (%s) is launched:\n"),
                                                                                      FILE_INPUT_NAME);
                    onegin.file_input_name = FILE_INPUT_NAME;
                    read_text_from_file(&onegin);
                    read_status = SUCCESS;
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
        printf(BLUE("Command line arguments are not received, default file (%s) are launched\n"), FILE_INPUT_NAME);
        onegin.file_input_name  = FILE_INPUT_NAME;
        read_text_from_file(&onegin);
        read_status = SUCCESS;
    }

    if (read_status == SUCCESS) onegin_sort(&onegin);

    return SUCCESS;
}
