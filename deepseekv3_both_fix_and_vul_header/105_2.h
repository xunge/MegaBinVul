#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

typedef unsigned char char_u;

#define FALSE 0
#define TRUE 1
#define FAIL 0
#define OK 1
#define NUL '\0'
#define MAXLNUM 0x7fffffff
#define LAST_TAB_NR 9999
#define RE_MAGIC 1
#define CMOD_BROWSE (1 << 0)
#define CMOD_CONFIRM (1 << 1)
#define CMOD_KEEPMARKS (1 << 2)
#define CMOD_KEEPALT (1 << 3)
#define CMOD_KEEPPATTERNS (1 << 4)
#define CMOD_KEEPJUMPS (1 << 5)
#define CMOD_HIDE (1 << 6)
#define CMOD_LOCKMARKS (1 << 7)
#define CMOD_LEGACY (1 << 8)
#define CMOD_NOAUTOCMD (1 << 9)
#define CMOD_NOSWAPFILE (1 << 10)
#define CMOD_SANDBOX (1 << 11)
#define CMOD_SILENT (1 << 12)
#define CMOD_ERRSILENT (1 << 13)
#define CMOD_UNSILENT (1 << 14)
#define CMOD_VIM9CMD (1 << 15)
#define WSP_ABOVE (1 << 0)
#define WSP_BELOW (1 << 1)
#define WSP_BOT (1 << 2)
#define WSP_VERT (1 << 3)
#define WSP_TOP (1 << 4)
#define ADDR_TABS 1
#define ASCII_ISALPHA(c) (isalpha(c))
#define VIM_ISWHITE(c) ((c) == ' ' || (c) == '\t')

typedef struct {
    int cmod_flags;
    int cmod_split;
    int cmod_tab;
    int cmod_verbose;
    int cmod_filter_force;
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
    struct {
        int lnum;
    } w_cursor;
} exarg_T;

typedef struct {
    struct {
        int ml_line_count;
    } b_ml;
} buf_T;

typedef struct {
    struct {
        int lnum;
    } w_cursor;
    buf_T *b_ml;
} curwin_T;

typedef struct {
    int index;
} tabpage_T;

extern int exmode_active;
extern int ex_pressedreturn;
extern int sticky_cmdmod_flags;
extern curwin_T *curwin;
extern buf_T *curbuf;
extern tabpage_T *curtab;
extern const char *e_command_modifier_without_command;
extern const char *e_legacy_must_be_followed_by_command;
extern const char *e_invalid_range;
extern const char *e_vim9cmd_must_be_followed_by_command;

int in_vim9script(void);
int comment_start(char_u *cmd, int starts_with_colon);
int has_cmdmod(cmdmod_T *cmod, int unused);
int checkforcmd_noparen(char_u **cmd, const char *name, int len);
int checkforcmd_opt(char_u **cmd, const char *name, int len, int opt);
int ends_excmd(int c);
int ends_excmd2(char_u *p, char_u *cmd);
char_u *skip_range(char_u *cmd, int skip, void *unused);
char_u *skip_vimgrep_pat(char_u *p, void *unused1, void *unused2);
char_u *skip_vimgrep_pat_ext(char_u *p, char_u **reg_pat, void *unused1, char_u **nulp, int *c);
char_u *skipwhite(char_u *p);
char_u *vim_strchr(char_u *str, int c);
void *vim_regcomp(char_u *pattern, int flags);
int getline_equal(void *getline1, void *cookie1, void *getline2);
void *getexmodeline(void);
void *getexline(void);
long get_address(exarg_T *eap, char_u **cmd, int addr_type, int skip, int skip_only, int forceit, int amount);
int tabpage_index(tabpage_T *tp);
void CLEAR_POINTER(void *p);
#define STRNCMP strncmp
#define STRLEN strlen
#define STRCPY strcpy
#define mch_memmove memmove
#define _(x) x
#define vim_isdigit isdigit