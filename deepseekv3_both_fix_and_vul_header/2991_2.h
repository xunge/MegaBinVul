#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

struct TCP_Server_Info {
    int ssocket;
    struct sockaddr dstaddr;
    bool noblocksnd;
};

struct kvec {
    void *iov_base;
    size_t iov_len;
};

#define MSG_DONTWAIT 0x40
#define MSG_NOSIGNAL 0x4000
#define ENOTSOCK 88
#define ENOSPC 28
#define EAGAIN 11

static void WARN_ON_ONCE(int condition) {}
static void cERROR(int level, const char *fmt, ...) {}
static void msleep(unsigned int msecs) { usleep(msecs * 1000); }
static int kernel_sendmsg(int sock, struct msghdr *msg, struct kvec *vec, size_t num, size_t size) { return -1; }