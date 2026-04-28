#include <stdbool.h>

struct window {
    unsigned int w_valid;
    // 其他成员根据需要添加
};

#define VALID_WCOL 0x01
#define VALID_WROW 0x02
#define TRUE true

extern struct window *curwin;

void check_cursor_moved(struct window *win);
void curs_columns(bool force);