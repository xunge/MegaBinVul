#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#define VTY_READ_BUFSIZ 4096
#define VTY_BUFSIZ 4096
#define VTY_NEWLINE "\n"
#define VTYSH_READ 1
#define VTYSH_DEBUG
#define CMD_SUSPEND 2

#define THREAD_FD(thread) (thread)->fd
#define THREAD_ARG(thread) (thread)->arg
#define ERRNO_IO_RETRY(err) ((err) == EAGAIN || (err) == EWOULDBLOCK || (err) == EINTR)

typedef unsigned char u_char;

struct thread {
    int fd;
    void *arg;
};

struct vty {
    unsigned char *buf;
    int length;
    int cp;
    int node;
    int monitor;
    void *obuf;
    struct thread *t_read;
    struct thread *t_write;
};

void vty_event(int type, int sock, struct vty *vty);
void vty_close(struct vty *vty);
void vty_clear_buf(struct vty *vty);
void vty_out(struct vty *vty, const char *format, ...);
int vty_execute(struct vty *vty);
int vtysh_flush(struct vty *vty);
void buffer_reset(void *buf);
void buffer_put(void *buf, const void *data, size_t len);
const char *safe_strerror(int errnum);
void zlog_warn(const char *format, ...);