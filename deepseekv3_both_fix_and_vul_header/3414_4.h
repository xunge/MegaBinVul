#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <stdint.h>

enum ip_conntrack_info {
    IP_CT_DIR_REPLY
};

#define NF_DROP 0
#define NF_ACCEPT 1
#define EBUSY 16
#define pr_debug(fmt, ...) do {} while (0)

typedef union nf_inet_addr {
    uint32_t ip;
    struct in_addr in;
} nf_inet_addr;

struct nf_conn {
    struct {
        struct {
            struct {
                nf_inet_addr u3;
            } dst;
        } tuple;
    } tuplehash[1];
};

struct nf_conntrack_expect {
    struct {
        struct {
            u_int16_t port;
        } tcp;
    } saved_proto;
    struct {
        struct {
            union {
                struct {
                    u_int16_t port;
                } tcp;
            } u;
        } dst;
    } tuple;
    int dir;
    void *expectfn;
    void *master;
};

struct sk_buff {};

static int nf_ct_expect_related(struct nf_conntrack_expect *exp) { return 0; }
static void nf_ct_helper_log(struct sk_buff *skb, void *master, const char *msg) {}
static void nf_ct_unexpect_related(struct nf_conntrack_expect *exp) {}
static int nf_nat_mangle_tcp_packet(struct sk_buff *skb, void *master, enum ip_conntrack_info ctinfo,
                                   unsigned int protoff, unsigned int matchoff, unsigned int matchlen,
                                   char *buffer, size_t len) { return 0; }
static void nf_nat_follow_master() {}