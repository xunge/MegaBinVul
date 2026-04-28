#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <arpa/inet.h>
#include <stddef.h>
#include <endian.h>

struct list_head {
    struct list_head *next, *prev;
};

struct io_buffer {
    void *data;
    void *tail;
    struct list_head list;
};

struct tls_cipherspec {
    struct tls_cipher_suite *suite;
    uint8_t fixed_iv[16];
    void *cipher_ctx;
};

struct tls_cipher_suite {
    struct cipher_algorithm *cipher;
    struct digest_algorithm *digest;
    size_t fixed_iv_len;
    size_t record_iv_len;
    size_t mac_len;
};

struct cipher_algorithm {
    int dummy;
};

struct digest_algorithm {
    size_t digestsize;
};

struct tls_auth_header {
    uint64_t seq;
    struct {
        uint8_t type;
        uint16_t version;
        uint16_t length;
    } header;
};

struct tls_connection {
    struct tls_cipherspec rx_cipherspec;
    uint64_t rx_seq;
    struct list_head rx_data;
};

struct tls_header {
    uint8_t type;
    uint16_t version;
    uint16_t length;
};

#define DBGC(tls, fmt, ...)
#define DBGC_HD(tls, data, len)
#define DBGC2(tls, fmt, ...)
#define DBGC2_HD(tls, data, len)

#define EINVAL_IV 1
#define EINVAL_MAC 2

#define __attribute__(x)

static inline size_t iob_len(struct io_buffer *iob) { return 0; }
static inline void iob_pull(struct io_buffer *iob, size_t len) {}
static inline void iob_unput(struct io_buffer *iob, size_t len) {}

static inline void cipher_setiv(struct cipher_algorithm *cipher, void *ctx, void *iv, size_t len) {}
static inline void cipher_decrypt(struct cipher_algorithm *cipher, void *ctx, void *dst, void *src, size_t len) {}

static inline int is_block_cipher(struct cipher_algorithm *cipher) { return 0; }
static inline int tls_verify_padding(struct tls_connection *tls, struct io_buffer *iob) { return 0; }

static inline void tls_hmac_list(struct tls_cipherspec *cipherspec, struct tls_auth_header *authhdr, struct list_head *rx_data, uint8_t *mac) {}
static inline int tls_new_record(struct tls_connection *tls, uint8_t type, struct list_head *rx_data) { return 0; }

#define list_empty(list) ((list)->next == (list))
#define list_first_entry(ptr, type, member) \
    container_of((ptr)->next, type, member)
#define list_last_entry(ptr, type, member) \
    container_of((ptr)->prev, type, member)
#define list_for_each_entry(pos, head, member) \
    for (pos = list_first_entry(head, typeof(*pos), member); \
         &pos->member != (head); \
         pos = list_next_entry(pos, member))
#define list_next_entry(pos, member) \
    container_of((pos)->member.next, typeof(*(pos)), member)
#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))