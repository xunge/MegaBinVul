#include <stdint.h>

struct buf;
struct {
    int flagkeys;
    uint32_t receivepacketid;
} packet;

int sshcrypto_packet_get(struct buf *b);
int packet_get_plain_(struct buf *b);
void log_f1(const char *msg);
void global_die(int code);