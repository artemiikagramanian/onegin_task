#include <stdio.h>
#include <string.h>

#include "sort.h"
#include "options.h"
#include "string_functions.h"

const Option option_arr[2] = {{"--rbubble", rbooble_string_sort}, {"--rquick", rquick_string_sort}};

void use_options (int argc, char* argv[], String* string_arr, int n_strings)
{
    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (strcmp (argv[i], option_arr[j].name)) *(option_arr[j].opt) (string_arr, n_strings);
        }
    }
}

void rbooble_string_sort (String* string_arr, int n_strings)
{
    booble_sort (string_arr, n_strings, sizeof (String), reverse_string_cmp);
}

void rquick_string_sort (String* string_arr, int n_strings)
{
    quick_sort (string_arr, n_strings, sizeof (String), reverse_string_cmp);
}
