#include <stddef.h>

typedef char char_u;

#define CMD_USER 0
#define CMD_USER_BUF 1
#define FEAT_CMDWIN

typedef struct window_S window_T;
typedef struct buf_S buf_T;
typedef struct garray_S garray_T;

struct window_S {
    buf_T *w_buffer;
};

struct garray_S {
    int ga_len;
    void *ga_data;
};

struct buf_S {
    garray_T b_ucmds;
};

extern garray_T ucmds;
extern buf_T *curbuf;
extern window_T *prevwin;

typedef struct {
    char_u *uc_name;
} user_cmd_T;

#define USER_CMD(idx) ((user_cmd_T *)((char *)ucmds.ga_data + (idx) * sizeof(user_cmd_T)))
#define USER_CMD_GA(ga, idx) ((user_cmd_T *)((char *)(ga)->ga_data + (idx) * sizeof(user_cmd_T)))

extern int is_in_cmdwin(void);
extern window_T *prevwin_curwin(void);