#include <stdint.h>
#include <stdlib.h>

typedef struct QEMUFile QEMUFile;
typedef struct QEMUTimer QEMUTimer;

typedef struct TSC210xState {
    uint16_t x;
    uint16_t y;
    uint8_t pressure;
    uint8_t state;
    uint8_t page;
    uint8_t offset;
    uint8_t command;
    uint8_t irq;
    uint16_t dav;
    QEMUTimer *timer;
    uint8_t enabled;
    uint8_t host_mode;
    uint8_t function;
    uint8_t nextfunction;
    uint8_t precision;
    uint8_t nextprecision;
    uint8_t filter;
    uint8_t pin_func;
    uint8_t ref;
    uint8_t timing;
    uint32_t noise;
    uint16_t audio_ctrl1;
    uint16_t audio_ctrl2;
    uint16_t audio_ctrl3;
    uint16_t pll[2];
    uint16_t volume;
    int64_t volume_change;
    int64_t powerdown;
    uint8_t softstep;
    uint16_t dac_power;
    uint16_t filter_data[0x14];
    int busy;
    void *pint;
    void *davint;
} TSC210xState;

#define QEMU_CLOCK_VIRTUAL 1
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define EINVAL 22

extern int64_t qemu_clock_get_ns(int clock_type);
extern uint16_t qemu_get_be16(QEMUFile *f);
extern uint8_t qemu_get_byte(QEMUFile *f);
extern void qemu_get_be16s(QEMUFile *f, uint16_t *pv);
extern void timer_get(QEMUFile *f, QEMUTimer *timer);
extern int timer_pending(QEMUTimer *timer);
extern void qemu_set_irq(void *irq, int level);
extern int64_t qemu_get_sbe64(QEMUFile *f);
extern uint32_t qemu_get_be32(QEMUFile *f);

static const uint8_t mode_regs[] = {0};
static const uint8_t resolution[] = {0};