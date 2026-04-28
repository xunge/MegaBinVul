#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define USE_M17N
#define N_SYMBOL 256
#define NBSP_CODE 0xA0

typedef struct {
    char *data;
    size_t length;
    size_t capacity;
} Str;

extern char *alt_symbol[];
extern char *alt2_symbol[];

char *Sprintf(const char *format, ...);
void Strcat(Str str, const char *s);
void Strcat_charp_n(Str str, const char *s, int n);
void Strcat_charp(Str str, const char *s);