#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

typedef struct congestion_control_t congestion_control_t;

typedef struct ratelim_t {
    int64_t last_allowed;
    int n_calls_since_last_time;
    int interval;
    int burst;
} ratelim_t;

#define RATELIM_INIT(interval) {0,0,interval,0}
#define LOG_INFO 0
#define LOG_NOTICE 0
#define LOG_PROTOCOL_WARN 0
#define LD_CIRC 0

extern bool is_monotime_clock_broken;

void log_fn_ratelim(ratelim_t *lim, int severity, int domain, const char *fmt, ...);
bool time_delta_should_use_heuristics(const congestion_control_t *cc);