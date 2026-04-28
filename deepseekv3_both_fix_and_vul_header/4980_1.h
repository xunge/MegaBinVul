#include <stdint.h>
#include <stdlib.h>

#define CEPHX_ENC_MAGIC 0
#define GFP_NOFS 0
#define EINVAL (-1)
#define ENOMEM (-2)
#define EPERM (-3)

struct ceph_crypto_key;
struct ceph_x_encrypt_header {
    uint8_t struct_v;
    uint64_t magic;
};

int ceph_decode_32(void **p);
int ceph_decrypt2(struct ceph_crypto_key *secret, void *head, size_t *head_len,
                 void *obuf, size_t *olen, void *p, int len);
void dout(const char *fmt, ...);