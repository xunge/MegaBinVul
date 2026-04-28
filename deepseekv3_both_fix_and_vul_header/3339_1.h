#include <stdbool.h>
#include <stddef.h>

typedef enum {
    STF_OK,
    STF_FAIL
} stf_status;

typedef void* err_t;

struct ke_continuation {
    struct msg_digest *md;
};

struct msg_digest {
    struct state *st;
};

struct state {
    struct msg_digest *st_suspended_md;
    bool st_calculating;
};

extern struct state *cur_state;

#define FALSE false
#define DBG(level, expr)
#define DBG_CONTROLMORE 0
#define DBG_log(msg)
#define RC_LOG_SERIOUS 0
#define loglog(level, fmt, ...)
#define __FUNCTION__ ""
#define passert(expr)
#define GLOBALS_ARE_RESET() true

void release_md(struct msg_digest *md);
void set_suspended(struct state *st, struct msg_digest *md);
void set_cur_state(struct state *st);
stf_status ikev2_parent_outI1_tail(struct pluto_crypto_req_cont *pcrc, struct pluto_crypto_req *r);
void complete_v2_state_transition(struct msg_digest **md, stf_status e);
void reset_cur_state();
void reset_globals();