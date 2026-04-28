#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef unsigned int krb5_ui_4;
typedef int krb5_error_code;
typedef struct krb5_context_data *krb5_context;
typedef struct krb5_pac_data *krb5_pac;

#define KRB5_CALLCONV
#define PACTYPE_LENGTH 8
#define MAX_BUFFERS 256
#define PAC_INFO_BUFFER_LENGTH 16
#define PAC_ALIGNMENT 8

typedef struct {
    krb5_ui_4 ulType;
    krb5_ui_4 cbBufferSize;
    unsigned long long Offset;
} PAC_INFO_BUFFER;

typedef struct {
    krb5_ui_4 cBuffers;
    krb5_ui_4 Version;
    PAC_INFO_BUFFER Buffers[1];
} PACTYPE;

struct krb5_pac_data {
    PACTYPE *pac;
    struct {
        void *data;
        size_t length;
    } data;
};

static inline krb5_ui_4 load_32_le(const unsigned char *p) {
    return p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24);
}

static inline unsigned long long load_64_le(const unsigned char *p) {
    return (unsigned long long)p[0] | ((unsigned long long)p[1] << 8) |
           ((unsigned long long)p[2] << 16) | ((unsigned long long)p[3] << 24) |
           ((unsigned long long)p[4] << 32) | ((unsigned long long)p[5] << 40) |
           ((unsigned long long)p[6] << 48) | ((unsigned long long)p[7] << 56);
}

krb5_error_code krb5_pac_init(krb5_context, krb5_pac *);
void krb5_pac_free(krb5_context, krb5_pac);