#include "my_sort.h"

#include "my_assert.h"
#include "my_string.h"

void bubbleSort(char* arr_index[], int arr_lenght) {
    for (int i = 0; i < arr_lenght - 1; i++) {
        for (int j = 0; j < arr_lenght - 1; j++) {
            if (my_strcmp(arr_index[j], arr_index[j + 1]) > 0) {
                char* tmp = arr_index[j];
                arr_index[j] = arr_index[j + 1];
                arr_index[j + 1] = tmp;
            }
        }
    }
}