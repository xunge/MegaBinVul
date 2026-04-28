#include <stdbool.h>

typedef bool bool_t;
typedef unsigned int evtchn_port_t;

struct domain {
    struct evtchn_port_ops *evtchn_port_ops;
};

struct evtchn_port_ops {
    bool_t (*is_pending)(struct domain *d, evtchn_port_t port);
};