#include <stdio.h>

#include "string_functions.h"

int count_strings (char* buf)
{
    char* pointer       = buf;
    int   count_strings = 0;

    while (*pointer != '\0')
    {
        if (*pointer == '\n') count_strings++;

        pointer++;
    }

    return count_strings;
}

void split_strings (char* buf, int buf_size, struct String* string_arr, int n_strings)
{
    int string_index = 0;

    char* pointer  = buf;
    int   str_size = 0;
       
    while (string_index != n_strings)
    {
        if (*pointer == '\n' || *pointer == '\0')
        {
            *pointer = '\0';

            string_arr[string_index].str     = pointer - str_size;
            string_arr[string_index].str_len = str_size + 1;

            string_index++;
            str_size = 0;
        }

        else if (*pointer == '\r')
	{
            *pointer = '\n';
	    str_size++;
	}

        else str_size++;

        pointer++;
    }
}
