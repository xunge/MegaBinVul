#include <stddef.h>

typedef unsigned char char_u;
#define NUL '\0'

typedef struct {
    int lnum;
    int col;
} pos_T;

typedef struct {
    pos_T w_cursor;
} win_T;

typedef struct {
    int lnum;
    int col;
} VIsual_T;

typedef struct {
    void *oap;
} cmdarg_T;

extern win_T *curwin;
extern VIsual_T VIsual;
extern char VIsual_mode;
extern int has_mbyte;

char_u *ml_get_curline(void);
char_u *ml_get_pos(pos_T *pos);
void unadjust_for_sel(void);
void clearopbeep(void *oap);
void reset_VIsual_and_resel(void);
size_t STRLEN(const char_u *str);
int mb_ptr2len(const char_u *p);
#define LT_POS(a, b) ((a).lnum < (b).lnum || ((a).lnum == (b).lnum && (a).col < (b).col))

#define FAIL 1
#define OK 0