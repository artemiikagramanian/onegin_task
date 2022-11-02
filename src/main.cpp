#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys\stat.h>

#include "string_functions.h"
#include "sort.h"
#include "input_output.h"
#include "operations.h"
#include "options.h"

int main(int argc, char* argv[])
{
    FILE* input_file = fopen ("hamlet.bin", "rb");
    assert (input_file != NULL);

    FILE* output_file = fopen ("output.bin", "rb");
    assert (output_file != NULL);

    int buf_size = get_file_size (input_file);

    char* buf = read_file (input_file, buf_size + 1);

    int n_strings = count_strings (buf);


    String* string_arr = split_strings (buf, buf_size, n_strings);

    print_strings (output_file, string_arr, n_strings);


    booble_sort   (string_arr,   n_strings, sizeof (String), string_cmp);
    print_strings (output_file, string_arr,      n_strings);


    booble_sort   ( string_arr,  n_strings, sizeof (String), reverse_string_cmp);
    print_strings (output_file, string_arr,      n_strings);

    quick_sort    ( string_arr,  n_strings, sizeof (String), string_cmp);
    print_strings (output_file, string_arr,      n_strings);
}
