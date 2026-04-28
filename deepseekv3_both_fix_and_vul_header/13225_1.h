#include <stdint.h>
#include <time.h>
#include <math.h>

#define GET_BE_U_4(x) (x)
#define FMAXINT 4294967296.0
#define JAN_1970 2208988800UL
#define ND_PRINT(fmt, ...) printf(fmt, ##__VA_ARGS__)

struct l_fixedpt {
    uint32_t int_part;
    uint32_t fraction;
};

typedef struct netdissect_options {
    int dummy;
} netdissect_options;