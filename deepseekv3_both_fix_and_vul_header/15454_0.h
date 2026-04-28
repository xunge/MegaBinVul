#include <stdint.h>
#include <errno.h>

#define PACKET_UNAUTHENTICATED_MESSAGES 10
#define SSH_MSG_DISCONNECT 1
#define SSH_MSG_IGNORE 2
#define SSH_MSG_DEBUG 4
#define NUMTOSTR_LEN 32

struct buf {
    uint8_t *buf;
    int len;
};

struct packet {
    int flagauthorized;
    int receivepacketid;
    int flagkeys;
} packet;

extern int sshcrypto_kex_flags;
#define sshcrypto_FLAGSTRICTKEX (1 << 0)
#define SSH_MSG_NEWKEYS 21

void buf_purge(struct buf *b);
int packet_get_(struct buf *b);
void log_f1(const char *msg);
void log_f4(const char *msg1, const char *msg2, const char *msg3, const char *msg4);
void global_die(int code);
char *numtostr(char *buf, uint8_t num);

typedef uint8_t crypto_uint8;