/*!
    \file
    File with the MY function, what implement <string.h> functions
*/

#ifndef MY_STRING_H
#define MY_STRING_H

#include <stdio.h>

/*!
    The function what return the lenght of the string
    \param [in] string - the pointer on start of the string
*/
int my_strlen(const char* string);

/*!
    The function what compare two strings
    \param [in]  first_string - the pointer on start of the first string
    \param [in] second_string - the pointer on start of the second string
*/
int my_strcmp(const char* first_string, const char* second_string);

/*!
    The function what copy the copy_string to copyed_string
    \param [out] copyed_string - the pointer on string where will copy the copyed_string
    \param [in]    copy_string - the pointer on string what will be copy
*/
char* my_strcpy(char* copyed_string, const char* copy_string);

/*!
    The function what attach the copy_string to determinate_string
    \param [out]  determinate_string - the pointer on string where will be attach the copy_string
    \param  [in]         copy_string - the pointer on string what will be copy
*/
char* my_strcat(char* determinate_string, const char* copy_string);

/*!
    The function what compare two strings
    \param [in]  first_string - the pointer on start of the first string
    \param [in] second_string - the pointer on start of the second string
*/
int reversed_strcmp(const char* first_string, const char* second_string);

#endif // MY_STRING_H
