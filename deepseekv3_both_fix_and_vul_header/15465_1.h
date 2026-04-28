#include <string.h>
#include <stdlib.h>

typedef struct Str *Str;
typedef int Lineprop;
typedef int Linecolor;

#define PE_NORMAL 0
#define PC_CTRL 1
#define PC_ASCII 2
#define PC_WCHAR1 4
#define PC_WCHAR2 8
#define PE_UNDER 16
#define PE_BOLD 32
#define ESC_CODE '\033'
#define FALSE 0
#define TRUE 1
#define LINELEN 256
#define ShowEffect 1
#define IS_ASCII(c) ((unsigned char)(c) < 128)
#define IS_CNTRL(c) ((c) < ' ' || (c) == 127)

#define New_Reuse(type, ptr, size) ((type *)realloc(ptr, (size) * sizeof(type)))

struct Str {
    char *ptr;
    int length;
};

Str Strnew_size(int size);
void Strcat_charp_n(Str s, char *str, int n);
void Strcat_char(Str s, char c);
void Strshrink(Str s, int n);
int get_mctype(char *str);
int get_mclen(char *str);
int parse_ansi_color(char **str, Lineprop *effect, Linecolor *mode);