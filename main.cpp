#include <stdio.h>
#include <stdlib.h>

#include "my_string.h"
#include "color_printf.h"
#include "return_codes.h"
#include "my_sort.h"
#include "files_input_output.h"

const char* FILE_INPUT_NAME  = "text.txt";
const char* FILE_OUTPUT_NAME = "sorted_text.txt";

int main() {
    char  text[STR_COUNT][STR_LENGHT] = {};
    char* text_ptr[STR_COUNT]         = {};

    file_input(FILE_INPUT_NAME, text, text_ptr, STR_LENGHT, STR_COUNT);

    //!bubble_sort((void**)text_ptr, STR_COUNT, sizeof(char) * STR_LENGHT);

    quick_sort(text_ptr, 0, STR_COUNT - 1, my_strcmp);

    file_output(FILE_OUTPUT_NAME, text_ptr);

    return 0;
}
