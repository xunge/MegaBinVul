#include <string.h>

struct dns_rrs;
struct dns_https_param;

extern unsigned char *dns_get_rr_nested_start(struct dns_rrs *rrs, char *domain, int maxsize, int *qtype, int *ttl, int *rr_len);
extern int _dns_read_short(unsigned char **data);
extern void safe_strncpy(char *dest, const char *src, int size);

#define DNS_T_HTTPS 65