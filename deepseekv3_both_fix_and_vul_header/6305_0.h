#include <stdlib.h>
#include <string.h>

enum protocol_version {
    PROTOCOL_VERSION_0 = 0,
    PROTOCOL_VERSION_1 = 1,
    PROTOCOL_VERSION_2 = 2
};

struct child_process;
struct strbuf {
    char *buf;
    size_t len;
    size_t alloc;
};
#define STRBUF_INIT { NULL, 0, 0 }

extern void transport_check_allowed(const char *type);
extern int git_use_proxy(const char *host);
extern struct child_process *git_proxy_connect(int fd[2], const char *host);
extern struct child_process *git_tcp_connect(int fd[2], const char *host, int flags);
extern void packet_write(int fd, const void *buf, size_t size);
extern char *xstrdup(const char *str);
extern void strbuf_addf(struct strbuf *sb, const char *fmt, ...);
extern void strbuf_addch(struct strbuf *sb, int c);
extern void strbuf_release(struct strbuf *sb);