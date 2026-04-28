#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct topdicts {
    int fontmatrix_set;
    double fontmatrix[6];
    int32_t cff_start;
};

struct ttfinfo {
    // Add necessary fields if needed
};

uint16_t getushort(FILE *ttf);
uint32_t getoffset(FILE *ttf, int offsize);
struct topdicts *readcfftopdict(FILE *ttf, char *fontname, uint32_t length, struct ttfinfo *info);
void MatMultiply(double a[6], double b[6], double result[6]);

typedef int32_t int32;
typedef uint16_t uint16;
typedef uint32_t uint32;