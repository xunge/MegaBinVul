#include <time.h>
#include <sys/types.h>
#include <unistd.h>

typedef long long ktime_t;
typedef int clockid_t;

enum alarmtimer_type {
    ALARM_REALTIME,
    ALARM_BOOTTIME
};

struct timespec64 {
    long long tv_sec;
    long tv_nsec;
};

struct alarm {
    enum alarmtimer_type type;
    void (*function)(struct alarm *, ktime_t);
};

struct restart_block {
    long (*fn)(struct restart_block *);
    struct {
        clockid_t clockid;
        ktime_t expires;
    } nanosleep;
};

struct alarm_base {
    ktime_t (*gettime)(void);
};

extern struct alarm_base alarm_bases[2];
extern struct {
    struct restart_block restart_block;
} *current;

#define TIMER_ABSTIME 1
#define CAP_WAKE_ALARM 0
#define ENOTSUPP 95
#define EINVAL 22
#define EPERM 1
#define ERESTART_RESTARTBLOCK 512
#define ERESTARTNOHAND 514

extern int alarmtimer_get_rtcdev(void);
extern enum alarmtimer_type clock2alarm(clockid_t which_clock);
extern void alarm_init_on_stack(struct alarm *alarm, enum alarmtimer_type type,
                void (*function)(struct alarm *, ktime_t));
extern ktime_t timespec64_to_ktime(struct timespec64 ts);
extern ktime_t ktime_add(ktime_t a, ktime_t b);
extern int alarmtimer_do_nsleep(struct alarm *alarm, ktime_t exp, enum alarmtimer_type type);
extern int capable(int cap);

void alarmtimer_nsleep_wakeup(struct alarm *alarm, ktime_t now);
long alarm_timer_nsleep_restart(struct restart_block *restart);