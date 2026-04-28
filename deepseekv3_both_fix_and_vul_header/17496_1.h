#include <stddef.h>
#include <string.h>
#include <ctype.h>

typedef struct pos_T {
    long lnum;
    long col;
} pos_T;

typedef struct buf_T {
    struct {
        long ml_line_count;
    } b_ml;
} buf_T;

typedef unsigned char char_u;

#define FALSE 0
#define TRUE 1
#define IOSIZE 1024
#define CPO_JOINSP 'J'
#define TAB '\t'
#define NUL '\0'
#define STRLEN strlen
#define STRNCPY strncpy

extern int compl_length;
extern int p_paste;
extern char_u *p_cpo;
extern int p_js;
extern char_u IObuff[IOSIZE];

char_u *ml_get_buf(buf_T *buf, long lnum, int will_change);
int ctrl_x_mode_line_or_eval(void);
int compl_status_adding(void);
char_u *skipwhite(char_u *p);
char_u *find_word_start(char_u *p);
char_u *find_word_end(char_u *p);
int vim_iswordp(char_u *p);
char_u *vim_strchr(const char_u *string, int c);