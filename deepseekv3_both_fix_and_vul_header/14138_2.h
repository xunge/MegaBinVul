#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct switch_core_session_t switch_core_session_t;
typedef struct switch_channel_t switch_channel_t;
typedef struct nua_t nua_t;
typedef struct nua_handle_t nua_handle_t;
typedef struct tagi_t {
    int tag;
    void *value;
} tagi_t;

typedef struct {
    char *last_sdp_str;
    char *prev_sdp_str;
} mparams_t;

typedef struct private_object_s {
    mparams_t mparams;
    unsigned int flags;
} private_object_t;

typedef struct {
    int e_msg;
} sofia_dispatch_event_data_t;

typedef struct {
    sofia_dispatch_event_data_t *data;
} sofia_dispatch_event_t;

typedef struct {
    char *pl_data;
} sip_payload_t;

typedef struct sip_s {
    sip_payload_t *sip_payload;
    void *sip_call_info;
} sip_t;

typedef struct {
    int flags;
} sofia_profile_t;

typedef struct {
    int flags;
} sofia_private_t;

#define SIP_100_TRYING 100
#define TAG_END() NULL
#define zstr(s) (!(s) || !*(s))
#define PFLAG_TRACK_CALLS (1 << 0)
#define PFLAG_MANAGE_SHARED_APPEARANCE (1 << 1)
#define TFLAG_GOT_ACK (1 << 0)

static inline int sofia_test_pflag(sofia_profile_t *profile, int flag) {
    return profile->flags & flag;
}

static inline void sofia_clear_flag(private_object_t *tech_pvt, int flag) {
    tech_pvt->flags &= ~flag;
}