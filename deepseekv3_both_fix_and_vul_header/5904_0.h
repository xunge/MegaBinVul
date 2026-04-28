#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

struct tcp_sock_t {
    int sd;
};

extern struct {
    int only_desired_port;
} g_options;

#define HTTP_MAX_PENDING_CONNS 128
#define ERR(msg) 