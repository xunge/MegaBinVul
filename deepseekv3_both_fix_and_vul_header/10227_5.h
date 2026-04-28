#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

typedef int fixed;
typedef unsigned int ufixed;

typedef struct {
    fixed x;
    fixed y;
} point;

typedef struct active_line {
    fixed x_current;
    fixed x_next;
    point start;
    point end;
} active_line;

#define AL_X_AT_Y(alp, y_val) \
    ((alp)->start.x + fixed_mult_quo((y_val) - (alp)->start.y, \
                                   (alp)->end.x - (alp)->start.x, \
                                   (alp)->end.y - (alp)->start.y))

#define INCR(expr) ((void)0)
#define INCR_EXPR(expr) ((void)0)
#define if_debug3(c, fmt, a1, a2, a3) ((void)0)

#define size_of(type) (sizeof(type) * CHAR_BIT / 2)

extern int mq_cross;
extern int cross_slow;
extern int cross_low;

extern float fixed2float(fixed f);
extern fixed fixed_mult_quo(fixed a, fixed b, fixed c);
extern fixed fixed_epsilon;