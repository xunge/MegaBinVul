#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define ARES_SUCCESS 0
#define ARES_EDESTRUCTION 1
#define ARES_ENOTFOUND 2

struct host_query {
    int timeouts;
    int remaining;
    struct ares_addrinfo *ai;
};

struct ares_addrinfo {
    struct ares_addrinfo_node *nodes;
};

struct ares_addrinfo_node {
    struct ares_addrinfo_node *ai_next;
};

void end_hquery(struct host_query *hquery, int status);
void next_lookup(struct host_query *hquery, int status);
int ares__parse_into_addrinfo(unsigned char *abuf, int alen, struct ares_addrinfo *ai);