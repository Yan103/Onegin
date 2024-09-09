#include "files_input_output.h"

#include <stdio.h>
#include "return_codes.h"
#include "color_printf.h"


int file_input(const char* filename, char text[STR_COUNT][STR_LENGHT], char* text_ptr[], int str_lenght, int str_count) {
    FILE *text_input_file = fopen(filename, "r");

    if (!text_input_file) {
        printf(RED("Error occured while opening file\n"));

        return FILE_ERROR;
    }

    for (int i = 0; i < str_count; i++) {
        fgets(text[i], str_lenght, text_input_file);
        text_ptr[i] = &text[i][0];
    }

    fclose(text_input_file);

    return SUCCESS;
}

int file_output(const char* filename, char* text_ptr[]) {
    FILE *text_output_file = fopen(filename, "w");

    if (!text_output_file) {
        printf(RED("Error occured while opening file\n"));

        return FILE_ERROR;
    }

    for (int i = 0; i < STR_COUNT; i++) {
        fputs(text_ptr[i], text_output_file);
    }

    printf(GREEN("SUCCESS!!!\n"));
    fclose(text_output_file);

    return SUCCESS;
}
