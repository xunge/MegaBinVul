#include <stddef.h>

typedef struct git_buf {
    char *ptr;
    size_t size;
} git_buf;

typedef struct git_pkt_data {
    const char *data;
    size_t len;
} git_pkt_data;

typedef struct git_pkt git_pkt;
typedef struct git_push git_push;

#define GIT_EBUFS (-1)
#define GIT_ITEROVER (-2)

int git_pkt_parse_line(git_pkt **pkt, const char *line, const char **line_end, size_t line_len);
int git_buf_put(git_buf *buf, const char *data, size_t len);
int git_buf_consume(git_buf *buf, const char *end);
void git_pkt_free(git_pkt *pkt);
int add_push_report_pkt(git_push *push, git_pkt *pkt);