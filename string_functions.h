#ifndef STRING_FINCTIONS_H
#define STRING_FINCTIONS_H

struct String
{
    char* str;
    int   str_len;
};

void split_strings (char* buf, int buf_size, struct String* Text, int text_size);

int count_strings (char* buf);

#endif
