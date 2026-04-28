#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <stdint.h>

#define PO_DROPPED 0x01
#define NS_MAXDNAME 1025
#define MDNS_QU_FLAG 0x8000
#define MAX_ASCII_ADDR_LEN 64
#define E_SUCCESS 0

#define ns_c_in 1
#define ns_t_a 1
#define ns_t_aaaa 28
#define ns_t_ptr 12
#define ns_t_srv 33

typedef uint8_t u_int8;
typedef uint16_t u_int16;
typedef unsigned char u_char;

struct packet_object {
    unsigned int flags;
    struct {
        void *data;
        size_t len;
    } DATA;
    struct {
        void *src;
    } L4;
};

struct mdns_header {
    u_int16 id;
    u_int16 flags;
    u_int16 questions;
    u_int16 answer_rrs;
    u_int16 authority_rrs;
    u_int16 additional_rrs;
};

struct ip_addr {
    u_int16 addr_type;
    union {
        struct in_addr ip4;
        struct in6_addr ip6;
    } addr;
};

#define NS_GET16(s, cp) { \
    const u_char *t_cp = (const u_char *)(cp); \
    (s) = ((u_int16)t_cp[0] << 8) | t_cp[1]; \
    (cp) += 2; \
}

#define NS_PUT16(s, cp) { \
    u_int16 t_s = (u_int16)(s); \
    u_char *t_cp = (u_char *)(cp); \
    *t_cp++ = t_s >> 8; \
    *t_cp = t_s & 0xff; \
    (cp) += 2; \
}

static inline void ip_addr_cpy(void *dst, const struct ip_addr *src) {
    if (ntohs(src->addr_type) == AF_INET) {
        memcpy(dst, &src->addr.ip4, sizeof(struct in_addr));
    } else if (ntohs(src->addr_type) == AF_INET6) {
        memcpy(dst, &src->addr.ip6, sizeof(struct in6_addr));
    }
}

static inline char *ip_addr_ntoa(const struct ip_addr *addr, char *buf) {
    if (ntohs(addr->addr_type) == AF_INET) {
        inet_ntop(AF_INET, &addr->addr.ip4, buf, MAX_ASCII_ADDR_LEN);
    } else if (ntohs(addr->addr_type) == AF_INET6) {
        inet_ntop(AF_INET6, &addr->addr.ip6, buf, MAX_ASCII_ADDR_LEN);
    }
    return buf;
}

static inline const char *type_str(u_int16 type) {
    switch(type) {
        case ns_t_a: return "A";
        case ns_t_aaaa: return "AAAA";
        case ns_t_ptr: return "PTR";
        case ns_t_srv: return "SRV";
        default: return "UNKNOWN";
    }
}

extern int dn_expand(const u_char *, const u_char *, const u_char *, char *, int);
extern int dn_comp(const char *, u_char *, int, u_char **, u_char **);
extern int get_spoofed_a(const char *name, struct ip_addr **reply);
extern int get_spoofed_aaaa(const char *name, struct ip_addr **reply);
extern int get_spoofed_ptr(const char *name, char **a, struct ip_addr **reply);
extern int get_spoofed_srv(const char *name, struct ip_addr **reply, u_int16 *port);
extern void prep_mdns_reply(struct packet_object *po, u_int16 class, struct ip_addr **sender, struct ip_addr **target, u_int8 **tmac, struct ip_addr *reply);
extern void send_mdns_reply(void *src, struct ip_addr *sender, struct ip_addr *target, u_int8 *tmac, u_int16 id, u_int8 *answer, size_t len, int count, int delay, int ttl);
extern void USER_MSG(const char *fmt, ...);