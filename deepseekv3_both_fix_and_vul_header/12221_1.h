#include <limits.h>
#include <stddef.h>

#define FALSE 0
#define TRUE 1
#define K_DEL 0
#define K_KDEL 0
#define K_BS 0
#define K_LEFTMOUSE 0
#define Ctrl_H 0
#define Ctrl_C 0
#define ESC 0
#define CAR 0
#define NL 0

extern int msg_silent;
extern int msg_row;
extern int msg_col;
extern int no_mapping;
extern int allow_keys;
extern int dont_scroll;
extern int mouse_row;
extern int skip_redraw;
extern int do_redraw;
extern int exmode_active;
extern int cmdline_row;

void windgoto(int row, int col);
int safe_vgetc(void);
void msg_putchar(int c);
void msg_puts(const char *str);
void stuffcharReadbuff(char c);

#define VIM_ISDIGIT(c) ((c) >= '0' && (c) <= '9')
#define USE_ON_FLY_SCROLL