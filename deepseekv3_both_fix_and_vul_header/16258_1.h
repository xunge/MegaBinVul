#include <limits.h>
#include <stdlib.h>
#include <string.h>

struct grid_cell {
    int attr;
};

struct input_param {
    char *str;
};

struct input_cell {
    struct grid_cell cell;
};

struct input_ctx {
    struct input_cell cell;
    struct input_param *param_list;
};

#define GRID_ATTR_ALL_UNDERSCORE 0
#define GRID_ATTR_UNDERSCORE (1 << 0)
#define GRID_ATTR_UNDERSCORE_2 (1 << 1)
#define GRID_ATTR_UNDERSCORE_3 (1 << 2)
#define GRID_ATTR_UNDERSCORE_4 (1 << 3)
#define GRID_ATTR_UNDERSCORE_5 (1 << 4)

#define nitems(x) (sizeof((x)) / sizeof((x)[0]))

typedef unsigned int u_int;

char *xstrdup(const char *);
long long strtonum(const char *, long long, long long, const char **);
void log_debug(const char *, ...);
void input_csi_dispatch_sgr_rgb_do(struct input_ctx *, int, int, int, int);
void input_csi_dispatch_sgr_256_do(struct input_ctx *, int, int);