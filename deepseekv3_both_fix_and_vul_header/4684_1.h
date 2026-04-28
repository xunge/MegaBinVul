#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <resolv.h>
#include <errno.h>
#include <alloca.h>
#include <arpa/nameser.h>
#include <sys/types.h>

enum nss_status {
    NSS_STATUS_UNAVAIL,
    NSS_STATUS_NOTFOUND
};

typedef union {
    char buf[1024];
    u_char ptr[1];
} querybuf;

extern struct __res_state _res;

#define BYNAME 1

enum nss_status getanswer_r(querybuf *buf, int anslen, struct netent *result,
                           char *buffer, size_t buflen, int *errnop,
                           int *herrnop, int byname);