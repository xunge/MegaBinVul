#include <stdint.h>

#define SSH_MSG_NEWKEYS 21
#define sshcrypto_FLAGSTRICTKEX 0x01

struct buf {
    uint8_t *buf;
};

struct {
    int flagkeys;
    uint32_t sendpacketid;
} packet;

extern void sshcrypto_packet_put(struct buf *b);
extern void packet_put_plain_(struct buf *b);
extern uint32_t sshcrypto_kex_flags;