#include <stdbool.h>
#include <stddef.h>

typedef struct exarg exarg_T;
typedef struct window window_T;

struct exarg {
    int line2;
    bool forceit;
    int regname;
};

struct window {
    struct {
        long lnum;
    } w_cursor;
};

#define TRUE true
#define FALSE false
#define BACKWARD 0
#define FORWARD 1
#define PUT_LINE 0x01
#define PUT_CURSLINE 0x02

extern window_T *curwin;
extern void do_put(int regname, void *arg, int direction, long count, int flags);