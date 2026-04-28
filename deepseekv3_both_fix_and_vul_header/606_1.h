#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

enum dns_resolve_status {
    DNS_EAI_CANCELED,
    DNS_EAI_INPROGRESS,
    DNS_EAI_ALLDONE,
    DNS_EAI_FAIL
};

struct dns_addrinfo {
    int ai_family;
    struct sockaddr ai_addr;
};

struct net_shell_user_data {
    const void *shell;
    void *user_data;
};

#define PR_WARNING(fmt, ...)
#define PR(fmt, ...)
#define NET_IPV6_ADDR_LEN 46
#define NET_IPV4_ADDR_LEN 16

static inline struct sockaddr_in *net_sin(struct sockaddr *addr) {
    return (struct sockaddr_in *)addr;
}

static inline struct sockaddr_in6 *net_sin6(struct sockaddr *addr) {
    return (struct sockaddr_in6 *)addr;
}

static inline const char *net_addr_ntop(int af, const void *src, char *dst, size_t size) {
    return inet_ntop(af, src, dst, size);
}