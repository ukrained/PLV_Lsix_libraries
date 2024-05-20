#include "myupper.h"

int str_to_upper(char* userstr_p)
{
    char* p = userstr_p;

    for (; *p; p++) {
        *p = (*p > 0x60 && *p < 0x7b) ? *p - 0x20 : *p;
    }

    return 0;
}