#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/poll.h>
#include <netdb.h>

#define PACKETSZ 512
#define MAXDNAME 1025
#define MAXLEN_searchdomain 256
#define HFIXEDSZ 12
#define NAMESERVER_PORT 53

#define T_A 1
#define T_AAAA 28
#define T_PTR 12
#define T_SIG 24
#define C_IN 1

#define NXDOMAIN 3
#define SERVFAIL 2

#define HOST_NOT_FOUND 1
#define NO_DATA 2
#define NO_RECOVERY 3
#define NETDB_INTERNAL 4

#define USE_SELECT

struct resolv_header {
    uint16_t id;
    unsigned qr:1;
    unsigned opcode:4;
    unsigned aa:1;
    unsigned tc:1;
    unsigned rd:1;
    unsigned ra:1;
    unsigned rcode:4;
    uint16_t qdcount;
    uint16_t ancount;
    uint16_t nscount;
    uint16_t arcount;
};

struct resolv_question {
    const char *dotted;
    uint16_t qtype;
    uint16_t qclass;
};

struct resolv_answer {
    char *dotted;
    uint16_t atype;
    uint16_t aclass;
    uint32_t ttl;
    uint16_t rdlength;
    unsigned char *rdata;
    unsigned char *buf;
    size_t buflen;
    int add_count;
};

typedef union {
    struct sockaddr sa;
    struct sockaddr_in sa4;
    struct sockaddr_in6 sa6;
} sockaddr46_t;

extern int __nameservers;
extern int __resolv_attempts;
extern int __searchdomains;
extern char *__searchdomain[];
extern sockaddr46_t __nameserver[];
extern unsigned __resolv_timeout;
extern int h_errno;
extern int __UCLIBC_MUTEX_LOCK(void *);
extern int __UCLIBC_MUTEX_UNLOCK(void *);
extern void *__resolv_lock;
extern void __open_nameservers(void);
extern int __encode_header(struct resolv_header *, unsigned char *, int);
extern int __encode_question(struct resolv_question *, unsigned char *, int);
extern int __length_question(const unsigned char *, int);
extern int __decode_answer(const unsigned char *, int, int, struct resolv_answer *);
extern void __decode_header(const unsigned char *, struct resolv_header *);
extern int __hnbad(const char *);

#define DPRINTF(...)