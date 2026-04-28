#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned char char_u;
typedef int bool;

#define FALSE 0
#define TRUE 1
#define FAIL 0
#define OK 1
#define NUL '\0'
#define MAXLNUM 0
#define LAST_TAB_NR 0
#define RE_MAGIC 0
#define CMOD_BROWSE 0
#define CMOD_CONFIRM 0
#define CMOD_KEEPMARKS 0
#define CMOD_KEEPALT 0
#define CMOD_KEEPPATTERNS 0
#define CMOD_KEEPJUMPS 0
#define CMOD_HIDE 0
#define CMOD_LOCKMARKS 0
#define CMOD_LEGACY 0
#define CMOD_NOAUTOCMD 0
#define CMOD_NOSWAPFILE 0
#define CMOD_SANDBOX 0
#define CMOD_SILENT 0
#define CMOD_ERRSILENT 0
#define CMOD_UNSILENT 0
#define CMOD_VIM9CMD 0
#define WSP_ABOVE 0
#define WSP_BELOW 0
#define WSP_BOT 0
#define WSP_VERT 0
#define WSP_TOP 0
#define ADDR_TABS 0
#define ASCII_ISALPHA(c) isalpha(c)
#define VIM_ISWHITE(c) isspace(c)
#define CLEAR_POINTER(p) memset((p), 0, sizeof(*(p)))
#define STRNCMP(s1, s2, n) strncmp((const char *)(s1), (const char *)(s2), (n))

typedef struct {
    int cmod_flags;
    int cmod_split;
    int cmod_filter_force;
    int cmod_tab;
    int cmod_verbose;
    struct {
        void *regprog;
    } cmod_filter_regmatch;
} cmdmod_T;

typedef struct {
    char_u *cmd;
    char_u *nextcmd;
    int skip;
    void *getline;
    void *cookie;
} exarg_T;

typedef struct {
    struct {
        int lnum;
    } w_cursor;
} win_T;

typedef struct {
    struct {
        int ml_line_count;
    } b_ml;
} buf_T;

typedef struct {
    int index;
} tabpage_T;

extern int sticky_cmdmod_flags;
extern int exmode_active;
extern int ex_pressedreturn;
extern win_T *curwin;
extern buf_T *curbuf;
extern tabpage_T *curtab;
extern int in_vim9script(void);
extern int comment_start(char_u *cmd, int starts_with_colon);
extern int has_cmdmod(cmdmod_T *cmod, int flag);
extern char *_(const char *str);
extern char *e_command_modifier_without_command;
extern char *e_legacy_must_be_followed_by_command;
extern char *e_invalid_range;
extern char *e_vim9cmd_must_be_followed_by_command;
extern char_u *vim_strchr(const char_u *str, int c);
extern char_u *skipwhite(char_u *p);
extern char_u *skip_range(char_u *p, int flag, int *lnump);
extern int checkforcmd_noparen(char_u **pp, const char *cmd, int len);
extern int checkforcmd_opt(char_u **pp, const char *cmd, int len, int opt);
extern int ends_excmd(int c);
extern int ends_excmd2(char_u *p, char_u *cmd);
extern char_u *skip_vimgrep_pat(char_u *p, char_u **pat, int *flags);
extern char_u *skip_vimgrep_pat_ext(char_u *p, char_u **pat, int *flags, char_u **nulp, int *c);
extern void *vim_regcomp(char_u *pat, int flags);
extern int getline_equal(void *getline, void *cookie, void *func);
extern void *getexmodeline;
extern void *getexline;
extern long get_address(exarg_T *eap, char_u **pp, int type, int skip, int skip_only, int silent, int lnump);
extern int tabpage_index(tabpage_T *tp);
extern void mch_memmove(void *dest, const void *src, size_t n);
extern int vim_isdigit(int c);