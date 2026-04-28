#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int fd;
    void *ctx;
} uev_io_t;

typedef struct {
    int data_sd;
    int sd;
    char data_address[INET_ADDRSTRLEN];
    int data_port;
    uev_io_t data_watcher;
} ctrl_t;

extern void uev_io_stop(uev_io_t *watcher);
extern void ERR(int level, const char *fmt, ...);
extern void DBG(const char *fmt, ...);
extern void send_msg(int sd, const char *msg);
extern size_t strlcpy(char *dst, const char *src, size_t siz);