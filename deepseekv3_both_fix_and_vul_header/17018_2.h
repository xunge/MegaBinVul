#include <assert.h>
#include <errno.h>
#include <stdarg.h>
#include <stddef.h>

typedef int tag_type_t;
typedef unsigned long tag_value_t;

struct sigcomp_compartment;

typedef struct tport_s {
    struct tport_primary_s *tp_pri;
    int tp_reusable;
    struct tport_params_s *tp_params;
    char *tp_protoname;
} tport_t;

typedef struct msg_s {
    int error;
} msg_t;

typedef struct tp_name_s {
    char *tpn_comp;
    char *tpn_proto;
} tp_name_t;

typedef struct tport_primary_s {
    struct tport_s *pri_primary;
    struct {
        int (*vtp_prepare)(tport_t *, msg_t *, tp_name_t *, struct sigcomp_compartment *, unsigned);
    } *pri_vtable;
} tport_primary_t;

typedef struct su_addrinfo_s {
    unsigned ai_flags;
} su_addrinfo_t;

typedef struct tagi_s {
    tag_type_t t_tag;
    tag_value_t t_value;
    struct tagi_s *t_next;
} tagi_t;

struct tport_params_s {
    int tpp_conn_orient;
};

#define TPN_FORMAT ""
#define TPN_ARGS(x) 
#define VA_NONE
#define SU_DEBUG_7(x)
#define SU_DEBUG_9(x)
#define NONE NULL
#define HAVE_UPNP 0

#define ta_list va_list
#define ta_start(ap, tag, value) va_start(ap, value)
#define ta_end va_end
#define ta_args(x) ((tagi_t const *)(x))
#define tl_next(x) ((x)->t_next)

#define EINVAL 22
#define EPROTONOSUPPORT 93
#define TP_AI_COMPRESSED (1 << 0)
#define TP_AI_SHUTDOWN (1 << 1)
#define TP_AI_CLOSE (1 << 2)

enum {
    tptag_reuse = 1,
    tptag_mtu = 2,
    tptag_sdwn_after = 3,
    tptag_close_after = 4,
    tptag_fresh = 5,
    tptag_compartment = 6
};

int msg_set_errno(msg_t *msg, int err);
int tport_is_master(tport_t *self);
int tport_is_primary(tport_t *self);
int tport_is_secondary(tport_t *self);
int tport_is_connection_oriented(tport_t *self);
int tport_is_clear_to_send(tport_t *self);
int tport_resolve(tport_t *self, msg_t *msg, tp_name_t *tpn);
int tport_prepare_and_send(tport_t *self, msg_t *msg, tp_name_t *tpn, struct sigcomp_compartment *cc, unsigned mtu);
tport_t *tport_primary_by_name(tport_t *self, tp_name_t *tpn);
tport_t *tport_primaries(tport_t *self);
tport_t *tport_next(tport_t *self);
tport_t *tport_by_addrinfo(tport_primary_t *tp, su_addrinfo_t *ai, tp_name_t *tpn);
tport_t *tport_connect(tport_primary_t *primary, su_addrinfo_t *ai, tp_name_t *tpn);
char *tport_canonize_comp(char *comp);
struct sigcomp_compartment *tport_sigcomp_assign(tport_t *self, struct sigcomp_compartment *cc);
struct sigcomp_compartment *tport_sigcomp_assign_if_needed(tport_t *self, struct sigcomp_compartment *cc);
void tport_peer_address(tport_t *self, msg_t *msg);
su_addrinfo_t *msg_addrinfo(msg_t *msg);
int su_errno(void);