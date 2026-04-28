#include <stdbool.h>
#include <stdatomic.h>

struct domain {
    _Atomic unsigned int valid_evtchns;
};

typedef bool bool_t;