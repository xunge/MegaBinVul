#include <stddef.h>

#define FALSE 0
#define TRUE 1
#define NUL 0
#define ESC 27
#define Ctrl_C 3
#define Ctrl_L 12
#define KE_NOP 0
#define KS_EXTRA 0
#define K_SPECIAL 0
#define K_CANCEL 0
#define RM_YES 0
#define MAXMAPLEN 0
#define SHOWCMD_COLS 0
#define FLUSH_INPUT 0
#define KEYLEN_PART_KEY 0
#define KKPS_ENABLED 0
#define VIM_ISWHITE(c) ((c) == ' ' || (c) == '\t')

typedef unsigned char char_u;
typedef int colnr_T;
typedef int linenr_T;

typedef enum {
    MODE_NORMAL,
    MODE_INSERT,
    MODE_CMDLINE,
    MODE_LANGMAP,
    MODE_HITRETURN
} Mode;

typedef enum {
    EXMODE_NORMAL,
    EXMODE_VIM
} ExMode;

typedef enum {
    map_result_retry,
    map_result_fail,
    map_result_get
} map_result_T;

typedef struct {
    int tb_off;
    int tb_len;
    int tb_maplen;
    int tb_buflen;
    int tb_silent;
    char_u *tb_buf;
    int tb_no_abbr_cnt;
    int tb_noremap[];
} typebuf_T;

typedef struct {
    int w_wcol;
    int w_wrow;
    int w_width;
    struct {
        linenr_T lnum;
        colnr_T col;
    } w_cursor;
    int w_cline_row;
    int w_p_wrap;
} win_T;

typedef struct {
    int in_use;
} gui_T;

typedef struct {
    int cts_vcol;
    char_u *cts_ptr;
} chartabsize_T;

typedef struct {
    int *cmdbuff;
} cmdline_info_T;

static int vgetc_busy;
static int ex_normal_busy;
static int KeyStuffed;
static int typebuf_was_empty;
static int typeahead_char;
static int got_int;
static int cmd_silent;
static int KeyTyped;
static int KeyNoremap;
static int no_mapping;
static int kitty_protocol_state;
static int p_timeout;
static int p_ttimeout;
static int p_ttm;
static int p_tm;
static int p_im;
static int p_smd;
static int p_lz;
static int mode_displayed;
static int must_redraw;
static int need_wait_return;
static int exmode_active;
static int pending_exmode_active;
static int msg_silent;
static int redraw_cmdline;
static int vgetc_im_active;
static int did_ai;
static int has_mbyte;
static int cmdwin_type;
static win_T *curwin;
static typebuf_T typebuf;
static gui_T gui;
static int State;
static int mode_displayed;
static int mode_deleted;
static int shape_changed;
static cmdline_info_T cmdline_info;

static void init_typebuf(void);
static void start_stuff(void);
static void check_end_reg_executing(int advance);
static int read_readbuffers(int advance);
static void line_breakcheck(void);
static void ui_breakcheck(void);
static int inchar(char_u *buf, int buflen, long wait_time);
static void flush_buffers(int flags);
static void gotchars(char_u *buf, int len);
static map_result_T handle_mapping(int *keylen, int *timedout, int *mapdepth);
static void del_typebuf(int count, int offset);
static void unshowmode(int force);
static void validate_cursor(void);
static char_u *skipwhite(char_u *p);
static char_u *ml_get_curline(void);
static int lbr_chartabsize(chartabsize_T *cts);
static void init_chartabsize_arg(chartabsize_T *cts, win_T *wp, linenr_T lnum, colnr_T col, char_u *line, char_u *ptr);
static void clear_chartabsize_arg(chartabsize_T *cts);
static int mb_head_off(char_u *base, char_u *p);
static int mb_ptr2len(char_u *p);
static int mb_ptr2cells(char_u *p);
static int ptr2cells(char_u *p);
static void setcursor(void);
static void out_flush(void);
static void edit_putchar(int c, int highlight);
static void push_showcmd(void);
static int add_to_showcmd(int c);
static void pop_showcmd(void);
static void putcmdline(int c, int highlight);
static void unputcmdline(void);
static void update_screen(int type);
static void showmode(void);
static void gui_update_cursor(int force, int clear);
static int curwin_col_off(void);
static cmdline_info_T *get_cmdline_info(void);
static void edit_unputchar(void);