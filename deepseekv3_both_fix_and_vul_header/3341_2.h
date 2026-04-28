#include <stddef.h>
#include <stdbool.h>

typedef int err_t;

enum debug_level {
    DBG_CONTROLMORE
};

enum rc_log_level {
    RC_LOG_SERIOUS
};

enum stf_status {
    STF_OK
};
typedef enum stf_status stf_status;

struct msg_digest {
    struct state *st;
};

struct state {
    struct msg_digest *st_suspended_md;
    bool st_calculating;
};

struct ke_continuation {
    struct msg_digest *md;
};

struct pluto_crypto_req_cont;
struct pluto_crypto_req;

#define FALSE false
#define passert(cond) ((void)0)
#define __FUNCTION__ ""

extern void DBG(enum debug_level level, const char *fmt, ...);
extern void loglog(enum rc_log_level level, const char *fmt, ...);
extern void release_md(struct msg_digest *md);
extern void set_suspended(struct state *st, struct msg_digest *md);
extern void set_cur_state(struct state *st);
extern stf_status ikev2_parent_inI1outR1_tail(struct pluto_crypto_req_cont *pcrc, struct pluto_crypto_req *r);
extern void complete_v2_state_transition(struct msg_digest **md, stf_status e);
extern void reset_globals();
extern bool GLOBALS_ARE_RESET();

extern struct state *cur_state;