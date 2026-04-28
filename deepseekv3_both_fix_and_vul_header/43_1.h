#include <stddef.h>

#define UNUSED
#define TRUE 1
#define FALSE 0
#define NUL '\0'
#define ESC '\033'
#define Ctrl_O 15
#define Ctrl_R 18
#define GOTO_NORMAL_MODE 1
#define CMDLINE_NOT_CHANGED 0
#define FEAT_EVAL
#define USE_ON_FLY_SCROLL

extern int dont_scroll;
extern int no_mapping;
extern int allow_keys;
extern int extra_char;
extern int new_cmdpos;
extern int KeyTyped;
extern int cmdline_star;

struct cmdline_info {
    int cmdfirstc;
    int cmdlen;
    int cmdpos;
    char *cmdbuff;
} ccline;

int plain_vgetc(void);
void putcmdline(char c, int flag);
void cmdline_paste(int c, int flag1, int flag2);
int get_expr_register(void);
int aborting(void);
void beep_flush(void);
void redrawcmd(void);