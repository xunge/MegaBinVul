#include <stddef.h>
#include <stdbool.h>

typedef int err_t;

struct pluto_crypto_req_cont;
struct pluto_crypto_req;

struct msg_digest {
    struct state *st;
};

struct state {
    struct msg_digest *st_suspended_md;
    bool st_calculating;
};

struct dh_continuation {
    struct msg_digest *md;
};

typedef enum {
    STF_OK,
    STF_FAIL
} stf_status;

extern struct state *cur_state;
extern const struct enum_names ikev2_notify_names;
extern const struct enum_names stfstatus_name;

#define FALSE false
#define DBG(level, expr)
#define DBG_CONTROLMORE 0
#define DBG_log(fmt, ...)
#define RC_LOG_SERIOUS 0
#define loglog(level, fmt, ...)
#define passert(expr)
#define __FUNCTION__ ""

static stf_status ikev2_parent_inI2outR2_tail(struct pluto_crypto_req_cont *pcrc, struct pluto_crypto_req *r);
static void release_md(struct msg_digest *md);
static void set_suspended(struct state *st, struct msg_digest *md);
static void set_cur_state(struct state *st);
static void complete_v2_state_transition(struct msg_digest **md, stf_status e);
static void reset_globals();
static bool GLOBALS_ARE_RESET();