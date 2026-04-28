#include <stdatomic.h>
#include <stdint.h>

struct snd_timer {
    unsigned long sticks;
    void *private_data;
};

struct snd_hrtimer {
    atomic_int running;
    uint64_t hrt;
};

#define HRTIMER_MODE_REL 0
#define resolution 1

static inline void atomic_set(atomic_int* obj, int desired) {
    *obj = desired;
}

static inline void hrtimer_cancel(uint64_t* timer) {}
static inline void hrtimer_start(uint64_t* timer, uint64_t time, int mode) {}
static inline uint64_t ns_to_ktime(uint64_t ns) { return ns; }