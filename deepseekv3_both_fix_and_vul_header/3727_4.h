#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef unsigned char char_u;
typedef long linenr_T;

typedef struct {
    int lnum;
    int col;
} lpos_T;

typedef struct {
    lpos_T startpos[10];
    lpos_T endpos[10];
} regmmatch_T;

typedef struct {
    char_u *startp[10];
    char_u *endp[10];
} regmatch_T;

typedef struct {
    regmatch_T *reg_match;
    regmmatch_T *reg_mmatch;
    linenr_T reg_firstlnum;
    linenr_T reg_maxline;
    int reg_line_lbr;
} regexec_T;

typedef struct {
    void *sm_match;
    void *sm_mmatch;
    linenr_T sm_firstlnum;
    linenr_T sm_maxline;
    int sm_line_lbr;
} regsubmatch_T;

typedef struct {
    int v_type;
    union {
        char_u *v_string;
        void *v_partial;
        void *v_instr;
        void *v_list;
    } vval;
} typval_T;

typedef int (*fptr_T)(int *, int);

typedef struct {
    int lv_len;
} list_T;

typedef struct {
    list_T sl_list;
} staticList10_T;

typedef struct {
    int fe_evaluate;
    void *fe_argv_func;
    void *fe_partial;
} funcexe_T;

typedef struct {
    void *pt_arg;
} partial_T;

#define REGSUB_COPY 1
#define REGSUB_MAGIC 2
#define REGSUB_BACKSLASH 4
#define MAX_REGSUB_NESTING 10
#define FEAT_EVAL
#define VAR_STRING 1
#define VAR_FUNC 2
#define VAR_PARTIAL 3
#define VAR_INSTR 4
#define VAR_UNKNOWN 5
#define VAR_LIST 6
#define NUMBUFLEN 100
#define K_SPECIAL 128
#define CAR '\r'
#define NL '\n'
#define TAB '\t'
#define Ctrl_H '\b'
#define ESC '\033'
#define NUL '\0'
#define TRUE 1
#define FALSE 0
#define REG_MULTI 1

static regexec_T rex;
static int can_f_submatch;
static regsubmatch_T rsm;
static char_u *eval_result[MAX_REGSUB_NESTING];
static char_u *substitute_instr;
static int has_mbyte;
static int enc_utf8;
static char_u *e_null_argument = "NULL argument";
static char_u *e_damaged_match_string = "damaged match string";
static char_u *e_substitute_nesting_too_deep = "substitute nesting too deep";

#define _(x) x
#define STRLEN(s) strlen((char *)(s))
#define STRCPY(d, s) strcpy((char *)(d), (char *)(s))
#define MB_PTR_ADV(s) (++(s))
#define MB_CHAR2LEN(c) 1
#define MB_PTR2LEN(s) 1
#define MB_PTR2CHAR(s) (*(s))
#define MB_CHAR2BYTES(c, s) (*(s) = (c))
#define utf_ptr2len(s) 1
#define mch_memmove(d, s, n) memmove(d, s, n)
#define CLEAR_FIELD(s) memset(&(s), 0, sizeof(s))
#define VIM_CLEAR(p) do { if (p) { free(p); (p) = NULL; } } while (0)

static int mb_ptr2char(char_u *p) { return *p; }
static int mb_ptr2len(char_u *p) { return 1; }
static int mb_char2len(int c) { return 1; }
static void mb_char2bytes(int c, char_u *buf) { *buf = c; }
static int vim_strchr(char_u *string, int c) { return strchr((char *)string, c) != NULL; }
static void vim_free(void *p) { free(p); }

static int do_upper(int *cc, int c) { *cc = toupper(c); return 0; }
static int do_Upper(int *cc, int c) { *cc = toupper(c); return 0; }
static int do_lower(int *cc, int c) { *cc = tolower(c); return 0; }
static int do_Lower(int *cc, int c) { *cc = tolower(c); return 0; }

static void iemsg(char_u *s) {}
static void emsg(char_u *s) {}
static int prog_magic_wrong(void) { return 0; }
static char_u *reg_getline(linenr_T lnum) { return NULL; }
static char_u *tv_get_string_buf_chk(typval_T *tv, char_u *buf) { return NULL; }
static char_u *vim_strsave(char_u *str) { return str ? strdup((char *)str) : NULL; }
static char_u *vim_strsave_escaped(char_u *src, char_u *esc_chars) { return NULL; }
static void clear_tv(typval_T *varp) {}
static void call_func(char_u *name, int argcount, typval_T *rettv, int argvars, typval_T *argv, funcexe_T *fex) {}
static char_u *partial_name(partial_T *partial) { return NULL; }
static void exe_typval_instr(typval_T *instr, typval_T *rettv) {}
static char_u *exe_substitute_instr(void) { return NULL; }
static char_u *eval_to_string(char_u *arg, int evaluate, int want_string) { return NULL; }
static void fill_submatch_list(void) {}
static void clear_submatch_list(staticList10_T *lp) {}