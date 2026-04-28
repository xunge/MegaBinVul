#include <stddef.h>
#include <stdint.h>
#include <string.h>

typedef struct NetClientState NetClientState;
typedef long ssize_t;

struct MACAddr {
    uint8_t a[6];
};

struct xlx_ethlite {
    int rxbuf;
    uint32_t *regs;
    struct {
        struct MACAddr macaddr;
    } conf;
    int c_rx_pingpong;
};

#define R_RX_CTRL0 0
#define R_RX_BUF0 0
#define R_MAX 0
#define CTRL_S 0
#define CTRL_I 0

static void eth_pulse_irq(struct xlx_ethlite *s) {}
static void D(int x) {}
static struct xlx_ethlite *qemu_get_nic_opaque(NetClientState *nc) { return NULL; }
static int qemu_log(const char *fmt, ...) { return 0; }