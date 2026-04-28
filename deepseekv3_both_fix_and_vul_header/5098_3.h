#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef uint8_t __u8;
typedef uint16_t __u16;

struct device {
    // Minimal device structure
};

struct serial {
    struct device *dev;
};

struct serial_port {
    struct device dev;
    int port_number;
    struct serial *serial;  // Added serial pointer
};

struct edgeport_port {
    struct serial_port *port;
    int baud_rate;
    __u8 bUartMode;
};

struct ktermios {
    unsigned int c_cflag;
};

struct tty_struct {
    struct ktermios termios;
};

struct ump_uart_config {
    __u16 wFlags;
    __u16 wBaudRate;
    __u8 bDataBits;
    __u8 bParity;
    __u8 bStopBits;
    __u8 cXon;
    __u8 cXoff;
    __u8 bUartMode;
};

#define UMP_MASK_UART_FLAGS_RECEIVE_MS_INT    0x0001
#define UMP_MASK_UART_FLAGS_AUTO_START_ON_ERR 0x0002
#define UMP_MASK_UART_FLAGS_PARITY            0x0008
#define UMP_MASK_UART_FLAGS_OUT_X_CTS_FLOW    0x0010
#define UMP_MASK_UART_FLAGS_RTS_FLOW          0x0020
#define UMP_MASK_UART_FLAGS_IN_X              0x0040
#define UMP_MASK_UART_FLAGS_OUT_X             0x0080

#define UMP_UART_CHAR5BITS    0x00
#define UMP_UART_CHAR6BITS    0x01
#define UMP_UART_CHAR7BITS    0x02
#define UMP_UART_CHAR8BITS    0x03

#define UMP_UART_NOPARITY     0x00
#define UMP_UART_ODDPARITY    0x01
#define UMP_UART_EVENPARITY   0x02

#define UMP_UART_STOPBIT1     0x00
#define UMP_UART_STOPBIT2     0x01

#define UMPC_SET_CONFIG       0x00
#define UMPM_UART1_PORT       0x00

#define GFP_KERNEL            0

#define CSIZE   0x00000300
#define CS5     0x00000000
#define CS6     0x00000100
#define CS7     0x00000200
#define CS8     0x00000300
#define PARENB  0x00001000
#define PARODD  0x00002000
#define CSTOPB  0x00004000
#define CRTSCTS 0x80000000
#define CMSPAR  0x40000000

#define I_IXOFF(tty) 0
#define I_IXON(tty)  0
#define START_CHAR(tty) 0x11
#define STOP_CHAR(tty) 0x13

static inline void cpu_to_be16s(__u16 *val) {
    *val = ((*val >> 8) & 0xff) | ((*val & 0xff) << 8);
}

static inline void *kmalloc(size_t size, int flags) {
    return malloc(size);
}

static inline void kfree(void *ptr) {
    free(ptr);
}

static int send_cmd(struct device *dev, __u8 cmd, __u8 port, __u8 spec1, __u8 *data, size_t size) {
    return 0;
}

static void restart_read(struct edgeport_port *edge_port) {}

static int tty_get_baud_rate(struct tty_struct *tty) {
    return 9600;
}

static void tty_encode_baud_rate(struct tty_struct *tty, int ibaud, int obaud) {}

static void dev_dbg(struct device *dev, const char *fmt, ...) {}