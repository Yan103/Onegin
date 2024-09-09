#include "my_string.h"

#include <ctype.h>
#include "my_assert.h"

int my_strlen(const char* string) {
    ASSERT(string != NULL, "Null pointer was passed");

    int str_lenght = 0;
    while (*string++ != '\0') str_lenght++;

    return str_lenght;
}

int my_strcmp(const char* first_string, const char* second_string) {
    ASSERT(first_string  != NULL, "Null pointer was passed");
    ASSERT(second_string != NULL, "Null pointer was passed");

    while(*first_string && (*first_string == *second_string)) {
        
        first_string++;
        second_string++;
    }

    return *first_string - *second_string;
}

char* my_strcat(char* determinate_string, const char* copy_string) {
    ASSERT(determinate_string  != NULL, "Null pointer was passed");
    ASSERT(copy_string         != NULL, "Null pointer was passed");

    char* str_ptr = determinate_string + my_strlen(copy_string);

    while (*copy_string != '\0') *str_ptr++ = *copy_string++;
    *str_ptr = '\0';

    return determinate_string;
}

char* my_strcpy(char* copyed_string, const char* copy_string) {
    ASSERT(copyed_string != NULL, "Null pointer was passed");
    ASSERT(copy_string   != NULL, "Null pointer was passed");

    while ((*copyed_string++ = *copy_string++) != '\0');

    return copyed_string;
}
