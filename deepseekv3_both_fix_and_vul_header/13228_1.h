#include <time.h>
#include <stdio.h>
#include <stdint.h>

#define BUFSIZE 256

typedef struct netdissect_options {
    int dummy;
} netdissect_options;

#define ND_PRINT(fmt, ...) printf(fmt, ##__VA_ARGS__)