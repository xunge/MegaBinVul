#include <stdbool.h>
#include <stdint.h>
#include <errno.h>
#include <assert.h>
#include <stddef.h>

typedef struct DnsScope {
    int dnssec_mode;
} DnsScope;

typedef struct DnsResourceKey {
    uint16_t type;
    uint16_t class;
} DnsResourceKey;

typedef struct DnsResourceRecord {
    DnsResourceKey *key;
} DnsResourceRecord;

typedef struct DnsAnswer {
    // placeholder structure
} DnsAnswer;

typedef struct DnsTransaction {
    DnsScope *scope;
    struct DnsTransaction *dnssec_transactions;
    struct DnsTransaction *next;
    DnsAnswer *answer;
    unsigned answer_query_flags;
    uint16_t id;
} DnsTransaction;

#define DNSSEC_NO 0
#define DNS_TYPE_RRSIG 46
#define DNS_TYPE_SOA 6
#define DNS_TYPE_NS 2
#define DNS_TYPE_DS 43
#define DNS_TYPE_CNAME 5
#define DNS_TYPE_DNAME 39
#define SD_RESOLVED_AUTHENTICATED (1 << 0)
#define FLAGS_SET(flags, mask) ((flags) & (mask))
#define SET_FOREACH(e, s) for ((e) = (s); (e); (e) = (e)->next)
#define PRIu16 "hu"
#define EINVAL 22
#define EBADMSG 74
#define SYNTHETIC_ERRNO(e) (e)

static inline int dns_type_is_pseudo(uint16_t type) { return 0; }
static inline int dns_transaction_negative_trust_anchor_lookup(DnsTransaction *t, const char *name) { return 0; }
static inline const char *dns_resource_key_name(const DnsResourceKey *key) { return NULL; }
static inline int dns_name_equal(const char *a, const char *b) { return 0; }
static inline int dns_name_parent(const char **name) { return 0; }
static inline DnsResourceKey *dns_transaction_key(DnsTransaction *t) { return NULL; }
static inline int dns_answer_match_key(DnsAnswer *a, DnsResourceKey *k, void *userdata) { return 0; }
static inline int log_debug_errno(int err, const char *format, ...) { return 0; }