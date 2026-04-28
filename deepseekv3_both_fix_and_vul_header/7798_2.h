#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define UNUSED
#define FALSE 0
#define TRUE 1
#define MODE_NORMAL_BUSY 0
#define MODE_SELECT 0
#define MODE_NORMAL 0
#define OP_NOP 0
#define NV_NCW 0
#define NV_STS 0
#define NV_SS 0
#define NV_SSS 0
#define NV_RL 0
#define NV_KEEPREG 0
#define K_ZERO 0
#define K_IGNORE 0
#define K_MOUSEMOVE 0
#define K_CURSORHOLD 0
#define K_LEFT 0
#define K_RIGHT 0
#define K_S_LEFT 0
#define K_S_RIGHT 0
#define K_C_LEFT 0
#define K_C_RIGHT 0
#define Ctrl_W 0
#define NL '\n'
#define CAR '\r'
#define K_KENTER 0
#define ESC '\033'
#define NUL '\0'
#define INVERTED 0
#define MOD_MASK_SHIFT (1<<0)
#define CA_COMMAND_BUSY (1<<0)

typedef struct pos_T {
    int line;
    int col;
} pos_T;

typedef struct window_S {
    pos_T w_cursor;
    int w_curswant;
    bool w_p_rl;
    bool w_p_scb;
    bool w_p_crb;
} window_S;

typedef struct oparg_T {
    int op_type;
    char regname;
    int prev_opcount;
    int prev_count0;
} oparg_T;

typedef struct cmdarg_T {
    oparg_T *oap;
    int opcount;
    int count0;
    int nchar;
    int cmdchar;
    void *arg;
    int retval;
    char *searchbuf;
} cmdarg_T;

typedef struct nv_cmd {
    int cmd_flags;
    void *cmd_arg;
    void (*cmd_func)(cmdarg_T *);
} nv_cmd;

extern window_S *curwin;
extern int State;
extern int finish_op;
extern int opcount;
extern int restart_edit;
extern int restart_VIsual_select;
extern int VIsual_active;
extern int VIsual_select;
extern int VIsual_select_reg;
extern int km_startsel;
extern int km_stopsel;
extern int mod_mask;
extern int KeyTyped;
extern int KeyStuffed;
extern int did_cursorhold;
extern int ex_normal_busy;
extern int msg_didout;
extern int msg_col;
extern int msg_nowait;
extern int has_mbyte;
extern int old_mapped_len;
extern nv_cmd nv_cmds[];
extern void *curbuf;
extern int vgetc_char;
extern int vgetc_mod_mask;
extern int dont_scroll;

void CLEAR_FIELD(cmdarg_T ca);
int typebuf_maplen(void);
int safe_vgetc(void);
void LANGMAP_ADJUST(int c, int condition);
int get_real_state(void);
int vim_isprintc(int c);
int ins_char_typebuf(int c, int mod_mask);
void ungetchars(int len);
void win_ensure_size(void);
int add_to_showcmd(int c);
int normal_cmd_get_count(cmdarg_T *ca, int c, int toplevel, int set_prevcount, int *ctrl_w, int *need_flushbuf);
int find_command(int cmdchar);
void clearopbeep(oparg_T *oap);
int text_locked(void);
void text_locked_msg(void);
int curbuf_locked(void);
void end_visual_mode(void);
void redraw_curbuf_later(int flags);
void unshift_special(cmdarg_T *ca);
int normal_cmd_needs_more_chars(cmdarg_T *ca, int flags);
int normal_cmd_get_more_chars(int idx, cmdarg_T *ca, int *need_flushbuf);
void out_flush(void);
int goto_im(void);
void start_selection(void);
void clearop(oparg_T *oap);
void reset_reg_var(void);
void do_pending_operator(cmdarg_T *ca, int old_col, int condition);
int normal_cmd_need_to_wait_for_msg(cmdarg_T *ca, pos_T *old_pos);
void normal_cmd_wait_for_msg(void);
void may_trigger_modechanged(void);
void ui_cursor_shape(void);
void update_mouseshape(int shape);
void clear_showcmd(void);
void checkpcmark(void);
void mb_adjust_cursor(void);
void validate_cursor(void);
void do_check_scrollbind(int condition);
void do_check_cursorbind(void);
int term_job_running(void *term);
int edit(int mode, int condition, long count);
void showmode(void);
int stuff_empty(void);
int readbuf1_empty(void);
void set_vcount_ca(cmdarg_T *ca, int *set_prevcount);
void vim_free(void *ptr);