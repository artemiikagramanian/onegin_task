#ifndef OPTIONS_H
#define OPTIONS_H

struct Option
{
    char* name;
    void (*opt) ();
};

void use_options (int argc, char* argv[], String* string_arr, int n_strings);

void rbooble_string_sort (String* string_arr, int n_strings);

void rquick_string_sort (String* string_arr, int n_strings);

#endif
