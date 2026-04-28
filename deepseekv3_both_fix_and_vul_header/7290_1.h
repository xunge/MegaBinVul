#include <stdbool.h>
#include <errno.h>

enum icall_call_type {
    ICALL_CALL_TYPE_AUDIO,
    ICALL_CALL_TYPE_VIDEO
};

enum econn_state {
    ECONN_PENDING_INCOMING
};

struct econn;
struct mediaflow;

struct ecall {
    struct econn *econn;
    struct mediaflow *flow;
    enum icall_call_type call_type;
    bool audio_cbr;
    bool answered;
    int audio_setup_time;
    int call_estab_time;
    unsigned long ts_answered;
    void *props_local;
};

#define EINVAL 22
#define ENOENT 2
#define EPROTO 71
#define ECALL_CBR_ALWAYS_ON
#define IFLOW_CALL(flow, func, ...)

void info(const char *fmt, ...);
void warning(const char *fmt, ...);
unsigned long tmr_jiffies(void);
int econn_props_update(void *props, const char *key, const char *value);
enum econn_state econn_current_state(struct econn *econn);
const char *econn_state_name(enum econn_state state);
int generate_or_gather_answer(struct ecall *ecall, struct econn *econn);