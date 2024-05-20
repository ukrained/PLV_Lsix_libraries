#include "mylower.h"

int str_to_lower(char* userstr_p)
{
    char* p = userstr_p;

    for (; *p; p++) {
        *p = (*p > 0x40 && *p < 0x5b) ? *p + 0x20 : *p;
    }

    return 0;
}