#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

typedef struct pool pool;

typedef struct pr_buffer_t {
    char *buf;
    size_t buflen;
    char *current;
    size_t remaining;
} pr_buffer_t;

typedef struct netio_stream {
    const char *owner_name;
    int (*read)(void *, char *, size_t);
} netio_stream;

typedef struct pr_netio_stream_t {
    int strm_fd;
    int strm_errno;
    int strm_mode;
    int strm_type;
    pool *strm_pool;
} pr_netio_stream_t;

#define PR_NETIO_STRM_CTRL 0
#define PR_NETIO_STRM_DATA 1
#define PR_NETIO_STRM_OTHR 2

extern int errno;
extern int XFER_ABORTED;
extern pool *session_pool;
extern struct session_t {
    size_t total_raw_in;
} session;
extern int trace_channel;
extern netio_stream *ctrl_netio;
extern netio_stream *default_ctrl_netio;
extern netio_stream *data_netio;
extern netio_stream *default_data_netio;
extern netio_stream *othr_netio;
extern netio_stream *default_othr_netio;

const char *netio_stream_mode(int mode);
int pr_netio_poll(pr_netio_stream_t *nstrm);
void pr_signals_handle(void);
void run_schedule(void);
void pr_event_generate(const char *event, pr_buffer_t *buf);
void pr_trace_msg(int channel, int level, const char *fmt, ...);
pool *make_sub_pool(pool *parent_pool);
void *pcalloc(pool *p, size_t sz);
void destroy_pool(pool *p);