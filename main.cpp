#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys\stat.h>

#include "string_functions.h"
#include "sort.h"
#include "input_output.h"

int main()
{
    FILE* file = fopen ("hamlet.bin", "rb");
    assert (file != NULL);

    int buf_size = get_file_size (file);

    // read_file
    char* buf = (char*) calloc (buf_size, sizeof (char));

    read_file (file, buf, buf_size);

    int n_strings = count_strings (buf);

    struct String* string_arr = (String*) calloc (n_strings, sizeof (String));
    split_strings (buf, buf_size, string_arr, n_strings);

    booble_sort (string_arr, n_strings, sizeof (String), reverse_string_cmp);
                                                     
    for (int i = 0; i < n_strings; i++)
    {
        printf ("%d %s", string_arr[i].str_len, string_arr[i].str);
    }
}
