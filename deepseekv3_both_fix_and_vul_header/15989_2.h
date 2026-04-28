#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct oparg_T {
    int op_type;
    char regname;
    int prev_opcount;
    int prev_count0;
} oparg_T;

typedef struct cmdarg_T cmdarg_T;
typedef struct pos_T pos_T;
typedef struct window_S window_S;
typedef struct nv_cmd {
    int cmd_flags;
    void *cmd_arg;
    void (*cmd_func)(cmdarg_T *);
} nv_cmd;

#define UNUSED __attribute__((unused))
#define FALSE 0
#define TRUE 1
#define MODE_NORMAL_BUSY 0
#define MODE_SELECT 0
#define MODE_NORMAL 0
#define OP_NOP 0
#define NV_NCW (1<<0)
#define NV_STS (1<<1)
#define NV_SS (1<<2)
#define NV_SSS (1<<3)
#define NV_RL (1<<4)
#define NV_KEEPREG (1<<5)
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
#define K_KENTER 0
#define Ctrl_W 0
#define NL '\n'
#define CAR '\r'
#define ESC '\033'
#define NUL '\0'
#define MOD_MASK_SHIFT (1<<0)
#define UPD_INVERTED 1
#define CA_COMMAND_BUSY (1<<0)

struct pos_T {
    int line;
    int col;
};

struct window_S {
    pos_T w_cursor;
    int w_curswant;
    bool w_p_rl;
    bool w_p_scb;
    bool w_p_crb;
    int w_leftcol;
};

struct cmdarg_T {
    oparg_T *oap;
    int opcount;
    int count0;
    int nchar;
    int cmdchar;
    void *arg;
    int retval;
    char *searchbuf;
};

extern window_S *curwin;
extern oparg_T *oap;
extern int opcount;
extern int finish_op;
extern int restart_edit;
extern int restart_VIsual_select;
extern int VIsual_active;
extern int VIsual_select;
extern int VIsual_select_reg;
extern int km_stopsel;
extern int km_startsel;
extern int mod_mask;
extern int KeyTyped;
extern int KeyStuffed;
extern int msg_nowait;
extern int msg_didout;
extern int msg_col;
extern int did_cursorhold;
extern int ex_normal_busy;
extern int has_mbyte;
extern int State;
extern int dont_scroll;
extern nv_cmd nv_cmds[];
extern int stuff_empty();
extern int readbuf1_empty();
extern int vim_isprintc(int c);
extern int ins_char_typebuf(int c, int mod_mask);
extern int ungetchars(int len);
extern int win_ensure_size();
extern int add_to_showcmd(int c);
extern int find_command(int cmdchar);
extern int check_text_locked(oparg_T *oap);
extern int curbuf_locked();
extern void CLEAR_FIELD(cmdarg_T ca);
extern void clearopbeep(oparg_T *oap);
extern void clearop(oparg_T *oap);
extern void clear_showcmd();
extern void end_visual_mode();
extern void redraw_curbuf_later(int flags);
extern void unshift_special(cmdarg_T *ca);
extern void start_selection();
extern void out_flush();
extern void ui_cursor_shape();
extern void update_mouseshape(int shape);
extern void may_trigger_modechanged();
extern void set_vcount_ca(cmdarg_T *ca, int *set_prevcount);
extern void reset_reg_var();
extern void do_pending_operator(cmdarg_T *ca, int old_col, int force);
extern void normal_cmd_wait_for_msg();
extern void checkpcmark();
extern void mb_adjust_cursor();
extern void validate_cursor();
extern void do_check_scrollbind(int force);
extern void do_check_cursorbind();
extern void showmode();
extern int edit(int mode, int force, long count);
extern int safe_vgetc();
extern int typebuf_maplen();
extern int get_real_state();
extern int normal_cmd_get_count(cmdarg_T *ca, int c, int toplevel, int set_prevcount, int *ctrl_w, int *need_flushbuf);
extern int normal_cmd_needs_more_chars(cmdarg_T *ca, int flags);
extern int normal_cmd_get_more_chars(int idx, cmdarg_T *ca, int *need_flushbuf);
extern int normal_cmd_need_to_wait_for_msg(cmdarg_T *ca, pos_T *old_pos);
extern int vgetc_char;
extern int vgetc_mod_mask;
extern int LANGMAP_ADJUST(int c, int condition);
extern int goto_im();
#define vim_free free