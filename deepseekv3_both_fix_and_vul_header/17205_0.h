#include <stddef.h>

#define A_SH 1
#define A_FT 2

struct SYMBOL {
    struct {
        struct {
            int sf;
            int nacc;
            char accs[8];
            char pits[8];
        } key;
    } u;
};