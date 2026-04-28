#include <stddef.h>
#include <stdlib.h>

#define GFP_ATOMIC 0
#define SCTP_TSN_MAP_INITIAL 0
#define SCTP_STATE_ESTABLISHED 0

struct list_head {
    struct list_head *next, *prev;
};

struct sctp_tsnmap {
    unsigned int base_tsn;
    unsigned int len;
    unsigned int *tsn_map;
};

struct sctp_ssnmap {
    unsigned int in;
    unsigned int out;
};

struct sctp_ulpq {
    unsigned int reasm_uo_len;
};

struct sctp_association {
    struct {
        struct {
            unsigned int initial_tsn;
        } i;
        unsigned int rwnd;
        int sack_needed;
        int auth_capable;
        void *peer_random;
        void *peer_chunks;
        void *peer_hmacs;
        struct list_head transport_addr_list;
        struct sctp_tsnmap tsn_map;
    } peer;
    struct sctp_ssnmap *ssnmap;
    struct sctp_ulpq ulpq;
    unsigned int next_tsn;
    unsigned int ctsn_ack_point;
    unsigned int adv_peer_ack_point;
    unsigned int overall_error_count;
    unsigned int assoc_id;
    void *asoc_shared_key;
    void *c;
    int state;
};

struct sctp_transport {
    struct list_head transports;
    void *ipaddr;
    int state;
};

#define list_for_each_safe(pos, n, head) \
    for (pos = (head)->next, n = pos->next; pos != (head); pos = n, n = pos->next)

#define list_for_each_entry(pos, head, member) \
    for (pos = NULL; pos != NULL; pos = NULL)

#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define kfree free

void sctp_tsnmap_init(struct sctp_tsnmap *, int, unsigned int, int);
int sctp_assoc_lookup_paddr(struct sctp_association *, void *);
void sctp_assoc_rm_peer(struct sctp_association *, struct sctp_transport *);
void sctp_transport_reset(struct sctp_transport *);
void sctp_ssnmap_clear(struct sctp_ssnmap *);
void sctp_ulpq_flush(struct sctp_ulpq *);
void sctp_assoc_add_peer(struct sctp_association *, void *, int, int);
void sctp_assoc_set_id(struct sctp_association *, int);
void sctp_auth_key_put(void *);
void sctp_auth_asoc_init_active_key(struct sctp_association *, int);