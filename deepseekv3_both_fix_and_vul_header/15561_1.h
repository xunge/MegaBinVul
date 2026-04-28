#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define EV_CNT 32
#define EV_KEY 0x01
#define EV_REL 0x02
#define EV_ABS 0x03
#define EV_MSC 0x04
#define EV_SW 0x05
#define EV_LED 0x11
#define EV_SND 0x12
#define EV_FF 0x15
#define EV_PWR 0x16

struct input_dev {
    unsigned long *evbit;
    unsigned long *keybit;
    unsigned long *relbit;
    unsigned long *absbit;
    unsigned long *mscbit;
    unsigned long *swbit;
    unsigned long *ledbit;
    unsigned long *sndbit;
    unsigned long *ffbit;
};

extern unsigned int input_max_code[EV_CNT];
extern void input_alloc_absinfo(struct input_dev *dev);
extern void pr_err(const char *fmt, ...);
extern void dump_stack(void);

#define __set_bit(nr, addr) ((addr)[(nr) / (8 * sizeof(long))] |= (1UL << ((nr) % (8 * sizeof(long)))))