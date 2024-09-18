/*!
    \file
    File with functions, what sort onegin lines
*/

#include "my_sort.h"

#include <stdlib.h>
#include <string.h>

#include "my_assert.h"
#include "my_string.h"

/*!
    The function what swap two void* pointer
    \param  [in]   first_ptr - the first pointer
    \param  [in]  second_ptr - the second pointer
    \param [out]   elem_size - the size of elements in pointers
*/
void void_swap(void* first_ptr, void* second_ptr, size_t elem_size) {
    ASSERT(first_ptr  != NULL, "Null pointer was passed");
    ASSERT(second_ptr != NULL, "Null pointer was passed");

    void *tmp = calloc(1, elem_size);
    memcpy(tmp, second_ptr, elem_size);
    memcpy(second_ptr, first_ptr, elem_size);
    memcpy(first_ptr, tmp, elem_size);

    FREE(tmp);
}

/*!
    The function what sort the text lines (using BubbleSort algorithm)
    \param [out]  onegin_ptr - the pointer on struct with info about Onegin
    \param  [in]  comp_func1 - the pointer on first comparate function

*/
void my_sort(void* arr, size_t elem_count, size_t elem_size, int (*comp_func)(const void*, const void*)) {
    ASSERT(arr       != NULL, "Null pointer was passed");
    ASSERT(comp_func != NULL, "Null pointer was passed");

    size_t* data = (size_t*)(arr);

    for (size_t i = 0; i < elem_count - 1; i++) {
        for (size_t j = 0; j < elem_count; j++) {
            //printf("%s %s %d\n", *(data + 2 * i), *(data + 2 * j), comp_func((const void*)(*(data + 2 * j)), (const void*)(*(data + 2 * i))));
            //void_swap((void*)(data + 2 * i), (void*)(data + 2 * j), elem_size);
            //printf("----------------------\n");

            if (comp_func((const void*)(*(data + 2 * i)), (const void*)(*(data + 2 * j))) > 0) {
                printf("%s %s %d\n", *(data + 2 * i), *(data + 2 * j), (const void*)(*(data + 2 * i)), (const void*)(*(data + 2 * j)));
                void_swap((void*)(data + 2 * i), (void*)(data + 2 * j), elem_size);
                printf("%s %s\n", *(data + 2 * i), *(data + 2 * j));
                printf("----------------------\n");
            }
        }
    }
}

/*!
    The function what prepare the parametrs (from void*) for launch the default compare function
    \param  [in]  arg1_ptr - the pointer on first argument
    \param  [in]  arg2_ptr - the pointer on second argument
*/
int default_compare(const void* arg1_ptr, const void* arg2_ptr) {
    ASSERT(arg1_ptr != NULL, "Null pointer was passed");
    ASSERT(arg2_ptr != NULL, "Null pointer was passed");

    const char*  first_str_ptr = (const char*)(arg1_ptr);
    const char* second_str_ptr = (const char*)(arg2_ptr);

    return my_strcmp(first_str_ptr, second_str_ptr);
}

/*!
    The function what prepare the parametrs (from void*) for launch the reversed compare function
    \param  [in]  arg1_ptr - the pointer on first comparate function
    \param  [in]  arg2_ptr - the pointer on second comparate function
*/
int reversed_compare(const void* arg1_ptr, const void* arg2_ptr) {
    ASSERT(arg1_ptr != NULL, "Null pointer was passed");
    ASSERT(arg2_ptr != NULL, "Null pointer was passed");

    const char*  first_str_ptr = (const char*)(arg1_ptr);
    const char* second_str_ptr = (const char*)(arg2_ptr);

    return reversed_strcmp(first_str_ptr, second_str_ptr);
}

/* int partition(void* arr, int start, int end, size_t elem_size, int(*comp_func)(void* p1, void* p2)){
    char* data = (char*)arr;
    char* pivot = data + elem_size * start;
    char* left = data + elem_size * (start + 1);
    char* right = data + elem_size * end;

    while (left <= right) {
        while (left <= right && comp_func(left, pivot) <= 0) {
            left += elem_size;
        }
        while (left <= right && comp_func(right, pivot) > 0) {
            right -= elem_size;
        }
        if (left < right) {
            void_swap(left - elem_size, right, elem_size);
        }
    }
    void_swap(pivot, right, elem_size);
    return (int)((right - data) / elem_size);
}

void my_quick_sort(void* arr, int start, int end, size_t elem_size, int(*comp_func)(void* p1, void* p2)) {
    if (start < end) {
        printf("1 ");
        int pi = partition(arr, start, end, elem_size, comp_func);

        my_quick_sort(arr, pi + 1, end, elem_size, comp_func);
        my_quick_sort(arr, start, pi - 1, elem_size, comp_func);

    }
} */
