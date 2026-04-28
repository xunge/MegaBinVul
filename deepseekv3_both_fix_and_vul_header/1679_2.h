#include <stddef.h>
#include <wchar.h>

typedef struct buf_S buf_T;
typedef struct win_S win_T;

#define FALSE 0
#define TRUE 1

typedef wchar_t char_u;

struct buf_S {
    int b_locked;
    char_u *b_fname;
    char_u *b_ffname;
};

struct win_S {
    buf_T *w_buffer;
    win_T *w_next;
};

extern int updating_screen;
extern char_u *e_attempt_to_delete_buffer_that_is_in_use_str;
extern char_u *_(const char_u *);
extern void semsg(const char_u *, const char_u *);

win_T *first_window;

#define FOR_ALL_WINDOWS(wp) \
    for ((wp) = first_window; (wp) != NULL; (wp) = (wp)->w_next)