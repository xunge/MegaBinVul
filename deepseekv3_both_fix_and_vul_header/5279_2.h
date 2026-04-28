#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

#define DNS_EAI_ADDRFAMILY 1
#define DNS_EAI_NONAME 2
#define DNS_QUERY_TYPE_A 1
#define DNS_QUERY_TYPE_AAAA 28
#define K_FOREVER -1

struct zsock_addrinfo {
    int ai_family;
    struct zsock_addrinfo *ai_next;
    struct sockaddr _ai_addr;
};

struct k_sem {
    unsigned int count;
    unsigned int limit;
};

struct ai_state {
    const struct zsock_addrinfo *hints;
    int idx;
    int status;
    uint16_t port;
    struct k_sem sem;
};

struct zsock_addrinfo ai_arr[2];
struct ai_state ai_state;

void (*dns_resolve_cb)(void *, int, void *);

void k_sem_init(struct k_sem *sem, unsigned int initial_count, unsigned int limit);
int k_sem_take(struct k_sem *sem, int timeout);
void dns_get_addr_info(const char *host, int query_type, void *arg,
                      void (*callback)(void *, int, void *),
                      struct ai_state *state, int timeout);
struct sockaddr_in *net_sin(struct sockaddr *addr);
struct sockaddr_in6 *net_sin6(struct sockaddr *addr);
uint16_t htons(uint16_t hostshort);