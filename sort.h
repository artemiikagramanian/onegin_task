#ifndef SORT_H
#define SORT_H

#include <string.h>

#include "string_functions.h"

int reverse_strcmp (char* a_ptr, int a_size, char* b_ptr, int b_size);

int reverse_string_cmp (void* a_ptr, void* b_ptr);

void swap_string (void* a_ptr, void* b_ptr, size_t size);

int string_cmp (void* a_ptr, void* b_ptr);

void booble_sort (void* string_array, size_t n_strings, size_t type,
                  int string_cmp (void* first_str, void* second_str)) ;

#endif
