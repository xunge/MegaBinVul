#include <stddef.h>

#define SSL_F_DTLS1_PREPROCESS_FRAGMENT 0
#define SSL_R_EXCESSIVE_MESSAGE_SIZE 0
#define ERR_R_BUF_LIB 0
#define SSL_AD_ILLEGAL_PARAMETER 0
#define SSL_AD_INTERNAL_ERROR 0
#define DTLS1_HM_HEADER_LENGTH 0

struct hm_header_st {
    unsigned char type;
    unsigned long msg_len;
    unsigned short seq;
    unsigned long frag_off;
    unsigned long frag_len;
};

typedef struct ssl_st SSL;
typedef struct buf_mem_st BUF_MEM;

struct ssl_st {
    struct {
        struct {
            struct {
                unsigned long message_size;
                unsigned char message_type;
            } tmp;
        } *s3;
        struct {
            struct hm_header_st r_msg_hdr;
        } *d1;
        BUF_MEM *init_buf;
    };
};

void SSLerr(int a, int b);
int BUF_MEM_grow_clean(BUF_MEM *buf, size_t len);