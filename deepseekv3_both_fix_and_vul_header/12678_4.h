#include <stdbool.h>
#include <stddef.h>

#define HZ 100

struct work_struct {
    // minimal stub
};

struct input_dev {
    unsigned long led;
    unsigned long snd;
};

struct serio;

struct sunkbd {
    struct work_struct tq;
    int wait;
    int reset;
    bool enabled;
    struct serio *serio;
    struct input_dev *dev;
};

#define SUNKBD_CMD_SETLED   0x01
#define SUNKBD_CMD_NOCLICK  0x02
#define SUNKBD_CMD_BELLOFF  0x03

#define LED_CAPSL   0
#define LED_SCROLLL 1
#define LED_COMPOSE 2
#define LED_NUML    3
#define SND_CLICK   0
#define SND_BELL    1

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))
#define test_bit(nr, addr) ((addr) & (1UL << (nr)))