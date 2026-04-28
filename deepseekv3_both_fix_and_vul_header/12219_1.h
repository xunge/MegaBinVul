#include <limits.h>

#define FALSE 0
#define TRUE 1

typedef struct cmdarg cmdarg_T;
typedef struct oparg oparg_T;

struct oparg {
    int op_type;
};

struct cmdarg {
    oparg_T *oap;
    int count1;
};

#define K_DEL 0
#define K_KDEL 0
#define K_LEFT 0
#define K_RIGHT 0
#define CAR 0
#define OP_NOP 0

#define VIM_ISDIGIT(c) ((c) >= '0' && (c) <= '9')
#define LANGMAP_ADJUST(c, condition) ((void)0)

extern int no_mapping;
extern int allow_keys;
extern int dont_scroll;
extern int need_mouse_correct;

int checkclearop(oparg_T *oap);
void clearopbeep(oparg_T *oap);
int plain_vgetc(void);
void add_to_showcmd(int c);
void win_setheight(int height);

#ifdef USE_ON_FLY_SCROLL
int dont_scroll;
#endif

#ifdef FEAT_GUI
int need_mouse_correct;
#endif