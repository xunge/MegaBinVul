#include <stdint.h>

#define sshcrypto_kem_PUBLICKEYMAX 32
#define sshcrypto_kem_CIPHERTEXTMAX 32
#define sshcrypto_kem_MAX 32
#define sshcrypto_sign_MAX 64
#define sshcrypto_cipher_KEYMAX 32
#define sshcrypto_hash_MAX 32

#define SSH_MSG_KEXDH_INIT 30
#define SSH_MSG_KEXDH_REPLY 31
#define SSH_MSG_NEWKEYS 21

struct buf {
    unsigned char *buf;
    long long len;
};

struct {
    int kex_packet_follows;
    int kex_guess;
    struct buf hashbuf;
    struct buf helloreceive;
    struct buf hellosend;
    struct buf kexrecv;
    struct buf kexsend;
    unsigned char sessionid[32];
    int flagrekeying;
    unsigned char clientnonce[32];
    unsigned char servernonce[32];
    unsigned char clientkey[32];
    unsigned char serverkey[32];
    unsigned char clientmackey[32];
    unsigned char servermackey[32];
} packet;

typedef uint8_t crypto_uint8;
typedef uint32_t crypto_uint32;

extern int sshcrypto_kem_publickeybytes;
extern int sshcrypto_kem_ciphertextbytes;
extern int sshcrypto_sign_bytes;
extern int sshcrypto_hash_bytes;
extern unsigned char sshcrypto_sign_publickey[];

extern void bug_proto();
extern int packet_getall(struct buf *b, int type);
extern void buf_purge(struct buf *b);
extern long long packetparser_uint8(const unsigned char *buf, long long len, long long pos, crypto_uint8 *ch);
extern long long packetparser_uint32(const unsigned char *buf, long long len, long long pos, crypto_uint32 *len_out);
extern long long packetparser_copy(const unsigned char *buf, long long len, long long pos, unsigned char *out, long long outlen);
extern long long packetparser_end(const unsigned char *buf, long long len, long long pos);
extern int sshcrypto_enc(unsigned char *serverpk, unsigned char *sharedsecret, const unsigned char *clientpk);
extern void buf_putstringlen(struct buf *b, const unsigned char *s, long long len);
extern void sshcrypto_buf_putsignpk(struct buf *b, const unsigned char *pk);
extern void sshcrypto_buf_putkemkey(struct buf *b, const unsigned char *key);
extern void sshcrypto_hash(unsigned char *out, const unsigned char *in, long long inlen);
extern void byte_copy(void *dst, long long len, const void *src);
extern int subprocess_sign(unsigned char *sm, long long smlen, const char *keydir, const unsigned char *hash, long long hashlen);
extern void buf_putnum8(struct buf *b, crypto_uint8 num);
extern void sshcrypto_buf_putsignature(struct buf *b, const unsigned char *sm);
extern void packet_put(struct buf *b);
extern int packet_sendall();
extern void buf_put(struct buf *b, const unsigned char *s, long long len);
extern void purge(void *ptr, long long len);