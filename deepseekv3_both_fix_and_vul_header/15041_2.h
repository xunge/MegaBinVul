#include <stdint.h>
#include <string.h>

#define __user
#define __be16 uint16_t
#define u32 uint32_t
#define u8 uint8_t
#define sctp_paramhdr_t struct sctp_paramhdr

#define EACCES 13
#define EINVAL 22
#define EFAULT 14

struct sock;

struct sctp_authchunks {
    u32 gauth_assoc_id;
    u32 gauth_number_of_chunks;
    char gauth_chunks[0];
};

struct sctp_paramhdr {
    __be16 length;
    __be16 type;
};

struct sctp_chunks_param {
    struct sctp_paramhdr param_hdr;
    u8 chunks[0];
};

struct sctp_association {
    struct {
        struct sctp_chunks_param *peer_chunks;
    } peer;
};

static inline __be16 ntohs(__be16 x) {
    return ((x >> 8) & 0xff) | ((x & 0xff) << 8);
}

static int copy_from_user(void *dst, const void __user *src, unsigned long size) {
    memcpy(dst, src, size);
    return 0;
}

static int copy_to_user(void __user *dst, const void *src, unsigned long size) {
    memcpy(dst, src, size);
    return 0;
}

static int put_user(int src, int __user *dst) {
    *dst = src;
    return 0;
}

extern struct sctp_association *sctp_id2assoc(struct sock *sk, u32 assoc_id);
extern int sctp_auth_enable;