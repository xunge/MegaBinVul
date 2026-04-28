#include <stdint.h>
#include <stddef.h>

typedef struct clist_node {
    struct clist_node *next;
} clist_node_t;

typedef struct {
    clist_node_t event;
    struct {
        void *ptr;
    } content;
} msg_t;

typedef struct {
    msg_t msg;
    clist_node_t event;
} arq_timeout_event_t;

typedef struct {
    clist_node_t window;
    arq_timeout_event_t arq_timeout_event;
    unsigned cur_seq;
    unsigned frags_sent;
} gnrc_sixlowpan_frag_fb_sfr_t;

typedef struct {
    unsigned offset;
    uint16_t tag;
    gnrc_sixlowpan_frag_fb_sfr_t sfr;
} gnrc_sixlowpan_frag_fb_t;

typedef struct {
    clist_node_t node;
    void *frame;
    uint16_t datagram_tag;
} _frame_queue_t;

typedef struct {
    clist_node_t *next;
} evtimer_t;

static clist_node_t _frame_queue;
static clist_node_t _frag_descs_free;
static evtimer_t _arq_timer;

int gnrc_sixlowpan_frag_sfr_congure_snd_has_inter_frame_gap(void);
void gnrc_pktbuf_release(void *pkt);
clist_node_t *clist_lpop(clist_node_t *list);
void clist_rpush(clist_node_t *list, clist_node_t *new_node);
void evtimer_del(evtimer_t *timer, clist_node_t *event);