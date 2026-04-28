#include <stdint.h>
#include <netinet/in.h>

struct net;
struct in6_addr;

typedef uint32_t __be32;
typedef uint32_t u32;

#define __read_mostly

u32 __ipv6_select_ident(struct net *net, ...);
void net_get_random_once(void *buf, size_t len);