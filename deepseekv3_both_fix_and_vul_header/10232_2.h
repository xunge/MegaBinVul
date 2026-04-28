#include <arpa/inet.h>
#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    uint16_t type;
    uint16_t length;
} part_signature_head_t;

typedef struct {
    part_signature_head_t head;
    char *username;
    unsigned char hash[32];
} part_signature_sha256_t;

typedef struct {
    struct {
        struct {
            void *userdb;
        } server;
    } data;
} sockent_t;

typedef struct {
    int dummy;
} c_complain_t;

#define C_COMPLAIN_INIT_STATIC {0}
#define PART_SIGNATURE_SHA256_SIZE (sizeof(part_signature_head_t) + 32)
#define BUFFER_READ(dst, len) do { \
    memcpy(dst, buffer + buffer_offset, len); \
    buffer_offset += len; \
} while (0)

#define LOG_NOTICE 0
#define PP_SIGNED 0
#define ENOMEM (-1)
#define ENOENT (-2)

typedef void* gcry_md_hd_t;
typedef int gcry_error_t;
#define GCRY_MD_SHA256 0
#define GCRY_MD_FLAG_HMAC 0

void c_complain(int level, c_complain_t *c, const char *format);
void ERROR(const char *format, ...);
void WARNING(const char *format, ...);

const char* gcry_strerror(gcry_error_t err);
gcry_error_t gcry_md_open(gcry_md_hd_t *hd, int algo, unsigned int flags);
gcry_error_t gcry_md_setkey(gcry_md_hd_t hd, const void *key, size_t keylen);
void gcry_md_write(gcry_md_hd_t hd, const void *buffer, size_t length);
unsigned char* gcry_md_read(gcry_md_hd_t hd, int algo);
void gcry_md_close(gcry_md_hd_t hd);

void *fbh_get(void *userdb, const char *username);
void parse_packet(sockent_t *se, char *buffer, size_t buffer_len, int flags, char *username);
void sfree(void *ptr);