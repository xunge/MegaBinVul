#include <stdbool.h>

#define TRUE 1
#define FALSE 0

typedef struct buf_T buf_T;
typedef struct win_T win_T;

struct win_T {
    buf_T *w_buffer;
    int w_p_cole;
    struct {
        int lnum;
    } w_cursor;
};

extern win_T *curwin;
extern buf_T *curbuf;
extern bool VIsual_active;
extern bool need_mouse_correct;
extern bool need_cursor_line_redraw;
extern bool msg_scrolled;
extern const char *e_not_allowed_to_enter_popup_window;

#define FEAT_CONCEAL
#define FEAT_PROP_POPUP
#define FEAT_GUI

#define ERROR_IF_ANY_POPUP_WINDOW 0

void emsg(const char *msg);
const char *_(const char *str);
bool text_locked(void);
void beep_flush(void);
void text_locked_msg(void);
bool curbuf_locked(void);
void reset_VIsual_and_resel(void);
bool popup_is_popup(win_T *wp);
bool win_valid(win_T *wp);
void redrawWinline(win_T *wp, int lnum);
void win_enter(win_T *wp, bool enter);