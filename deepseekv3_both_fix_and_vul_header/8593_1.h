#include <stdint.h>

#define NANOSECONDS_PER_SECOND 1000000000

typedef struct QEMUSerialSetParams {
    int speed;
    int parity;
    int data_bits;
    int stop_bits;
} QEMUSerialSetParams;

typedef struct SerialState {
    int divider;
    int lcr;
    int baudbase;
    int char_transmit_time;
    void *chr;
} SerialState;

#define CHR_IOCTL_SERIAL_SET_PARAMS 1

extern void qemu_chr_fe_ioctl(void *chr, int cmd, void *arg);
extern void DPRINTF(const char *fmt, ...);