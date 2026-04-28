#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>

typedef unsigned char char_u;
typedef int bool;
#define FALSE 0
#define TRUE 1

typedef struct ucmd_S ucmd_T;
typedef struct garray_S garray_T;
typedef struct window_S window_T;
typedef struct buf_S buf_T;

struct ucmd_S {
    char_u *uc_name;
    int uc_argt;
    long uc_def;
    int uc_addr_type;
    int uc_compl;
    char_u *uc_compl_arg;
    char_u *uc_rep;
    void *uc_script_ctx;
};

struct garray_S {
    int ga_len;
    void *ga_data;
};

struct window_S {
    buf_T *w_buffer;
};

struct buf_S {
    garray_T b_ucmds;
};

extern garray_T ucmds;
extern buf_T *curbuf;
extern window_T *prevwin;
extern int got_int;
extern char_u IObuff[];
extern int Columns;
extern int p_verbose;

#define USER_CMD_GA(gap, i) ((ucmd_T *)((gap)->ga_data) + (i))
#define STRLEN strlen
#define STRNCMP strncmp
#define STRCPY strcpy

#define EX_BANG 0x01
#define EX_REGSTR 0x02
#define EX_TRLBAR 0x04
#define EX_RANGE 0x08
#define EX_COUNT 0x10
#define EX_DFLALL 0x20
#define EX_EXTRA 0x40
#define EX_NOSPC 0x80
#define EX_NEEDARG 0x100

enum {
    ADDR_NONE,
    ADDR_LINES,
};

typedef struct {
    int expand;
    char *shortname;
} addr_complete_T;

typedef struct {
    int expand;
    char *name;
} cmd_complete_T;

extern addr_complete_T addr_type_complete[];
extern cmd_complete_T command_complete[];

#define HL_ATTR(x) (x)
#define HLF_D 0

#define _(x) x

window_T *prevwin_curwin(void);
int is_in_cmdwin(void);
int message_filtered(char_u *name);
void msg_puts_title(char *str);
void msg_putchar(char c);
void msg_outtrans_attr(char_u *str, int attr);
void msg_outtrans(char_u *str);
void msg_outtrans_special(char_u *str, int attr, int maxlen);
void msg(char *str);
void out_flush(void);
void ui_breakcheck(void);
void last_set_msg(void *ctx);