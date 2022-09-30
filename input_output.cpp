#include <stdio.h>
#include <sys\stat.h>
#include <stdlib.h>

#include "input_output.h"

int get_file_size (FILE* file)
{
    struct stat buffer = {0};
    fstat (fileno (file), &buffer);

    int buf_size = buffer.st_size + 1;

    return buf_size;
}

void read_file (FILE* file, char* buf, int buf_size)
{
    fread (buf, sizeof (char), buf_size, file);
    buf[buf_size - 1] = '\0';
}

