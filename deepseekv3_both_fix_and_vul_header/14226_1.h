#include <stddef.h>

#define FAIL 1
#define OK 0
#define NUL '\0'

typedef struct {
    int lnum;
    int col;
} pos_T;

typedef struct {
    pos_T w_cursor;
} win_T;

typedef pos_T VIsual_T;

typedef struct {
    void *oap;
} cmdarg_T;

typedef unsigned char char_u;

extern char VIsual_mode;
extern VIsual_T VIsual;
extern win_T *curwin;
extern int has_mbyte;
extern int (*mb_ptr2len)(char_u *);

#define LT_POS(a, b) ((a).lnum < (b).lnum || ((a).lnum == (b).lnum && (a).col < (b).col))

char_u *ml_get_curline(void);
char_u *ml_get_pos(pos_T *pos);
size_t STRLEN(const char_u *str);
void unadjust_for_sel(void);
void clearopbeep(void *oap);
void reset_VIsual_and_resel(void);