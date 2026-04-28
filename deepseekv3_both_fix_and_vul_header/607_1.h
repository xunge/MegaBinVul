#include <stdbool.h>
#include <string.h>

#define PR_WARNING(fmt, ...)
#define PR(fmt, ...) 
#define PR_INFO(fmt, ...)

#define K_MSEC(ms) (ms)
#define CONFIG_DNS_RESOLVER
#define ENOEXEC (-1)

struct shell;
struct net_shell_user_data {
    const struct shell *shell;
    void *user_data;
};

enum dns_query_type {
    DNS_QUERY_TYPE_A,
    DNS_QUERY_TYPE_AAAA
};

int dns_get_addr_info(const char *host, enum dns_query_type qtype,
                     void *user_data, void (*cb)(void *user_data, void *dns_data),
                     void *user_cb_data, int timeout);

void dns_result_cb(void *user_data, void *dns_data);