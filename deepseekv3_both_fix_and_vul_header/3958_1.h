#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

typedef struct tiff {
    const char *tif_name;
} TIFF;

void TIFFErrorExtR(TIFF*, const char*, const char*, ...);