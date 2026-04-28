#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef long linenr_T;
typedef unsigned char char_u;

typedef struct {
    int ga_len;
    char_u **ga_data;
    int ga_maxlen;
    int ga_itemsize;
    int ga_growsize;
} garray_T;

typedef enum {
    CMD_def,
    CMD_block,
    CMD_unknown
} CMD_index;

typedef struct exarg {
    int (*getline)(void *);
    void *cookie;
    CMD_index cmdidx;
    char_u *nextcmd;
    char_u **cmdlinep;
} exarg_T;

typedef enum {
    GETLINE_CONCAT_CONT,
    GETLINE_CONCAT_CONTBAR,
    GETLINE_NONE
} getline_opt_T;

extern int SOURCING_LNUM;
extern int need_wait_return;
extern int KeyTyped;
extern int msg_scroll;
extern int Rows;
extern int lines_left;
extern int did_emsg;
extern int p_verbose;

#define STRLEN(s) strlen((char *)(s))
#define STRNCMP(s1, s2, n) strncmp((char *)(s1), (char *)(s2), (n))
#define STRCMP(s1, s2) strcmp((char *)(s1), (char *)(s2))
#define VIM_ISWHITE(c) ((c) == ' ' || (c) == '\t')
#define ASCII_ISALPHA(c) (((c) >= 'A' && (c) <= 'Z') || ((c) >= 'a' && (c) <= 'z'))
#define ASCII_ISALNUM(c) (ASCII_ISALPHA(c) || ((c) >= '0' && (c) <= '9'))
#define VIM_CLEAR(p) do { if (p) { free(p); (p) = NULL; } } while (0)
#define FAIL 1
#define OK 0
#define TRUE 1
#define FALSE 0
#define NUL '\0'
#define _(s) s

static char *e_missing_heredoc_end_marker_str = "Missing heredoc end marker";
static char *e_missing_end_block = "Missing end block";
static char *e_missing_enddef = "Missing enddef";
static char *e_missing_endfunction = "Missing endfunction";
static char *e_mismatched_endfunction = "Mismatched endfunction";
static char *e_mismatched_enddef = "Mismatched enddef";
static char *e_function_nesting_too_deep = "Function nesting too deep";
static char *e_text_found_after_str_str = "Text found after %s: %s";

static int ga_grow_inner(garray_T *ga, int n) {
    int new_maxlen = ga->ga_maxlen + (n > ga->ga_growsize ? n : ga->ga_growsize);
    char_u **new_data = realloc(ga->ga_data, new_maxlen * sizeof(char_u *));
    if (!new_data) return FAIL;
    ga->ga_data = new_data;
    ga->ga_maxlen = new_maxlen;
    return OK;
}

#define ga_init2(ga, itemsize, growsize) do { \
    (ga)->ga_itemsize = (itemsize); \
    (ga)->ga_growsize = (growsize); \
    (ga)->ga_data = NULL; \
    (ga)->ga_maxlen = 0; \
    (ga)->ga_len = 0; \
} while (0)

#define ga_init(ga) ga_init2((ga), sizeof(char_u *), 80)
#define ga_grow(ga, n) ((ga)->ga_len + (n) <= (ga)->ga_maxlen ? OK : ga_grow_inner((ga), (n)))
#define ga_concat(ga, s) do { \
    size_t len = STRLEN(s); \
    if ((ga)->ga_len + len >= (ga)->ga_maxlen) { \
        if (ga_grow(ga, len) == FAIL) break; \
    } \
    memcpy((ga)->ga_data + (ga)->ga_len, (s), len); \
    (ga)->ga_len += len; \
} while (0)

static char_u *vim_strsave(char_u *s) {
    if (!s) return NULL;
    size_t len = STRLEN(s) + 1;
    char_u *p = malloc(len);
    if (p) memcpy(p, s, len);
    return p;
}

static char_u *vim_strnsave(char_u *s, size_t len) {
    char_u *p = malloc(len + 1);
    if (p) {
        memcpy(p, s, len);
        p[len] = NUL;
    }
    return p;
}

static char_u *vim_strchr(char_u *s, int c) {
    return (char_u *)strchr((char *)s, c);
}

static char_u *skipwhite(char_u *p) {
    while (VIM_ISWHITE(*p)) ++p;
    return p;
}

static char_u *skiptowhite(char_u *p) {
    while (*p && !VIM_ISWHITE(*p)) ++p;
    return p;
}

static linenr_T get_sourced_lnum(int (*getline)(void *), void *cookie) {
    return 0;
}

static char_u *get_function_line(exarg_T *eap, void *lines_to_free, int indent, getline_opt_T options) {
    return NULL;
}

static int checkforcmd(char_u **pp, char *cmd, int len) {
    return 0;
}

static int checkforcmd_noparen(char_u **pp, char *cmd, int len) {
    return 0;
}

static int is_function_cmd(char_u **pp) {
    return 0;
}

static int eval_fname_script(char_u *p) {
    return 0;
}

static char_u *trans_function_name(char_u **pp, void *arg1, int arg2, int arg3, void *arg4, void *arg5, void *arg6) {
    return NULL;
}

static char_u *skip_range(char_u *p, int skip_comma, int *amount) {
    return p;
}

static void emsg(char *s) {}
static void semsg(char *s, ...) {}
static void give_warning2(char_u *s1, char_u *s2, int flag) {}
static void vim_free(void *p) { free(p); }