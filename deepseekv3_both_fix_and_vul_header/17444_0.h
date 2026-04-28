#include <stdbool.h>

typedef struct congestion_control_t {
    bool in_slow_start;
    unsigned long ewma_rtt_usec;
    unsigned long bdp[1];
} congestion_control_t;

#define BDP_ALG_SENDME_RATE 0