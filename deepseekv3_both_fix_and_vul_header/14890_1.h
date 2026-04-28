#include <stddef.h>
#include <stdint.h>

typedef int64_t s64;

typedef struct {
    int64_t tv64;
} ktime_t;

struct hrtimer_base {
    ktime_t resolution;
};

struct hrtimer {
    ktime_t expires;
    struct hrtimer_base *base;
};

#define unlikely(x) (x)
#define KTIME_SEC_MAX ((s64)9223372036854775807LL)

static inline ktime_t ktime_sub(ktime_t a, ktime_t b) {
    ktime_t res;
    res.tv64 = a.tv64 - b.tv64;
    return res;
}

static inline s64 ktime_to_ns(ktime_t t) {
    return t.tv64;
}

static inline ktime_t ktime_add_ns(ktime_t t, s64 ns) {
    ktime_t res;
    res.tv64 = t.tv64 + ns;
    return res;
}

static inline ktime_t ktime_add(ktime_t a, ktime_t b) {
    ktime_t res;
    res.tv64 = a.tv64 + b.tv64;
    return res;
}

static inline ktime_t ktime_set(const s64 secs, const unsigned long nsecs) {
    ktime_t res;
    res.tv64 = secs * 1000000000LL + nsecs;
    return res;
}

static inline unsigned long ktime_divns(ktime_t div, s64 ns) {
    return div.tv64 / ns;
}