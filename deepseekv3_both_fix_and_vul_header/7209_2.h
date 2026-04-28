#include <stddef.h>

#define TRUE 1
#define FALSE 0

typedef struct tabpage_S tabpage_T;
struct tabpage_S {
    tabpage_T *tp_next;
};

extern tabpage_T *first_tabpage;
extern tabpage_T *curtab;

extern int text_locked(void);
extern void text_locked_msg(void);
extern void beep_flush(void);
extern tabpage_T *find_tabpage(int n);
extern void goto_tabpage_tp(tabpage_T *tp, int flag, int noenter);
extern int gui_use_tabline(void);
extern void gui_mch_set_curtab(int idx);
extern int tabpage_index(tabpage_T *tp);

#define CHECK_CMDWIN
#define FEAT_GUI_TABLINE