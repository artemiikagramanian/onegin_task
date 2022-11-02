#ifndef STRING_FUNCTIONS_H
#define STRING_FUNCTIONS_H

struct String
{
    char* str;
    int   str_len;
};

String* split_strings (char* buf, int buf_size, int n_strings);

int count_strings (char* buf);

#endif
