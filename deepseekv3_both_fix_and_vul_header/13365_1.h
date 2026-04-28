#include <stdlib.h>
#include <string.h>

typedef char char_u;

typedef struct yankreg_T {
    char_u **y_array;
    int y_size;
} yankreg_T;

extern yankreg_T *y_current;
extern int FEAT_CLIPBOARD;

#ifdef FEAT_CLIPBOARD
typedef struct {
    int available;
} Clipboard_T;

extern Clipboard_T clip_star;
extern Clipboard_T clip_plus;

int clip_isautosel_star(void);
int clip_isautosel_plus(void);
void clip_update_selection(Clipboard_T *clip);
void may_get_selection(int name);
#endif

void get_yank_register(int name, int flag);
char_u *vim_strsave(const char_u *str);

#define ALLOC_ONE(type) ((type *)malloc(sizeof(type)))
#define ALLOC_MULT(type, count) ((type *)malloc((count) * sizeof(type)))