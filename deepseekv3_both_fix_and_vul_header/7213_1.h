#include <stddef.h>

#define UNUSED
#define FEAT_CMDWIN

typedef char char_u;

typedef struct garray_T {
    int ga_len;
    void *ga_data;
} garray_T;

typedef struct user_command {
    char_u *uc_name;
} user_command;

typedef struct buf_T {
    garray_T b_ucmds;
} buf_T;

typedef struct window_T {
    buf_T *w_buffer;
} window_T;

typedef struct expand_T expand_T;

extern buf_T *curbuf;
extern window_T *prevwin;
extern garray_T ucmds;

#define USER_CMD_GA(ga, idx) (((user_command *)(ga)->ga_data) + (idx))
#define USER_CMD(idx) USER_CMD_GA(&ucmds, idx)

window_T *prevwin_curwin(void);
int is_in_cmdwin(void);