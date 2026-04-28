#include <stddef.h>
#include <ctype.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define NUMBUFLEN 50
#define FALSE 0
#define TRUE 1
#define MAXCOL 2147483647
#define NUL '\0'
#define OP_NR_SUB 1
#define VIsual_active 0
#define VIsual_mode 0
#define CMOD_LOCKMARKS 0

#define STR2NR_BIN 1
#define STR2NR_OCT 2
#define STR2NR_HEX 4

typedef unsigned long long uvarnumber_T;
typedef long linenr_T;
typedef int colnr_T;

typedef struct {
    linenr_T lnum;
    colnr_T col;
    colnr_T coladd;
} pos_T;

typedef struct {
    pos_T w_cursor;
    int w_set_curswant;
    colnr_T w_curswant;
} win_T;

typedef struct {
    char *b_p_nf;
    pos_T b_op_start;
    pos_T b_op_end;
    struct {
        colnr_T vi_curswant;
    } b_visual;
} buf_T;

typedef struct {
    int cmod_flags;
} cmdmod_T;

extern win_T *curwin;
extern buf_T *curbuf;
extern cmdmod_T cmdmod;

typedef char char_u;

#define STRLEN(s) strlen((const char *)(s))
#define vim_strchr(s, c) strchr((const char *)(s), (c))
#define vim_isbdigit(c) (isdigit(c) || (c) == 'b' || (c) == 'B')
#define vim_isxdigit(c) isxdigit((unsigned char)(c))
#define vim_isdigit(c) isdigit((unsigned char)(c))
#define ASCII_ISALPHA(c) isalpha((unsigned char)(c))
#define VIM_ISDIGIT(c) isdigit((unsigned char)(c))
#define CharOrd(c) ((c) - (isupper((unsigned char)(c)) ? 'A' : 'a'))
#define STRCAT(d, s) strcat((char *)(d), (const char *)(s))

static int has_mbyte = 0;
static int (*mb_head_off)(char_u *, char_u *);
static int (*mb_ptr2len)(char_u *);

static char_u *ml_get(linenr_T lnum);
static char_u *ml_get_curline(void);
static int del_char(int fixpos);
static void ins_char(int c);
static void ins_str(char_u *s);
static void beep_flush(void);
static int virtual_active(void);
static void vim_str2nr(char_u *start, int *pre, int *len, int what, char_u **endptr, uvarnumber_T *nptr, int maxlen, int strict, int *overflow);
static void vim_snprintf(char *str, size_t size, const char *format, ...);
static void *alloc(size_t size);
static int gchar_cursor(void);
static void inc_cursor(void);
static void vim_free(void *ptr);