#ifndef MY_SORT_H
#define MY_SORT_H

#include <stdio.h>

void bubble_sort(void** arr_index, int arr_lenght, size_t elem_size);
void swap(void* first_ptr, void* second_ptr, size_t elem_size);
int comp_func(const void* first_prm, const void* second_prm);

#endif // MY_SORT_H