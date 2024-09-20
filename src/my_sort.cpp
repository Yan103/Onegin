/*!
    \file
    File with functions, what sort onegin lines
*/

#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "my_assert.h"
#include "my_sort.h"
#include "my_string.h"

/*!
    The function what swap two void* pointer
    \param  [in]   first_ptr - the first pointer
    \param  [in]  second_ptr - the second pointer
    \param [out]   elem_size - the size of elements in pointers
*/
void void_swap(void* first_ptr, void* second_ptr, size_t elem_size) {
    ASSERT(first_ptr  != NULL, ERR_MSG_NULL_PTR);
    ASSERT(second_ptr != NULL, ERR_MSG_NULL_PTR);

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
void my_sort(void* arr, size_t elem_count, size_t elem_size, my_comp_type comp_func) {
    ASSERT(arr       != NULL, ERR_MSG_NULL_PTR);
    ASSERT(comp_func != NULL, ERR_MSG_NULL_PTR);

    size_t data = (size_t)(arr);

    for (size_t i = 0; i < elem_count; i++) {
        for (size_t j = i; j < elem_count; j++) {
            if (comp_func((const void*)(data + i * elem_size), (const void*)(data + j * elem_size)) > 0) {
                void_swap((void*)(data + i * elem_size), (void*)(data + j * elem_size), elem_size);
            }
        }
    }
}

/*!
    The function what prepare the parametrs (from void*) for launch the default compare function
    \param  [in]  arg1_ptr - the pointer on first argument
    \param  [in]  arg2_ptr - the pointer on second argument
*/
int struct_comp_sort(const void* arg1_ptr, const void* arg2_ptr) {
    ASSERT(arg1_ptr != NULL, ERR_MSG_NULL_PTR);
    ASSERT(arg2_ptr != NULL, ERR_MSG_NULL_PTR);

    const str_info *arg1_ptr_typed = (const str_info*)(arg1_ptr);
    const str_info *arg2_ptr_typed = (const str_info*)(arg2_ptr);

    return my_strcmp(arg1_ptr_typed->text_start, arg2_ptr_typed->text_start);
}

/*!
    The function what prepare the parametrs (from void*) for launch the reversed compare function
    \param  [in]  arg1_ptr - the pointer on first comparate function
    \param  [in]  arg2_ptr - the pointer on second comparate function
*/
int struct_comp_reverse(const void* arg1_ptr, const void* arg2_ptr) {
    ASSERT(arg1_ptr != NULL, ERR_MSG_NULL_PTR);
    ASSERT(arg2_ptr != NULL, ERR_MSG_NULL_PTR);

    const str_info *arg1_ptr_typed = (const str_info*)(arg1_ptr);
    const str_info *arg2_ptr_typed = (const str_info*)(arg2_ptr);

    return reversed_strcmp(arg1_ptr_typed->text_end, arg2_ptr_typed->text_end);
}

/*!
    The function that sorts an array by separating element
    \param  [out]      arr - the pointer on array
    \param  [in]     start - the first element
    \param  [in]       end - the last element
    \param  [in] elem_size - size of element
    \param  [in] comp_func - the pointer on comparate function
*/
int partition(void* arr, int start, int end, size_t elem_size, my_comp_type comp_func) {
    ASSERT(arr       != NULL, ERR_MSG_NULL_PTR);
    ASSERT(comp_func != NULL, ERR_MSG_NULL_PTR);

    size_t data = (size_t)(arr);

    size_t pivot = data + elem_size * start;
    size_t left = data + elem_size * start;
    size_t right = data + elem_size * (end - 1);

    while (left < right) {
        while (left <= right && comp_func((const void*)left, (const void*)pivot) <= 0) {
            left += elem_size;
        }

        while (left <= right && comp_func((const void*)right, (const void*)pivot) > 0) {
            right -= elem_size;
        }

        if (left < right) {
            void_swap((void*)(left), (void*)right, elem_size);
        }
    }

    void_swap((void*)pivot, (void*)right, elem_size);

    return (int)((right - data) / elem_size);
}

/*!
    The function what launch the QuickSort algorithm
    \param  [out]      arr - the pointer on array
    \param  [in]     start - the first element
    \param  [in]       end - the last element
    \param  [in] elem_size - size of element
    \param  [in] comp_func - the pointer on comparate function
*/
void my_quick_sort(void* arr, int start, int end, size_t elem_size, my_comp_type comp_func) {
    ASSERT(arr       != NULL, ERR_MSG_NULL_PTR);
    ASSERT(comp_func != NULL, ERR_MSG_NULL_PTR);

    if (start < end) {
        int pivot = partition(arr, start, end, elem_size, comp_func);

        my_quick_sort(arr, pivot + 1, end, elem_size, comp_func);
        my_quick_sort(arr, start, pivot - 1, elem_size, comp_func);
    }
}
