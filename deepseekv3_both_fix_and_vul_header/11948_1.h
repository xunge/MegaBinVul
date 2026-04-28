#include <stddef.h>
#include <stdint.h>
#include <string.h>

typedef unsigned char char_u;

typedef struct pos_T {
    int dummy;
} pos_T;

typedef struct buf_T {
    int b_scanned;
    char_u *b_p_cpt;
    struct buf_T *b_next;
} buf_T;

typedef struct compl_T {
    struct compl_T *cp_next;
    struct compl_T *cp_prev;
} compl_T;

#define FALSE 0
#define TRUE 1
#define FAIL (-1)
#define NUL '\0'

#define CTRL_X_NORMAL 0
#define CTRL_X_PATH_PATTERNS 1
#define CONT_LOCAL 1

#define INS_COMPL_CPT_END 0
#define INS_COMPL_CPT_CONT 1

typedef struct ins_compl_next_state_T {
    int found_all;
    buf_T *ins_buf;
    char_u *e_cpt_copy;
    char_u *e_cpt;
    pos_T last_match_pos;
    pos_T first_match_pos;
    pos_T *cur_match_pos;
    int set_match_pos;
} ins_compl_next_state_T;

static int compl_started;
static int ctrl_x_mode;
static compl_T *compl_curr_match;
static compl_T *compl_old_match;
static char_u *compl_pattern;
static int compl_dir_forward();
static int compl_interrupted;
static int got_int;
static int compl_cont_status;
static buf_T *curbuf;
static buf_T *first_buffer;

#define CLEAR_FIELD(field) memset(&(field), 0, sizeof(field))
#define FOR_ALL_BUFFERS(buf) for (buf = first_buffer; buf != NULL; buf = buf->b_next)

static char_u *vim_strsave(char_u *str);
static void vim_free(void *ptr);
static int ctrl_x_mode_normal();
static int ctrl_x_mode_line_or_eval();
static int ctrl_x_mode_not_default();
static int process_next_cpt_value(ins_compl_next_state_T *st, int *type, pos_T *ini);
static int get_next_completion_match(int type, ins_compl_next_state_T *st, pos_T *ini);
static void ins_compl_check_keys(int count, int in_compl_func);
static int ins_compl_make_cyclic();
static void may_trigger_modechanged();
static int buf_valid(buf_T *buf);