#include <stdbool.h>
#include <stdlib.h>

struct sock {
    int sk_ack_backlog;
};

struct list_head {
    struct list_head *next, *prev;
};

struct sctp_association {
    struct {
        struct sock *sk;
        bool dead;
        struct list_head inqueue;
        struct list_head bind_addr;
    } base;
    bool temp;
    struct list_head asocs;
    struct list_head outqueue;
    struct list_head ulpq;
    struct {
        struct list_head tsn_map;
        struct list_head transport_addr_list;
        int transport_count;
        void *cookie;
        void *peer_random;
        void *peer_chunks;
        void *peer_hmacs;
    } peer;
    void *ssnmap;
    void *timers;
    void *asconf_addr_del_pending;
    void *endpoint_shared_keys;
    void *asoc_shared_key;
};

struct sctp_transport {
    struct list_head transports;
};

#define list_del(entry) do {} while (0)
#define list_for_each_safe(pos, temp, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)
#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))
#define list_del_rcu(entry) do {} while (0)

#define sctp_style(sk, style) 0
#define sctp_sstate(sk, state) 0
#define sctp_association_put(asoc) do {} while (0)
#define sctp_outq_free(outq) do {} while (0)
#define sctp_ulpq_free(ulpq) do {} while (0)
#define sctp_inq_free(inq) do {} while (0)
#define sctp_tsnmap_free(tsnmap) do {} while (0)
#define sctp_ssnmap_free(ssnmap) do {} while (0)
#define sctp_bind_addr_free(bind_addr) do {} while (0)
#define sctp_transport_free(transport) do {} while (0)
#define sctp_asconf_queue_teardown(asoc) do {} while (0)
#define sctp_auth_destroy_keys(keys) do {} while (0)
#define sctp_auth_key_put(key) do {} while (0)
#define del_timer(timer) 0

#define kfree(ptr) free(ptr)

enum {
    SCTP_EVENT_TIMEOUT_NONE,
    SCTP_NUM_TIMEOUT_TYPES,
    TCP,
    LISTENING
};