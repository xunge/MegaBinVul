#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef struct sourceinfo {
    void *smu;
} sourceinfo_t;

typedef struct chanacs {
    unsigned int level;
} chanacs_t;

typedef struct mowgli_node_t {
    void *data;
    struct mowgli_node_t *next;
} mowgli_node_t;

typedef struct mychan {
    char *name;
    unsigned int flags;
    struct {
        mowgli_node_t *head;
    } chanacs;
} mychan_t;

typedef struct myentity {
    char *name;
} myentity_t;

typedef struct hook_channel_acl_req {
    chanacs_t *ca;
    unsigned int oldlevel;
    unsigned int newlevel;
} hook_channel_acl_req_t;

typedef struct user {
    unsigned int flags;
} user_t;

#define STR_INSUFFICIENT_PARAMS ""
#define fault_needmoreparams 0
#define fault_nosuch_target 0
#define fault_noprivs 0
#define fault_badparams 0
#define fault_nochange 0
#define fault_toomany 0

#define PRIV_CHAN_AUSPEX 0
#define CA_FOUNDER 0x1
#define CA_ACLVIEW 0x2
#define CA_FLAGS 0x4
#define CA_AKICK 0x8
#define ca_all 0xFFFF

#define MC_PUBACL 0x1
#define MU_NEVEROP 0x1

#define CMDLOG_DO 0
#define CMDLOG_GET 1
#define CMDLOG_SET 2

struct ircd {
    int uses_rcommand;
};

struct chansvs {
    int maxfounders;
    struct {
        char *disp;
    } *me;
};

extern struct ircd *ircd;
extern struct chansvs chansvs;
extern bool anope_flags_compat;

static inline char *sstrdup(const char *src) {
    return strdup(src);
}

static inline int irccasecmp(const char *a, const char *b) {
    return strcasecmp(a, b);
}

static inline myentity_t *entity(void *p) {
    return (myentity_t *)p;
}

static inline user_t *user(myentity_t *mt) {
    return (user_t *)mt;
}

static inline bool isuser(myentity_t *mt) {
    return mt != NULL;
}

#define MOWGLI_ITER_FOREACH_SAFE(n, tn, head) \
    for ((n) = (head); (n) != NULL; (n) = (tn)) \
        if (((tn) = (n)->next), 1)

static inline void command_fail(sourceinfo_t *si, int fault, const char *fmt, ...) {}
static inline void command_success_nodata(sourceinfo_t *si, const char *fmt, ...) {}
static inline void command_success_string(sourceinfo_t *si, const char *str, const char *fmt, ...) {}
static inline void logcommand(sourceinfo_t *si, int cmdlog, const char *fmt, ...) {}
static inline void verbose(mychan_t *mc, const char *fmt, ...) {}

static inline mychan_t *mychan_find(const char *name) { return NULL; }
static inline void *metadata_find(mychan_t *mc, const char *key) { return NULL; }
static inline bool has_priv(sourceinfo_t *si, int priv) { return false; }
static inline unsigned int flags_to_bitmask(const char *flags, unsigned int flags_all) { return 0; }
static inline void do_list(sourceinfo_t *si, mychan_t *mc, unsigned int flags) {}
static inline myentity_t *myentity_find_ext(const char *name) { return NULL; }
static inline bool chanacs_source_has_flag(mychan_t *mc, sourceinfo_t *si, unsigned int flag) { return false; }
static inline bool validhostmask(const char *host) { return false; }
static inline chanacs_t *chanacs_find_host_literal(mychan_t *mc, const char *hostmask, unsigned int level) { return NULL; }
static inline chanacs_t *chanacs_find_literal(mychan_t *mc, myentity_t *mt, unsigned int level) { return NULL; }
static inline char *bitmask_to_flags2(unsigned int flags, unsigned int flags_all) { return NULL; }
static inline unsigned int chanacs_source_flags(mychan_t *mc, sourceinfo_t *si) { return 0; }
static inline unsigned int allow_flags(mychan_t *mc, unsigned int restrictflags) { return 0; }
static inline void flags_make_bitmasks(const char *flags, unsigned int *addflags, unsigned int *removeflags) {}
static inline unsigned int get_template_flags(mychan_t *mc, const char *name) { return 0; }
static inline int mychan_num_founders(mychan_t *mc) { return 0; }
static inline chanacs_t *chanacs_open(mychan_t *mc, myentity_t *mt, const char *hostmask, bool create, myentity_t *setter) { return NULL; }
static inline void chanacs_close(chanacs_t *ca) {}
static inline bool chanacs_modify(chanacs_t *ca, unsigned int *addflags, unsigned int *removeflags, unsigned int restrictflags) { return false; }
static inline bool chanacs_is_table_full(chanacs_t *ca) { return false; }
static inline bool myentity_can_register_channel(myentity_t *mt) { return false; }
static inline bool myentity_allow_foundership(myentity_t *mt) { return false; }
static inline void hook_call_channel_acl_change(hook_channel_acl_req_t *req) {}
static inline const char *get_source_name(sourceinfo_t *si) { return NULL; }
static inline void object_unref(void *obj) {}

#define _(x) x