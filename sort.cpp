#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

int reverse_strcmp (char* a_ptr, int a_size, char* b_ptr, int b_size)
{
    int i = 0;
    char* a = a_ptr;
    char* b = b_ptr;
             
    while (i < b_size && i < a_size)
    {
	if (*a < 'A' || *a > 'z')
	{
	     a--;
	     i++;
	}
	
	if (*b < 'A' || *b > 'z')
	{
	     b--;
	     i++;
	}


	if (*a != *b) return *a - *b;

	a--;
	b--; 
	i++;
    }
	
    return (*a == *b) ? 0 : *a - *b;
}

void swap_string (void* a_ptr, void* b_ptr, size_t size)
{                      
    void* temp = calloc (size, 1);    

    memcpy (temp , a_ptr, size); 

    memcpy (a_ptr, b_ptr, size);
    memcpy (b_ptr, temp , size);
}
     
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

    return reverse_strcmp (a->str + a->str_len - 1, a->str_len, b->str + b->str_len - 1, b->str_len);
}

// void* buffer, size_t Text_size, size_t type,

void booble_sort (void* string_array, size_t n_strings, size_t type,
                  int string_cmp (void* first_str, void* second_str))
{
    for (int i = 0; i < n_strings; i++)
    {
        for (int j = i + 1; j < n_strings; j++)
        {
            // (char*)Text + i * Text_size
            if (string_cmp ((String*) string_array + i, (String*) string_array + j) > 0)
            {
     		swap_string ((String*) string_array + i, (String*) string_array + j, sizeof (String));
	    }
        }
    }
}
