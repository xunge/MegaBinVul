#include <netdb.h>
#include <resolv.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/nameser.h>
#include <alloca.h>
#include <sys/types.h>

typedef union {
    HEADER hdr;
    unsigned char buf[NS_PACKETSZ];
} querybuf;

enum nss_status {
    NSS_STATUS_TRYAGAIN,
    NSS_STATUS_UNAVAIL,
    NSS_STATUS_NOTFOUND
};

struct gaih_addrtuple;
struct __res_state;

extern struct __res_state _res;
extern int __res_maybe_init(struct __res_state *, int);
extern int __libc_res_nsearch(struct __res_state *, const char *, int, int, 
                             unsigned char *, int, unsigned char **, 
                             unsigned char **, int *, int *, int *);
extern enum nss_status gaih_getanswer(const void *, int, const void *, 
                                     int, const char *, struct gaih_addrtuple **, 
                                     char *, size_t, int *, int *, int32_t *);
extern void __set_errno(int);

#define T_QUERY_A_AND_AAAA (T_A | T_AAAA)