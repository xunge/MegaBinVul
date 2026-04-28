#include <stddef.h>

typedef struct {
    int lnum;
    int col;
} pos_T;

typedef int colnr_T;

struct window {
    pos_T w_cursor;
};

extern struct window *curwin;

#define FM_BLOCKSTOP 0

pos_T *findmatchlimit(pos_T *pos, int c, int flags, int stopat);
colnr_T cin_skip2pos(pos_T *trypos);
pos_T *ind_find_start_CORS(char *line);