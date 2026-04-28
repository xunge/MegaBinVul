#include <string.h>

#define initial_n 128
#define initial_bias 72
#define delimiter '-'
#define base 36
#define tmin 1
#define tmax 26
#define maxint ((unsigned int)-1)

static int is_basic(unsigned int ch)
{
    return ch < 0x80;
}

static int digit_decoded(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c - 'A';
    if (c >= 'a' && c <= 'z')
        return c - 'a';
    if (c >= '0' && c <= '9')
        return c - '0' + 26;
    return -1;
}

static unsigned int adapt(unsigned int delta, unsigned int numpoints, int firsttime)
{
    unsigned int k;

    delta = firsttime ? delta / 700 : delta / 2;
    delta += delta / numpoints;

    for (k = 0; delta > ((base - tmin) * tmax) / 2; k += base)
        delta /= base - tmin;

    return k + (base - tmin + 1) * delta / (delta + 38);
}