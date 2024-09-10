#include "my_sort.h"

#include <stdlib.h>
#include <string.h>
#include "my_assert.h"
#include "my_string.h"

void void_swap(void* first_ptr, void* second_ptr, size_t elem_size) {
    void *tmp = calloc(1, elem_size);
    memcpy(tmp, second_ptr, elem_size);
    memcpy(second_ptr, first_ptr, elem_size);
    memcpy(first_ptr, tmp, elem_size);

    free(tmp); tmp = NULL;
}

void bubble_sort(void** arr_index, int arr_lenght, size_t elem_size) {
    for (int i = 0; i < arr_lenght - 1; i++) {
        for (int j = 0; j < arr_lenght - 1; j++) {
            if (my_strcmp((const char*)arr_index[j], (const char*)arr_index[j + 1]) > 0) {
                void_swap(arr_index[j], arr_index[j + 1], elem_size);
            }
        }
    }
}

int comp_func(const void* first_prm, const void* second_prm) {
    const char* s1 = (const char*)first_prm;
    const char* s2 = (const char*)second_prm;
    return my_strcmp(s1, s2);
}

int partition(char* arr[], int low, int high, int (*compare_func)(const char*, const char*)) {
    // Initialize pivot to be the first element
    char* p = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
    // Find the first element greater than
    // the pivot (from starting)
        while (compare_func(arr[i], p) <= 0 && i <= high - 1) i++;

    // Find the first element smaller than
    // the pivot (from last)
        while (compare_func(arr[j], p) > 0 && j >= low + 1) j--;

        if (i < j) swap(&arr[i], &arr[j]);
    }

    swap(&arr[low], &arr[j]);

    return j;
}

void quick_sort(char* arr[], int low, int high, int (*compare_func)(const char*, const char*)) {
    if (low < high) {
    // call partition function to find Partition Index
    int pi = partition(arr, low, high, compare_func);

    // Recursively call quick_sort() for left and right
    // half based on Partition Index
    quick_sort(arr, low, pi - 1, compare_func);
    quick_sort(arr, pi + 1, high, compare_func);
    }
}

void swap(char** x, char** y) {
    char* tmp = *x;
    *x = *y;
    *y = tmp;
}
