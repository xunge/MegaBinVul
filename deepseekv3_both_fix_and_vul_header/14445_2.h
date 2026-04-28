#include <stddef.h>
#include <string.h>
#include <ctype.h>

typedef unsigned char char_u;
typedef int cmdidx_T;
typedef int cctx_T;

#define UNUSED
#define FALSE 0
#define TRUE 1
#define NUL '\0'
#define CMD_SIZE 0
#define CMD_eval 0
#define CMD_block 0
#define CMD_var 0
#define CMD_k 0
#define CMD_substitute 0
#define CMD_Next 0
#define CMD_bang 0
#define CMD_star 0
#define CMD_Print 0
#define CMD_final 0
#define CMD_finally 0
#define CMD_increment 0
#define CMD_decrement 0
#define EXFLAG_LIST 0
#define EXFLAG_PRINT 0
#define EX_NONWHITE_OK 0
#define CPO_STAR 0
#define OK 0
#define FEAT_EVAL 0

#define _(x) x
#define e_command_str_not_followed_by_white_space_str "E492: Not an editor command: %s %s"

typedef struct {
    char_u *cmd;
    int cmdidx;
    int flags;
    int skip;
} exarg_T;

typedef struct {
    const char *cmd_name;
    int cmd_argt;
} CommandName;

extern CommandName cmdnames[];
extern int cmdidxs1[];
extern int cmdidxs2[26][26];
extern char_u *p_cpo;
extern int emsg_silent;
extern int command_count;

static inline int CharOrdLow(int c) { return c - 'a'; }
static inline int IS_WHITE_OR_NUL(int c) { return c == NUL || isspace(c); }

char_u *skip_option_env_lead(char_u *);
char_u *vim_strchr(char_u *, int);
char_u *skipwhite(char_u *);
int ends_excmd(int);
char_u *to_name_const_end(char_u *);
char_u *to_name_end(char_u *, int);
int valid_yank_reg(int, int);
char_u *skip_var_list(char_u *, int, int *, int *, int);
int skip_expr(char_u **, int *);
int assignment_len(char_u *, int *);
int in_vim9script(void);
char_u *find_ucmd(exarg_T *, char_u *, int *, int *, int *);
char_u *vim_strnsave(char_u *, size_t);
void semsg(const char *, char_u *, char_u *);
void vim_free(char_u *);
void iemsg(const char *);
void getout(int);
#define STRNCMP strncmp
#define ASCII_ISALPHA isalpha
#define ASCII_ISALNUM isalnum
#define ASCII_ISLOWER islower
#define ASCII_ISUPPER isupper