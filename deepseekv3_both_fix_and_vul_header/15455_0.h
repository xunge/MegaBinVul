#include <stdint.h>

struct buf {
    uint8_t *buf;
};

struct {
    int flagkeys;
    uint32_t sendpacketid;
} packet;

#define SSH_MSG_NEWKEYS 21

extern void sshcrypto_packet_put(struct buf *b);
extern void packet_put_plain_(struct buf *b);

extern unsigned int sshcrypto_kex_flags;
#define sshcrypto_FLAGSTRICTKEX (1 << 0)