#include <sys/epoll.h>
#include <sys/signalfd.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#define UEV_MAX_EVENTS 64
#define UEV_NONBLOCK   1
#define UEV_ONCE       2
#define UEV_ERROR      4
#define UEV_HUP        8
#define UEV_READ       16
#define UEV_EVENT_MASK 0xFFFF

typedef enum {
    UEV_IO_TYPE,
    UEV_SIGNAL_TYPE,
    UEV_TIMER_TYPE,
    UEV_CRON_TYPE,
    UEV_EVENT_TYPE
} uev_type_t;

typedef struct uev {
    int fd;
    int active;
    uev_type_t type;
    void (*cb)(struct uev *, void *, uint32_t);
    void *arg;
    union {
        struct {
            time_t when;
            time_t interval;
        } c;
        struct {
            time_t timeout;
            time_t period;
        } t;
    } u;
    struct signalfd_siginfo siginfo;
    struct uev *next;
} uev_t;

typedef struct uev_ctx {
    int fd;
    int running;
    int maxevents;
    int workaround;
    uev_t *watchers;
} uev_ctx_t;

#define _UEV_FOREACH(w, list) for (w = list; w; w = w->next)
#define _UEV_REMOVE(w, list) /* Implementation depends on list structure */

int uev_cron_set(uev_t *w, time_t when, time_t interval);
int uev_timer_set(uev_t *w, time_t timeout, time_t period);
void uev_exit(uev_ctx_t *ctx);
int uev_io_stop(uev_t *w);
int uev_signal_start(uev_t *w);
int uev_signal_stop(uev_t *w);
int uev_timer_stop(uev_t *w);
int uev_cron_stop(uev_t *w);
int has_data(int fd);