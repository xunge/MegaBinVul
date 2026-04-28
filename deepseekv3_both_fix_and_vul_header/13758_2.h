#include <stdbool.h>
#include <errno.h>

enum {
    IR_HOMEBREW,
    IR_IRDEO,
    IR_IRDEO_REMOTE,
    IR_ANIMAX,
    IR_IGOR
};

static int type;
static int io;
static int irq;
static bool softcarrier;
static int sense;

struct hardware_info {
    bool set_send_carrier;
    bool set_duty_cycle;
};

static struct hardware_info hardware[5];

extern int serial_ir_init(void);
extern void serial_ir_exit(void);

#define __init
#define EINVAL 22