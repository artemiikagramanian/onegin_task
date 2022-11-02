#ifndef SORT_H
#define SORT_H

#include "string_functions.h"

int  reverse_string_cmp (void* a_ptr, void* b_ptr);

int  string_cmp (void* a_ptr, void* b_ptr);

void booble_sort (void* type_arr, size_t n_strings, size_t type,
                  int type_cmp (void* first_str, void* second_str));

void quick_sort (void* string_array, size_t n_strings, size_t type,
                 int type_cmp (void* first_str, void* second_str));

#endif
