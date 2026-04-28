#include <stdint.h>

typedef int64_t ktime_t;
typedef uint64_t u64;
typedef uint32_t u32;

struct sock {
    u32 sk_pacing_rate;
};

struct sk_buff {
    unsigned int len;
};

struct hrtimer {
    int dummy;
};

struct tcp_sock {
    struct hrtimer pacing_timer;
};

#define NSEC_PER_SEC 1000000000L
#define HRTIMER_MODE_ABS_PINNED_SOFT 0

static inline struct tcp_sock *tcp_sk(const struct sock *sk) { return (struct tcp_sock *)sk; }
static inline int tcp_needs_internal_pacing(const struct sock *sk) { return 0; }
static inline ktime_t ktime_get(void) { return 0; }
static inline ktime_t ktime_add_ns(ktime_t kt, u64 ns) { return kt + ns; }
static inline int hrtimer_is_queued(const struct hrtimer *timer) { return 0; }
static inline ktime_t hrtimer_get_softexpires(const struct hrtimer *timer) { return 0; }
static inline int ktime_after(ktime_t a, ktime_t b) { return a > b; }
static inline int hrtimer_try_to_cancel(struct hrtimer *timer) { return 0; }
static inline void hrtimer_start(struct hrtimer *timer, ktime_t time, int mode) {}
static inline void sock_hold(struct sock *sk) {}
static inline void __sock_put(struct sock *sk) {}
static inline u64 do_div(u64 *n, u32 base) { u64 rem = *n % base; *n = *n / base; return rem; }