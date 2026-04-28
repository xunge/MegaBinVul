#include <stdlib.h>
#include <string.h>

typedef char* Str;
typedef unsigned int Lineprop;

typedef struct {
    char *lineBuf;
    int len;
    Lineprop *propBuf;
} Line;

#define PC_SYMBOL 0x01
#define PC_KANJI 0x02
#define SYMBOL_BASE 0
#define N_SYMBOL 1
#define USE_M17N 0

typedef unsigned char wc_uchar;
extern char* DisplayCharset;

#ifdef USE_M17N
extern char** get_symbol(char* charset, int* width);
#else
extern char** get_symbol(void);
#endif

extern Str Strnew_size(int size);
extern void Strcopy_charp_n(Str str, const char *src, int n);
extern void Strcat_charp(Str str, const char *src);
extern void Strcat_char(Str str, char c);
extern Str Strnew_charp_n(const char *src, int n);
extern int wtf_get_code(wc_uchar *p);
extern int get_mclen(char *p);