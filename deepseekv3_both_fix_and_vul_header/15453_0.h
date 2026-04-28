#include <stdint.h>
#include <errno.h>

typedef uint8_t crypto_uint8;

struct sshcrypto_kex {
    const char *name;
    int flagenabled;
    const char *enc;
    unsigned long long kem_publickeybytes;
    unsigned long long kem_ciphertextbytes;
    unsigned long long kem_bytes;
    const char *hash;
    unsigned long long hash_bytes;
    void (*buf_putkemkey)(void);
};

struct sshcrypto_pseudokex {
    const char *name;
    const char *cname;
    int flag;
};

extern const struct sshcrypto_kex sshcrypto_kexs[];
extern const struct sshcrypto_pseudokex sshcrypto_pseudokexs[];
extern const char *sshcrypto_kex_name;
extern int sshcrypto_kex_flags;
extern const char *sshcrypto_enc;
extern unsigned long long sshcrypto_kem_publickeybytes;
extern unsigned long long sshcrypto_kem_ciphertextbytes;
extern unsigned long long sshcrypto_kem_bytes;
extern const char *sshcrypto_hash;
extern unsigned long long sshcrypto_hash_bytes;
extern void (*sshcrypto_buf_putkemkey)(void);

extern long long stringparser(const unsigned char *buf, long long len, long long pos, unsigned char **x, long long *xlen);
extern int str_equaln(const char *a, long long alen, const char *b);
extern void bug_proto(void);
extern void log_d2(const char *msg, const char *data);