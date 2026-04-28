#include <ctype.h>
#include <stddef.h>

static int _q_x2c(char h, char l)
{
    int hi = isdigit(h) ? h - '0' : tolower(h) - 'a' + 10;
    int lo = isdigit(l) ? l - '0' : tolower(l) - 'a' + 10;
    return (hi << 4) + lo;
}