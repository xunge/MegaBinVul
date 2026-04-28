#include <stddef.h>

struct evtchn_ops {
    int (*percpu_init)(unsigned int);
};

extern struct evtchn_ops *evtchn_ops;