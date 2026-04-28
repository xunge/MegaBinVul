#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <strings.h>

#define TRUE 1
#define FALSE 0
#define EINVAL 22
#define E2BIG 7
#define C_SITE "SITE"
#define DEBUG0 0
#define PR_STR_FL_PRESERVE_WHITESPACE (1 << 0)

typedef struct {
    int strm_errno;
} pr_netio_stream_t;

typedef struct {
    void *pool;
    struct {
        pr_netio_stream_t *instrm;
        pr_netio_stream_t *outstrm;
    } *c;
} session_t;

typedef struct {
    int is_ftp;
    char *protocol;
    void *arg;
} cmd_rec;

extern session_t session;
extern long get_max_cmd_sz(void);
extern void *pcalloc(void *, size_t);
extern void pr_signals_handle(void);
extern int pr_netio_telnet_gets2(char *, long, pr_netio_stream_t *, pr_netio_stream_t *);
extern void pr_trace_msg(const char *, int, const char *);
extern void pr_log_debug(int, const char *, ...);
extern cmd_rec *make_ftp_cmd(void *, char *, int, int);
extern int pr_cmd_is_http(cmd_rec *);
extern int pr_cmd_is_ssh2(cmd_rec *);
extern int pr_cmd_is_smtp(cmd_rec *);