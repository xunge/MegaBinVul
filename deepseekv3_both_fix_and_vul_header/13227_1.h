#include <stdint.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

typedef unsigned char u_char;
typedef struct netdissect_options netdissect_options;

#define GET_BE_U_4(p) ((uint32_t)((p)[0] << 24 | (p)[1] << 16 | (p)[2] << 8 | (p)[3]))
#define FMAXINT 4294967296.0
#define JAN_1970 2208988800UL

#define ND_PRINT(fmt, ...) printf(fmt, ##__VA_ARGS__)