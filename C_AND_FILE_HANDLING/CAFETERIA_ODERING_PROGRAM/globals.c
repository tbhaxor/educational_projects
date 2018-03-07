#include <stdlib.h>

char* gen_random(const int len)
{
    char str[len];
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i)
    {
        str[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    str[len] = '\0';
    return str;
}