#include <stdint.h>
#include <string.h>

typedef uint32_t crypto_uint32;

struct buf {
    char *buf;
    long long len;
};

struct kex_alg {
    const char *name;
    int flagenabled;
};

extern struct kex_alg sshcrypto_kexs[];
extern struct kex_alg sshcrypto_pseudokexs[];

size_t str_len(const char *s);
void buf_putnum32(struct buf *b, crypto_uint32 num);
void buf_puts(struct buf *b, const char *s);
void log_d2(const char *msg, const char *str);