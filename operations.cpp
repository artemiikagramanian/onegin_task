#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "operations.h"

void swap_elems (void* a_ptr, void* b_ptr, size_t size)
{
    char tmp = 0;

    for (int i = 0; i < size; i++)
    {
        tmp = *((char*) a_ptr + i);
        *((char*) a_ptr + i) = *((char*) b_ptr + i);
        *((char*) b_ptr + i) = tmp;
    }
}

