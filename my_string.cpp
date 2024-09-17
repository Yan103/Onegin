/*!
    \file
    File with the MY function, what implement <string.h> functions
*/

#include "my_string.h"

#include <ctype.h>

#include "my_assert.h"

/*!
    The function what return the lenght of the string
    \param [in] string - the pointer on start of the string
*/
int my_strlen(const char* string) {
    ASSERT(string != NULL, "Null pointer was passed");

    int str_lenght = 0;
    while (*string++ != '\0') str_lenght++;

    return str_lenght;
}

/*!
    The function what compare two strings
    \param [in]  first_string - the pointer on start of the first string
    \param [in] second_string - the pointer on start of the second string
*/
int my_strcmp(const char* first_string, const char* second_string) {
    ASSERT(first_string  != NULL, "Null pointer was passed");
    ASSERT(second_string != NULL, "Null pointer was passed");

    while (*first_string  && isalpha(*first_string)  == 0) first_string++;
    while (*second_string && isalpha(*second_string) == 0) second_string++;

    while(*first_string && (*first_string == *second_string)) {
        first_string++;
        second_string++;

        while (*first_string  && isalpha(*first_string)  == 0) first_string++;
        while (*second_string && isalpha(*second_string) == 0) second_string++;
    }

    return *first_string - *second_string;
}

/*!
    The function what compare two strings
    \param [in]  first_string - the pointer on start of the first string
    \param [in] second_string - the pointer on start of the second string
*/
int reversed_strcmp(const char* first_string, const char* second_string) {
    ASSERT(first_string  != NULL, "Null pointer was passed");
    ASSERT(second_string != NULL, "Null pointer was passed");

    while (*first_string  && isalpha(*first_string)  == 0) first_string--;
    while (*second_string && isalpha(*second_string) == 0) second_string--;

    while(*first_string && (*first_string == *second_string)) {
        first_string--;
        second_string--;

        while (*first_string  && isalpha(*first_string)  == 0) first_string--;
        while (*second_string && isalpha(*second_string) == 0) second_string--;
    }

    return *first_string - *second_string;
}

/*!
    The function what attach the copy_string to determinate_string
    \param [out]  determinate_string - the pointer on string where will be attach the copy_string
    \param  [in]         copy_string - the pointer on string what will be copy
*/
char* my_strcat(char* determinate_string, const char* copy_string) {
    ASSERT(determinate_string  != NULL, "Null pointer was passed");
    ASSERT(copy_string         != NULL, "Null pointer was passed");

    char* str_ptr = determinate_string + my_strlen(copy_string);

    while (*copy_string != '\0') *str_ptr++ = *copy_string++;
    *str_ptr = '\0';

    return determinate_string;
}

/*!
    The function what copy the copy_string to copyed_string
    \param [out] copyed_string - the pointer on string where will copy the copyed_string
    \param [in]    copy_string - the pointer on string what will be copy
*/
char* my_strcpy(char* copyed_string, const char* copy_string) {
    ASSERT(copyed_string != NULL, "Null pointer was passed");
    ASSERT(copy_string   != NULL, "Null pointer was passed");

    while ((*copyed_string++ = *copy_string++) != '\0');

    return copyed_string;
}
