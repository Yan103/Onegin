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
    \param  [in]  comp_func2 - the pointer on second comparate function
*/
void my_sort(Text* onegin, int (*comp_func1)(const void*, const void*), int (*comp_func2)(const void*, const void*)) {
    ASSERT(onegin     != NULL, "Null pointer was passed");
    ASSERT(comp_func1 != NULL, "Null pointer was passed");
    ASSERT(comp_func2 != NULL, "Null pointer was passed");

    for (int i = 0; i < onegin->lines_count - 1; i++) {
        for (int j = 0; j < onegin->lines_count - 1; j++) {
            if (comp_func1(onegin->text_start_ptr[j],
                           onegin->text_start_ptr[j + 1]) > 0) {
                void_swap(&onegin->text_start_ptr[j], &onegin->text_start_ptr[j + 1], sizeof(onegin->text_start_ptr[j]));
            }

            if (comp_func2(onegin->text_end_ptr[j],
                           onegin->text_end_ptr[j + 1]) > 0) {
                void_swap(&onegin->text_end_ptr[j], &onegin->text_end_ptr[j + 1], sizeof(onegin->text_end_ptr[j]));
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
    char** data = (char**)arr;
    char* pivot = *(data + start + 1);
    //char* left = *(data + start);
    //char* right = *(data + (end - 1));

    int pi = start;
    while (*(data + start) < *(data + (end - 1))) {
        while (comp_func((void*)(*(data + start)), (void*)(pivot)) <= 0 &&
               (size_t)(*(data + start)- *data) / elem_size <= (size_t)(end - 1)) {
                start++;
        }

        while (comp_func((void*)(*(data + (end - 1))), (void*)(pivot)) >= 0 &&
               (size_t)(*(data + (end - 1)) - *data) >= (size_t)(*(data + start) - *data)) {
                --end;
        }

        if (*(data + start) < *(data + (end - 1))) {
            printf("%s %s\n", *(data + start), *(data + end - 1));
            printf("------------------\n");
            void_swap((void*)((data + start)), (void*)((data + end - 1)), elem_size);
            printf("%s %s\n", *(data + start), *(data + end - 1));
        }
        printf("!");
    }

    void_swap((void*)((data + pi)), (void*)((data + end - 1)), elem_size);

    return (int)((*(data + end - 1) - *data) / elem_size);
}

void my_quick_sort(void* arr, int start, int end, size_t elem_size, int(*comp_func)(void* p1, void* p2)) {
    if (start < end) {
        printf("1 ");
        int pi = partition(arr, start, end, elem_size, comp_func);

        my_quick_sort(arr, pi + 1, end, elem_size, comp_func);
        my_quick_sort(arr, start, pi - 1, elem_size, comp_func);

    }
} */
