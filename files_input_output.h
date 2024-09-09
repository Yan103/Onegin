#ifndef FILES_INPUT_OUTPUT_H
#define FILES_INPUT_OUTPUT_H

#include <stdio.h>

const int   STR_COUNT        = 28;
const int   STR_LENGHT       = 50;

int file_input(const char* filename, char text[STR_COUNT][STR_LENGHT], char* text_ptr[], int str_lenght, int str_count);
int file_output(const char* filename, char* text_ptr[]);


#endif // FILES_INPUT_OUTPUT_H