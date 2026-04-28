#include <stdint.h>
#include <string.h>
#include <syslog.h>
#include <netdb.h>
#include <errno.h>
#include <limits.h>
#include <arpa/nameser.h>
#include <resolv.h>
#include <nss.h>
#include <stdlib.h>
#include <sys/param.h>

#define MAX_NR_ALIASES 10
#define MAXDNAME NS_MAXDNAME
#define AskedForGot "Asked for \"%s\", got \"%s\""

typedef struct querybuf {
    HEADER hdr;
    unsigned char buf[NS_PACKETSZ];
} querybuf;

typedef union { 
    int32_t align;
    char data[1];
} align;

extern int res_hnok(const char *);
extern int res_dnok(const char *);
extern const char *p_class(int);
extern const char *p_type(int);
extern int map_v4v6_hostent(struct hostent *, char **, int *);
extern int __ns_name_unpack(const unsigned char *, const unsigned char *, const unsigned char *, unsigned char *, size_t);
extern int __ns_name_ntop(const unsigned char *, char *, size_t);
extern unsigned __ns_get16(const unsigned char *);
extern unsigned __ns_get32(const unsigned char *);
extern void *__mempcpy(void *dest, const void *src, size_t n);