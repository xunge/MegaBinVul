#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct git_pkt git_pkt;
typedef struct git_pkt_data git_pkt_data;
typedef struct git_pkt_err git_pkt_err;
typedef struct git_pkt_progress git_pkt_progress;
typedef struct git_buf git_buf;
typedef struct gitno_buffer gitno_buffer;
typedef struct transport_smart transport_smart;
typedef struct git_push git_push;

#define GIT_BUF_INIT {0, NULL}
#define GIT_EBUFS (-2)
#define GIT_EEOF (-3)
#define GIT_ITEROVER (-4)
#define GIT_ERROR (-5)
#define GITERR_NET "NET"

enum git_pkt_type {
    GIT_PKT_DATA,
    GIT_PKT_ERR,
    GIT_PKT_PROGRESS
};

struct git_pkt {
    enum git_pkt_type type;
};

struct git_pkt_data {
    struct git_pkt parent;
    char *data;
    size_t len;
};

struct git_pkt_err {
    struct git_pkt parent;
    char *error;
};

struct git_pkt_progress {
    struct git_pkt parent;
    char *data;
    size_t len;
};

struct git_buf {
    size_t size;
    char *ptr;
};

struct gitno_buffer {
    char *data;
    size_t offset;
    size_t size;
};

struct transport_smart {
    gitno_buffer buffer;
    int (*progress_cb)(const char *data, size_t len, void *payload);
    void *message_cb_payload;
};

#define giterr_set(err, fmt, ...) fprintf(stderr, "%s: " fmt "\n", err, ##__VA_ARGS__)

static int git_pkt_parse_line(git_pkt **pkt, const char *line, const char **end, size_t len);
static int gitno_recv(gitno_buffer *buf);
static void gitno_consume(gitno_buffer *buf, const char *end);
static int add_push_report_sideband_pkt(git_push *push, git_pkt_data *pkt, git_buf *buf);
static int add_push_report_pkt(git_push *push, git_pkt *pkt);
static void git_pkt_free(git_pkt *pkt);
static void git_buf_free(git_buf *buf);