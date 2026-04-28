#include <string.h>
#include <stddef.h>

typedef unsigned char char_u;
typedef long linenr_T;

typedef struct {
    int cmdidx;
    char_u *(*getline)(int, void *, int, int);
    void *cookie;
    char_u **cmdlinep;
    char_u *nextcmd;
    char_u *arg;
} exarg_T;

typedef struct {
    char_u **ga_data;
    int ga_len;
    int ga_maxlen;
    int ga_itemsize;
    int ga_growsize;
} garray_T;

typedef enum {
    CMD_def,
    CMD_block,
    CMD_function
} CMD_index;

typedef enum {
    GETLINE_CONCAT_CONTBAR,
    GETLINE_CONCAT_CONT,
    GETLINE_NONE
} getline_opt_T;

extern linenr_T SOURCING_LNUM;
#define STRLEN(s) strlen((const char *)(s))
#define VIM_ISWHITE(c) ((c) == ' ' || (c) == '\t')
#define ASCII_ISALPHA(c) (((c) >= 'A' && (c) <= 'Z') || ((c) >= 'a' && (c) <= 'z'))
#define ASCII_ISALNUM(c) (ASCII_ISALPHA(c) || ((c) >= '0' && (c) <= '9'))
#define STRNCMP(s1, s2, n) strncmp((const char *)(s1), (const char *)(s2), (n))
#define STRCMP(s1, s2) strcmp((const char *)(s1), (const char *)(s2))
#define NUL '\0'
#define FALSE 0
#define TRUE 1
#define FAIL 0
#define OK 1
#define Rows 24

extern int KeyTyped;
extern int msg_scroll;
extern int lines_left;
extern int did_emsg;
extern int p_verbose;
extern int need_wait_return;

#define _(s) s
#define e_missing_heredoc_end_marker_str "Missing heredoc end marker"
#define e_missing_end_block "Missing end block"
#define e_missing_enddef "Missing enddef"
#define e_text_found_after_enddef_str "Text found after enddef: %s"
#define e_mismatched_endfunction "Mismatched endfunction"
#define e_mismatched_enddef "Mismatched enddef"
#define e_function_nesting_too_deep "Function nesting too deep"

#define VIM_CLEAR(p) do { if (p) { vim_free(p); (p) = NULL; } } while (0)

static linenr_T get_sourced_lnum(char_u *(*getline)(int, void *, int, int), void *cookie);
static char_u *getcmdline(int, long, int, getline_opt_T);
static char_u *vim_strchr(const char_u *, int);
static char_u *vim_strsave(char_u *);
static char_u *vim_strnsave(const char_u *, size_t);
static char_u *skipwhite(char_u *);
static char_u *skiptowhite(char_u *);
static char_u *skip_range(char_u *, int, char_u **);
static int checkforcmd(char_u **, const char *, int);
static int checkforcmd_noparen(char_u **, const char *, int);
static int is_function_cmd(char_u **);
static int eval_fname_script(char_u *);
static char_u *trans_function_name(char_u **, char_u *, int, int, char_u **, char_u **, char_u **);
static void ga_init2(garray_T *, int, int);
static int ga_grow(garray_T *, int);
static void ga_concat(garray_T *, char_u *);
static void ga_init(garray_T *);
static void vim_free(void *);
static void emsg(const char *);
static void semsg(const char *, const char *);
static void give_warning2(char_u *, char_u *, int);