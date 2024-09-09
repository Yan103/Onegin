#include <stdio.h>
#include <stdlib.h>

#include "my_string.h"
#include "color_printf.h"
#include "return_codes.h"
#include "my_sort.h"

const char* filename   = "text.txt";
const int   STR_COUNT  = 14;
const int   STR_LENGHT = 50;

int main() {
    FILE *text_file = fopen(filename, "r");

    if (!text_file) {
        printf(RED("Error occured while opening file\n"));

        return FILE_ERROR;
    }

    char  text[STR_COUNT][STR_LENGHT] = {};
    char* text_ptr[STR_COUNT]         = {};

    for (int i = 0; i < STR_COUNT; i++) {
        fgets(text[i], STR_LENGHT, text_file);
        text_ptr[i] = &text[i][0];
    }
    printf("!\n");

    for (int i = 0; i < STR_COUNT; i++) {
        printf("%s", text_ptr[i]);
    }
    printf("--------------------\n");

    bubbleSort(text_ptr, STR_COUNT);

    for (int i = 0; i < STR_COUNT; i++) {
        printf("%s", text_ptr[i]);
    }
    printf("--------------------\n");

    /* const char* s1 = "\"ABC\"";
    const char* s2 = "ABC";
    printf("%d", my_strcmp(s1, s2)); */

    return 0;
}
