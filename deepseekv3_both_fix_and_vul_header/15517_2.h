#include <sys/epoll.h>
#include <sys/socket.h>
#include <errno.h>
#include <stddef.h>
#include <stdint.h>

typedef int ogs_socket_t;
#define INVALID_SOCKET (-1)

#define OGS_LOG_ERROR 1
#define OGS_ERROR (-1)
#define OGS_TIMEUP (-2)
#define OGS_OK 0
#define OGS_INFINITE_TIME (-1)

#define OGS_POLLIN 0x001
#define OGS_POLLOUT 0x004

typedef int64_t ogs_time_t;

struct epoll_context_s {
    int epfd;
    struct epoll_event *event_list;
    void *map_hash;
};

struct epoll_map_s {
    struct ogs_poll *read;
    struct ogs_poll *write;
};

struct ogs_poll {
    void (*handler)(short when, ogs_socket_t fd, void *data);
    ogs_socket_t fd;
    void *data;
};

typedef struct ogs_pollset_s {
    struct epoll_context_s *context;
    int capacity;
} ogs_pollset_t;

extern int ogs_socket_errno;
void ogs_log_message(int level, int err, const char *msg);
void ogs_assert(int condition);
int ogs_time_to_msec(ogs_time_t t);
void *ogs_hash_get(void *hash, void *key, size_t keylen);