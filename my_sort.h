#ifndef MY_SORT_H
#define MY_SORT_H

#include <stdio.h>

void bubble_sort(void** arr_index, int arr_lenght, size_t elem_size);
void void_swap(void* first_ptr, void* second_ptr, size_t elem_size);
int comp_func(const void* first_prm, const void* second_prm);
void quick_sort(char* arr[], int low, int high, int (*compare_func)(const char*, const char*));
int partition(char* arr[], int low, int high, int (*compare_func)(const char*, const char*));
void swap(char** x, char** y);

#endif // MY_SORT_H