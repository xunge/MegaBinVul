#include <stdlib.h>

struct pnp_dev;
struct rc_dev;
struct timer_list {
    // Minimal timer_list definition
    int dummy;
};

struct ene_device {
    struct rc_dev *rdev;
    struct timer_list tx_sim_timer;
    unsigned long hw_lock;
    unsigned int irq;
    unsigned long hw_io;
};

#define ENE_IO_SIZE 0x10