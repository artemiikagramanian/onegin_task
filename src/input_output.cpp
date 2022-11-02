#include <stdio.h>
#include <sys\stat.h>
#include <stdlib.h>

#include "input_output.h"

int get_file_size (FILE* file)
{
    struct stat buffer = {0};
    fstat (fileno (file), &buffer);

    return buffer.st_size;
}

char* read_file (FILE* file, int buf_size)
{
    char* buf = (char*) calloc (buf_size, sizeof (char));

    fread (buf, sizeof (char), buf_size, file);
    buf[buf_size - 1] = '\0';

    return buf;
}

void print_strings (FILE* file, String* string_arr, int n_strings)
{
    for (int i = 0; i < n_strings; i++)
    {
        fprintf (file, "%d %s", string_arr[i].str_len, string_arr[i].str);
    }
}
