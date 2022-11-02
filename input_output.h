#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include "string_functions.h"

int get_file_size (FILE* file);

char* read_file (FILE* file, int buf_size);

void print_strings (FILE* file, String* string_arr, int n_strings);

#endif
