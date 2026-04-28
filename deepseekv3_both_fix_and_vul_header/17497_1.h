#include <stddef.h>
#include <ctype.h>

#define NUL '\0'
#define FAIL 1
#define OK 0
#define VAR_STRING 1
#define BS '\b'
#define ESC '\033'
#define FF '\f'
#define NL '\n'
#define CAR '\r'
#define TAB '\t'
#define FALSE 0

typedef unsigned char char_u;

typedef struct {
    int v_type;
    union {
        char_u *v_string;
    } vval;
} typval_T;

#define FSK_KEYCODE 1
#define FSK_IN_STRING 2
#define FSK_SIMPLIFY 4

#define MB_PTR_ADV(p) ((p)++)
#define MB_COPY_CHAR(p, end) (*(end)++ = *(p)++)

#define _(x) x
#define e_stray_closing_curly_str "E115: Stray closing curly brace"
#define e_missing_double_quote_str "E114: Missing double quote"

int trans_special(char_u **p, char_u *end, int flags, int simplify, void *unused);
char_u *alloc(int size);
int vim_isxdigit(int c);
int hex2nr(int c);
int (*mb_char2bytes)(int nr, char_u *buf);
void semsg(const char *msg, char_u *arg);
void iemsg(const char *msg);