#include <stdint.h>
#include <string.h>

typedef uint8_t guint8;
typedef unsigned int guint;
typedef int gint;
typedef guint8 guchar;

typedef struct _StringInfo {
    guint8 *data;
    guint data_len;
} StringInfo;

typedef struct _SslCipherSuite {
    int mode;
    int block;
} SslCipherSuite;

typedef struct _SslDigest {
    int len;
} SslDigest;

typedef struct _SslWriteIv {
    guint8 *data;
    guint data_len;
} SslWriteIv;

typedef struct _SslDecoder {
    SslCipherSuite *cipher_suite;
    int compression;
    void *decomp;
    void *evp;
    uint64_t seq;
    SslWriteIv write_iv;
} SslDecoder;

typedef struct _SslDecryptSession {
    int version_netorder;
} SslDecryptSession;

#define MODE_CBC 1
#define MODE_GCM 2
#define MODE_CCM 3
#define MODE_CCM_8 4
#define MODE_STREAM 5

#define SSLV3_VERSION 0x0300
#define TLSV1_VERSION 0x0301
#define TLSV1DOT1_VERSION 0x0302
#define TLSV1DOT2_VERSION 0x0303
#define DTLSV1DOT0_VERSION 0xfeff
#define DTLSV1DOT2_VERSION 0xfefd
#define DTLSV1DOT0_VERSION_NOT 0xfefe

#define SSL_EX_NONCE_LEN_GCM 8

extern int ssl_ignore_mac_failed;
extern void ssl_debug_printf(const char *fmt, ...);
extern void ssl_print_data(const char *label, const guint8 *data, guint len);
extern void ssl_data_realloc(StringInfo *str, guint len);
extern void ssl_data_copy(StringInfo *dst, StringInfo *src);
extern int ssl_cipher_decrypt(void *evp, guint8 *out, guint out_len, const guint8 *in, guint in_len);
extern int ssl3_check_mac(SslDecoder *decoder, gint ct, guint8 *data, guint len, guint8 *mac);
extern int tls_check_mac(SslDecoder *decoder, gint ct, int version, guint8 *data, guint len, guint8 *mac);
extern int dtls_check_mac(SslDecoder *decoder, gint ct, int version, guint8 *data, guint len, guint8 *mac);
extern int ssl_decompress_record(void *decomp, guint8 *in, guint in_len, StringInfo *out, guint *out_len);
extern const char *gcry_strsource(int err);
extern const char *gcry_strerror(int err);
extern int gcry_cipher_setiv(void *h, const void *k, size_t l);
extern int gcry_cipher_setctr(void *h, const void *ctr, size_t l);
extern SslDigest *ssl_cipher_suite_dig(SslCipherSuite *cs);