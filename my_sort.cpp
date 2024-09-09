#include "my_sort.h"

#include <stdlib.h>
#include <string.h>
#include "my_assert.h"
#include "my_string.h"

void swap(void* first_ptr, void* second_ptr, size_t elem_size) {
    void *tmp = calloc(1, elem_size);
    memcpy(tmp, second_ptr, elem_size);
    memcpy(second_ptr, first_ptr, elem_size);
    memcpy(first_ptr, tmp, elem_size);

    free(tmp); tmp = NULL;
}

void bubbleSort(char* arr_index[], int arr_lenght) {
    for (int i = 0; i < arr_lenght - 1; i++) {
        for (int j = 0; j < arr_lenght - 1; j++) {
            if (my_strcmp(arr_index[j], arr_index[j + 1]) > 0) {
                swap(arr_index[j], arr_index[j + 1], sizeof(arr_index[j]));
            }
        }
    }
}