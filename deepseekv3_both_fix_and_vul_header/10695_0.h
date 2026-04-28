#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <resolv.h>
#include <stdlib.h>
#include <alloca.h>
#include <assert.h>
#include <stdio.h>

typedef struct __res_state *res_state;

#define T_QUERY_A_AND_AAAA (-1)
#define QUERYSIZE 1024
#define MAXPACKET 65536
#define RES_F_EDNS0ERR (1 << 0)
#define RES_USE_EDNS0 (1 << 0)
#define RES_USE_DNSSEC (1 << 1)
#define RES_DEBUG (1 << 0)
#define NOERROR 0
#define NXDOMAIN 3
#define SERVFAIL 2
#define FORMERR 1
#define NOTIMP 4
#define REFUSED 5
#define HOST_NOT_FOUND 1
#define NO_DATA 2
#define NO_RECOVERY 3
#define TRY_AGAIN 4

#define QUERY 0
#define T_A 1
#define T_AAAA 28

#define __alignof__(x) _Alignof(x)
#define __builtin_expect(expr, val) (expr)
#define __glibc_unlikely(expr) (expr)

#define RES_SET_H_ERRNO(statp, err) ((statp)->res_h_errno = (err))