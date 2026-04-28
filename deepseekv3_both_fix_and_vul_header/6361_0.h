#include <stddef.h>

typedef long colnr_T;
typedef unsigned char char_u;
typedef int bool;

#define TRUE 1
#define FALSE 0
#define FAIL 1
#define NUL '\0'
#define REG_MULTI 0

struct regengine {
    char_u *line;
    int lnum;
    bool reg_ic;
    union {
        struct {
            colnr_T col;
            int lnum;
        } reg_startpos[1], reg_endpos[1];
        char_u *reg_startp[1], *reg_endp[1];
    };
};

extern struct regengine rex;

#define MB_CHAR2LEN(c) 1
#define PTR2CHAR(p) (*(p))
#define MB_CASEFOLD(c) (c)
#define enc_utf8 0
#define utf_iscomposing(c) 0

static int skip_to_start(int regstart, colnr_T *col);
static void cleanup_subexpr(void);