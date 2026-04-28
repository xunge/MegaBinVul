#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define Ctrl_V 22
#define VE_BLOCK 1
#define TAB '\t'
#define INVERTED 1
#define NUL '\0'

struct cursor {
    long lnum;
};

struct window {
    int w_p_cole;
    struct cursor w_cursor;
    long w_virtcol;
    int w_redr_type;
    long w_old_cursor_lnum;
    long w_old_visual_lnum;
};

struct clip_star {
    char vmode;
};

static int VIsual_mode;
static bool VIsual_active;
static bool VIsual_reselect;
static bool redraw_cmdline;
static int p_smd;
static int msg_silent;
static struct cursor VIsual;
static struct window *curwin;
static struct clip_star clip_star;

static void trigger_modechanged(void);
static void validate_virtcol(void);
static void coladvance(long col);
static int gchar_cursor(void);
static int get_ve_flags(void);
static void setmouse(void);
static bool conceal_cursor_line(struct window *win);
static void conceal_check_cursor_line(bool was_concealed);
static void foldAdjustVisual(void);