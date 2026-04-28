#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

enum dns_resolve_status {
    DNS_EAI_ALLDONE
};

struct dns_addrinfo {
    struct sockaddr ai_addr;
    socklen_t ai_addrlen;
    char ai_canonname[256];
    int ai_family;
};

struct zsock_addrinfo {
    struct sockaddr _ai_addr;
    char _ai_canonname[256];
    struct sockaddr *ai_addr;
    socklen_t ai_addrlen;
    char *ai_canonname;
    int ai_family;
    int ai_socktype;
    int ai_protocol;
};

struct k_sem {
    int count;
};

struct getaddrinfo_state {
    int status;
    struct k_sem sem;
    size_t idx;
    uint16_t port;
    struct zsock_addrinfo *hints;
};

static inline struct sockaddr_in *net_sin(struct sockaddr *addr)
{
    return (struct sockaddr_in *)addr;
}

static inline void k_sem_give(struct k_sem *sem)
{
    sem->count++;
}

extern struct zsock_addrinfo ai_arr[10];
extern void NET_DBG(const char *fmt, ...);