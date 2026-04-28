#include <assert.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stddef.h>
#include <time.h>

typedef struct Unit Unit;
typedef struct Timer Timer;
typedef struct TimerValue TimerValue;

#define TIMER(u) ((Timer*) (u))
#define UNIT_TRIGGER(u) ((Unit*) (u))
#define TIMER_DEAD 0
#define TIMER_FAILED 0
#define TIMER_ACTIVE 0
#define TIMER_SUCCESS 0
#define UNIT_LOADED 0
#define USEC_INFINITY 0
#define UID_INVALID 0
#define GID_INVALID 0
#define MODE_INVALID 0

struct dual_timestamp {
    struct timespec realtime;
};

static const struct dual_timestamp DUAL_TIMESTAMP_NULL = { .realtime = {0, 0} };

struct Timer {
    int state;
    char *stamp_path;
    TimerValue *values;
    int result;
    struct dual_timestamp last_trigger;
};

struct Unit {
    int load_state;
};

struct TimerValue {
    int base;
    bool disabled;
    TimerValue *value;
};

static inline struct timespec timespec_load(struct timespec *ts) {
    return *ts;
}

static void touch_file(const char *path, bool create, unsigned usec, int uid, int gid, int mode) {}

static void timer_enter_waiting(Timer *t, bool b) {}

#define LIST_FOREACH(value, v, head) \
    for ((v) = (head); (v) != NULL; (v) = (v)->value)