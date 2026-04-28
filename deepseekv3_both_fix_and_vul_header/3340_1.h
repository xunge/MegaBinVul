#include <stddef.h>

typedef int err_t;

struct pluto_crypto_req_cont {
    /* empty structure - actual definition unknown */
};

struct pluto_crypto_req {
    /* empty structure - actual definition unknown */
};

struct msg_digest {
    struct state *st;
    /* other members unknown */
};

struct state {
    struct msg_digest *st_suspended_md;
    unsigned int st_calculating;
    /* other members unknown */
};

struct dh_continuation {
    struct msg_digest *md;
    /* other members unknown */
};

typedef enum {
    STF_OK,
    STF_FAIL,
    /* other status values unknown */
} stf_status;

extern struct state *cur_state;

void release_md(struct msg_digest *md);
void set_suspended(struct state *st, void *ptr);
void set_cur_state(struct state *st);
stf_status ikev2_parent_inR1outI2_tail(struct pluto_crypto_req_cont *pcrc, struct pluto_crypto_req *r);
void complete_v2_state_transition(struct msg_digest **md, stf_status e);
void reset_globals();
int GLOBALS_ARE_RESET();

#define DBG(level, expr)
#define DBG_CONTROLMORE 0
#define DBG_log(msg)
#define RC_LOG_SERIOUS 0
#define loglog(level, ...)
#define passert(expr)
#define __FUNCTION__ ""
#define FALSE 0