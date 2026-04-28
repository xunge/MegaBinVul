#include <stdbool.h>
#include <errno.h>
#include <sys/types.h>

enum icall_call_type {
    ICALL_CALL_TYPE_VIDEO
};

enum icall_video_state {
    ICALL_VIDEO_STATE_STARTED
};

enum econn_state {
    ECONN_PENDING_INCOMING,
    ECONN_PENDING_OUTGOING
};

enum async_state {
    ASYNC_OFFER,
    ASYNC_NONE
};

struct econn;
struct flow;
struct props;

struct ecall {
    struct econn *econn;
    enum icall_call_type call_type;
    struct flow *flow;
    struct props *props_local;
    enum icall_video_state vstate;
    struct {
        enum async_state async;
    } sdp;
    unsigned long ts_started;
    int call_setup_time;
    int turnc;
};

#define ECALL_CBR_ALWAYS_ON

int econn_current_state(struct econn *econn);
const char *econn_state_name(enum econn_state state);
int ecall_answer(struct ecall *ecall, enum icall_call_type call_type, bool audio_cbr);
int ecall_create_econn(struct ecall *ecall);
struct econn *ecall_get_econn(struct ecall *ecall);
void econn_set_state(struct econn *econn, enum econn_state state);
int alloc_flow(struct ecall *ecall, enum async_state async, enum icall_call_type call_type, bool audio_cbr);
int econn_props_update(struct props *props, const char *key, const char *value);
int generate_offer(struct ecall *ecall);
unsigned long tmr_jiffies(void);

#define IFLOW_CALL(flow, func, arg) (0)

void info(const char *fmt, ...);
void warning(const char *fmt, ...);