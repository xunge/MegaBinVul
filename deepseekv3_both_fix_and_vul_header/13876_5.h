#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

struct topdicts {
    struct {
        int cnt;
    } glyphs;
    uint16_t *charset;
    uint32_t charsetoff;
    uint32_t cff_start;
};

struct ttfinfo {
    bool bad_cff;
};

uint16_t getushort(FILE *ttf);
void LogError(const char *format, ...);

#define uint16 uint16_t
#define _(x) x