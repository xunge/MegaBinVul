#include <stdbool.h>
#include <string.h>

#define EOFC (-1)
#define ERRC (-2)
#define SAES_MAX_KEYLENGTH 32

#define AES_DECRYPT 0
#define AES_ENCRYPT 1

#define gs_error_VMerror 1
#define gs_error_rangecheck 2

typedef struct stream_state_s stream_state;
typedef struct stream_cursor_read_s stream_cursor_read;
typedef struct stream_cursor_write_s stream_cursor_write;
typedef struct stream_aes_state_s stream_aes_state;
typedef struct aes_context_s {
    int nr;
    unsigned int *rk;
    unsigned int buf[68];
} aes_context;

struct stream_cursor_read_s {
    const unsigned char *ptr;
    const unsigned char *limit;
};

struct stream_cursor_write_s {
    unsigned char *ptr;
    unsigned char *limit;
};

struct stream_aes_state_s {
    aes_context *ctx;
    void *memory;
    int keylength;
    unsigned char key[SAES_MAX_KEYLENGTH];
    unsigned char iv[16];
    bool initialized;
    bool use_padding;
};

void *gs_alloc_bytes_immovable(void *memory, size_t size, const char *name);
void gs_throw(int code, const char *msg);
void gs_throw1(int code, const char *msg, int arg);
void gs_warn1(const char *msg, unsigned char arg);
int aes_setkey_dec(aes_context *ctx, const unsigned char *key, int bits);
int aes_crypt_cbc(aes_context *ctx, int mode, size_t length, unsigned char iv[16], const unsigned char *input, unsigned char *output);