#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>

typedef struct NetClientState NetClientState;
typedef struct stellaris_enet_state stellaris_enet_state;

struct stellaris_enet_state {
    uint32_t rctl;
    uint32_t ris;
    int np;
    int next_packet;
    struct {
        uint8_t data[2048];
        size_t len;
    } rx[31];
};

#define SE_RCTL_RXEN (1 << 0)
#define SE_INT_FOV   (1 << 1)
#define SE_INT_RX    (1 << 2)

#define DPRINTF(fmt, ...) do { } while (0)

static uint32_t crc32(uint32_t crc, const uint8_t *buf, size_t len)
{
    crc = ~crc;
    while (len--) {
        crc ^= *buf++;
        for (int i = 0; i < 8; i++)
            crc = (crc >> 1) ^ (0xEDB88320 & -(crc & 1));
    }
    return ~crc;
}

static void stellaris_enet_update(stellaris_enet_state *s) {}
static void *qemu_get_nic_opaque(NetClientState *nc) { return NULL; }