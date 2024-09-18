/*!
    \file
    File with functions, what sort onegin lines
*/

#ifndef MY_SORT_H
#define MY_SORT_H

#include <stdio.h>

#include "my_string.h"
#include "struct_text.h"

/*!
    The function what sort the text lines (using BubbleSort algorithm)
    \param [out]  onegin_ptr - the pointer on struct with info about Onegin
    \param  [in]  comp_func1 - the pointer on first comparate function
    \param  [in]  comp_func2 - the pointer on second comparate function
*/
void my_sort(void* arr, size_t elem_count, size_t elem_size, int (*comp_func)(const void*, const void*));

/*!
    The function what prepare the parametrs (from void*) for launch the default compare function
    \param  [in]  arg1_ptr - the pointer on first argument
    \param  [in]  arg2_ptr - the pointer on second argument
*/
int default_compare(const void* arg1_ptr, const void* arg2_ptr);

int struct_cmp(const void *s1, const void *s2);

/*!
    The function what prepare the parametrs (from void*) for launch the reversed compare function
    \param  [in]  arg1_ptr - the pointer on first comparate function
    \param  [in]  arg2_ptr - the pointer on second comparate function
*/
int reversed_compare(const void* arg1_ptr, const void* arg2_ptr);

/*!
    The function what swap two void* pointer
    \param  [in]   first_ptr - the first pointer
    \param  [in]  second_ptr - the second pointer
    \param [out]   elem_size - the size of elements in pointers
*/
void void_swap(void* first_ptr, void* second_ptr, size_t elem_size);
int struct_cmp_reverse(const void *s1, const void *s2);

//!int partition(void* arr, int start, int end, size_t elem_size, int(*comp_func)(void* p1, void* p2));
//!void my_quick_sort(void* arr, int start, int end, size_t elem_size, int(*comp_func)(void* p1, void* p2));

#endif // MY_SORT_H