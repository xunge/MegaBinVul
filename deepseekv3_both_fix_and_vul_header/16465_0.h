#include <stddef.h>

struct buf {
    size_t size;
    const char *data;
};

struct html_renderopt {
    unsigned int flags;
#define HTML_ESCAPE (1 << 0)
};

#define BUFPUTSL(ob, literal) bufput(ob, literal, sizeof(literal) - 1)

static void escape_html(struct buf *ob, const char *data, size_t size);
static void bufput(struct buf *ob, const char *data, size_t size);