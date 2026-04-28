#include <stdint.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

typedef uint32_t u32;

#define __force
#define __read_mostly

void net_get_random_once(void *buf, size_t nbytes);
u32 jhash_3words(u32 a, u32 b, u32 c, u32 initval);
u32 ip_idents_reserve(u32 hash, int segs);