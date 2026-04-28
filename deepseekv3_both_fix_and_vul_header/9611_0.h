#include <stdint.h>

static inline int mid_pred(int a, int b, int c)
{
    if (a > b) {
        if (c > b) {
            if (c > a)
                b = a;
            else
                b = c;
        }
    } else {
        if (b > c) {
            if (a > c)
                b = a;
            else
                b = c;
        }
    }
    return b;
}