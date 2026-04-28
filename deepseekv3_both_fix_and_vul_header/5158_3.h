#include <stddef.h>
#include <stdint.h>

#define FAIL 0
#define OK 1

typedef struct term_T term_T;
typedef struct VTerm VTerm;
typedef struct VTermScreen VTermScreen;
typedef struct VTermState VTermState;
typedef struct VTermValue VTermValue;
typedef struct VTermColor {
    uint8_t red, green, blue;
} VTermColor;
typedef struct VTermPos {
    int row, col;
} VTermPos;
typedef struct VTermRect {
    int start_row, end_row, start_col, end_col;
} VTermRect;
typedef enum VTermProp {
    VTERM_PROP_CURSORVISIBLE = 0,
    VTERM_PROP_CURSORBLINK,
    VTERM_PROP_ALTSCREEN,
    VTERM_PROP_TITLE,
    VTERM_PROP_ICONNAME,
    VTERM_PROP_REVERSE,
    VTERM_PROP_CURSORSHAPE,
    VTERM_PROP_MOUSE,
    VTERM_PROP_FOCUSREPORT
} VTermProp;

typedef struct VTermAllocator {
    void *(*malloc)(size_t size, void *user);
    void (*free)(void *mem, void *user);
} VTermAllocator;

typedef struct VTermScreenCallbacks {
    int (*damage)(VTermRect rect, void *user);
    int (*moverect)(VTermRect dest, VTermRect src, void *user);
    int (*movecursor)(VTermPos pos, VTermPos oldpos, int visible, void *user);
    int (*settermprop)(VTermProp prop, VTermValue *val, void *user);
    int (*bell)(void *user);
    int (*resize)(int rows, int cols, void *user);
} VTermScreenCallbacks;

typedef struct VTermParserFallbacks {
    void (*control)(unsigned char control, void *user);
    void (*escape)(const char *bytes, size_t len, void *user);
    void (*text)(const char *bytes, size_t len, void *user);
} VTermParserFallbacks;

struct term_T {
    VTerm *tl_vterm;
    struct {
        VTermColor fg;
        VTermColor bg;
    } tl_default_color;
};

struct VTermValue {
    int boolean;
};

static VTermAllocator vterm_allocator;
static VTermScreenCallbacks screen_callbacks;
static VTermParserFallbacks parser_fallbacks;
extern int t_colors;

#ifdef WIN3264
#include <windows.h>
#endif

static void init_default_colors(term_T *term) {}

extern VTerm* vterm_new_with_allocator(int rows, int cols, VTermAllocator* allocator, void* user);
extern void vterm_free(VTerm* vt);
extern VTermState* vterm_obtain_state(VTerm* vt);
extern VTermScreen* vterm_obtain_screen(VTerm* vt);
extern void vterm_screen_set_callbacks(VTermScreen* screen, VTermScreenCallbacks* callbacks, void* user);
extern void vterm_set_utf8(VTerm* vt, int is_utf8);
extern void vterm_state_set_default_colors(VTermState* state, const VTermColor* fg, const VTermColor* bg);
extern void vterm_state_set_bold_highbright(VTermState* state, int bold_is_highbright);
extern void vterm_screen_reset(VTermScreen* screen, int hard);
extern void vterm_screen_enable_altscreen(VTermScreen* screen, int enable);
extern void vterm_state_set_termprop(VTermState* state, VTermProp prop, const VTermValue* val);
extern void vterm_state_set_unrecognised_fallbacks(VTermState* state, const VTermParserFallbacks* fallbacks, void* user);