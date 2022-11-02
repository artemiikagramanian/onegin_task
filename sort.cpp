#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cctype>

#include "sort.h"
#include "operations.h"

int string_cmp (void* a_ptr, void* b_ptr)
{
    String* a = (String*) a_ptr;
    String* b = (String*) b_ptr;

    return strcmp (a->str, b->str);
}

int reverse_string_cmp (void* a_ptr, void* b_ptr)
{
    String* a = (String*) a_ptr;
    String* b = (String*) b_ptr;

    int i = 0;

    int a_size = a->str_len;
    int b_size = b->str_len;

    char* a_str = a->str + a_size - 1;
    char* b_str = b->str + b_size - 1;

    while (i < b_size && i < a_size)
    {
        if (isalnum (*a_str) == 0)
        {
             a_str--;
             i++;
        }

        if (isalnum (*b_str) == 0)
        {
             b_str--;
             i++;
        }


        if (*a_str != *b_str) return *a_str - *b_str;

        a_str--;
        b_str--;
        i++;
    }

    return (b_size == a_size) ? 0 : *a_str - *b_str;
}

void booble_sort (void* type_arr, size_t n_strings, size_t type,
                  int type_cmp (void* first_str, void* second_str))
{
    for (int i = 0; i < n_strings; i++)
    {
        for (int j = i + 1; j < n_strings; j++)
        {
            if (type_cmp ((char*) type_arr + i*type, (char*) type_arr + j*type) > 0)
            {
                swap_elems ((char*) type_arr + i*type, (char*) type_arr + j*type, type);
            }
        }
    }
}

void quick_sort (void* type_arr, size_t n_strings, size_t type,
                int type_cmp (void* first_str, void* second_str))
{
    size_t begin_ptr = 0;
    size_t end_ptr   = n_strings - 1;

    void* mid = (char*) type_arr + (n_strings / 2) * type;

    while (begin_ptr <= end_ptr)
    {
        while (type_cmp ((char*)type_arr + begin_ptr * type, mid) < 0 )
        {
            begin_ptr++;
        }

        while (type_cmp ((char*)type_arr + end_ptr   * type, mid) > 0 )
        {
            end_ptr--;
        }

        if (begin_ptr <= end_ptr)
        {
            swap_elems ((char*)type_arr + begin_ptr * type, (char*)type_arr + end_ptr * type, type);

            begin_ptr++;
            end_ptr--;
        }
    }

    if (end_ptr > 0) quick_sort ((char*) type_arr, end_ptr + 1, type, type_cmp);

    if (begin_ptr < n_strings - 1) quick_sort ((char*) type_arr + begin_ptr * type,
                                                      n_strings - begin_ptr, type, type_cmp);
}
