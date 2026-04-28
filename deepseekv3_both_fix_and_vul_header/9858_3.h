#include <stddef.h>
#include <string.h>
#include <stdatomic.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef unsigned int gfp_t;

typedef union sctp_addr {
    struct sockaddr sa;
    struct sockaddr_in v4;
    struct sockaddr_in6 v6;
} sctp_addr_t;

struct sctp_transport_list {
    struct sctp_transport *next;
    struct sctp_transport *prev;
};

struct sctp_transport {
    sctp_addr_t ipaddr;
    void *af_specific;
    void *asoc;
    void *dst;
    sctp_addr_t saddr;
    unsigned long rto;
    unsigned long rtt;
    unsigned long rttvar;
    unsigned long srtt;
    int rto_pending;
    int hb_sent;
    int fast_recovery;
    unsigned long last_time_heard;
    unsigned long last_time_ecne_reduced;
    int init_sent_count;
    unsigned int param_flags;
    unsigned int hbinterval;
    unsigned short pathmaxrxt;
    unsigned short error_count;
    struct sctp_transport_list transmitted;
    struct sctp_transport_list send_ready;
    struct sctp_transport_list transports;
    struct {
        unsigned long expires;
        void (*function)(unsigned long);
        unsigned long data;
    } T3_rtx_timer, hb_timer, proto_unreach_timer;
    unsigned long long hb_nonce;
    atomic_int refcnt;
    int dead;
    int malloced;
    struct {
        int changeover_active;
        int cycling_changeover;
        unsigned int next_tsn_at_change;
        int cacc_saw_newack;
    } cacc;
};

#define SPP_HB_DISABLE 0x01
#define SPP_PMTUD_ENABLE 0x02
#define SPP_SACKDELAY_ENABLE 0x04

#define INIT_LIST_HEAD(ptr) do { \
    (ptr)->next = (struct sctp_transport *)(ptr); \
    (ptr)->prev = (struct sctp_transport *)(ptr); \
} while (0)

static inline unsigned long msecs_to_jiffies(unsigned int msecs) {
    return msecs;
}

static unsigned long jiffies = 0;
static unsigned long sctp_rto_initial = 0;
static unsigned long sctp_max_retrans_path = 0;

static void setup_timer(void *timer, void (*function)(unsigned long), unsigned long data) {
    ((struct {
        unsigned long expires;
        void (*function)(unsigned long);
        unsigned long data;
    }*)timer)->function = function;
    ((struct {
        unsigned long expires;
        void (*function)(unsigned long);
        unsigned long data;
    }*)timer)->data = data;
}

static void get_random_bytes(void *buf, size_t len) {
    memset(buf, 0, len);
}

static void *sctp_get_af_specific(int family) {
    return NULL;
}

static void sctp_generate_t3_rtx_event(unsigned long data) {}
static void sctp_generate_heartbeat_event(unsigned long data) {}
static void sctp_generate_proto_unreach_event(unsigned long data) {}

static inline void atomic_set(atomic_int *v, int i) {
    *v = i;
}