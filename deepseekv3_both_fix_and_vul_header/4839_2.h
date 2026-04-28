#include <stddef.h>
#include <stdlib.h>

struct list_head {
    struct list_head *next, *prev;
};

#define list_for_each_safe(pos, n, head) \
    for (pos = (head)->next, n = pos->next; pos != (head); pos = n, n = pos->next)

#define list_for_each_entry(pos, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = container_of(pos->member.next, typeof(*pos), member))

#define list_entry(ptr, type, member) \
    container_of(ptr, type, member)

#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) *__mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member)); })

struct sctp_tsn_map {
    unsigned int base_tsn;
    unsigned int len;
    unsigned int *tsn_map;
};

struct sctp_association {
    struct {
        int rwnd;
        int sack_needed;
        int auth_capable;
        struct {
            int initial_tsn;
        } i;
        struct sctp_tsn_map tsn_map;
        void *peer_random;
        void *peer_chunks;
        void *peer_hmacs;
        struct list_head transport_addr_list;
    } peer;
    int c;
    int state;
    int next_tsn;
    int ctsn_ack_point;
    int adv_peer_ack_point;
    void *ssnmap;
    int overall_error_count;
    void *ulpq;
    int assoc_id;
    void *asoc_shared_key;
};

struct sctp_transport {
    struct list_head transports;
    void *ipaddr;
    int state;
};

#define GFP_ATOMIC 0
#define SCTP_STATE_ESTABLISHED 1
#define SCTP_TSN_MAP_INITIAL 0

void sctp_tsnmap_init(struct sctp_tsn_map *map, int initial, int initial_tsn, int flags);
int sctp_assoc_lookup_paddr(struct sctp_association *asoc, void *ipaddr);
void sctp_assoc_rm_peer(struct sctp_association *asoc, struct sctp_transport *trans);
void sctp_transport_reset(struct sctp_transport *trans);
void sctp_ssnmap_clear(void *ssnmap);
void sctp_ulpq_flush(void *ulpq);
void sctp_assoc_add_peer(struct sctp_association *asoc, void *ipaddr, int flags, int state);
void sctp_assoc_set_id(struct sctp_association *asoc, int flags);
void sctp_auth_key_put(void *key);
void sctp_auth_asoc_init_active_key(struct sctp_association *asoc, int flags);