#include <stdbool.h>
#include <stdio.h>

#define SUNKBD_RET_RESET    0x01
#define SUNKBD_RET_LAYOUT   0x02
#define SUNKBD_RET_ALLUP    0x03
#define SUNKBD_KEY          0x7f
#define SUNKBD_RELEASE      0x80
#define IRQ_HANDLED         1
#define KERN_WARNING        ""

typedef int irqreturn_t;

struct sunkbd {
    int reset;
    int layout;
    bool enabled;
    unsigned short *keycode;
    void *dev;
    void *tq;
    void *wait;
};

static void *serio_get_drvdata(void *serio) { return NULL; }
static void wake_up_interruptible(void *wait) {}
static void schedule_work(void *tq) {}
static void input_report_key(void *dev, unsigned short keycode, int pressed) {}
static void input_sync(void *dev) {}