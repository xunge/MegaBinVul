#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define HIST_COUNT 10
#define HIST_CMD 0
#define NUL '\0'
#define VIM_ISDIGIT(c) isdigit((unsigned char)(c))
#define ASCII_ISALPHA(c) isalpha((unsigned char)(c))
#define STRLEN(s) strlen((char *)(s))
#define STRNICMP(s1, s2, n) strncasecmp((char *)(s1), (char *)(s2), (n))
#define STRCPY(d, s) strcpy((char *)(d), (char *)(s))
#define STRCAT(d, s) strcat((char *)(d), (char *)(s))
#define IOSIZE 1024
#define Columns 80

typedef unsigned char char_u;

typedef struct exarg {
    char_u *arg;
} exarg_T;

typedef struct histentry {
    char_u *hisstr;
    int hisnum;
} histentry_T;

extern int hislen;
extern histentry_T *history[HIST_COUNT];
extern int hisidx[HIST_COUNT];
extern char_u IObuff[IOSIZE];
extern int got_int;
extern char *history_names[HIST_COUNT];
extern char *e_trailing_characters_str;
extern char *e_val_too_large;

int get_histtype(char_u *arg);
int get_list_range(char_u **end, int *hisidx1, int *hisidx2);
int vim_strsize(char_u *s);
char_u *vim_strchr(char_u *string, int c);
void trunc_string(char_u *s, char_u *buf, int max_len, int buflen);
void msg(char *s);
void semsg(char *s, char_u *arg);
void msg_puts_title(char *s);
void msg_putchar(char c);
void msg_outtrans(char_u *s);
void out_flush(void);