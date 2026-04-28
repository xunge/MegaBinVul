#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

#define ECRYPTFS_SALT_SIZE 8
#define ECRYPTFS_TAG_3_PACKET_TYPE 0x03
#define ECRYPTFS_MAX_ENCRYPTED_KEY_BYTES 64
#define RFC2440_CIPHER_AES_192 0x03
#define ECRYPTFS_PASSWORD 0x01
#define ECRYPTFS_CONTAINS_DECRYPTED_KEY 0x01
#define ECRYPTFS_CONTAINS_ENCRYPTED_KEY 0x02
#define ECRYPTFS_USERSPACE_SHOULD_TRY_TO_DECRYPT 0x04
#define ECRYPTFS_USERSPACE_SHOULD_TRY_TO_ENCRYPT 0x08
#define KERN_ERR ""
#define KERN_WARNING ""
#define GFP_KERNEL 0
#define unlikely(x) (x)
#define printk(fmt, ...)
#define ecryptfs_printk(level, fmt, ...)

typedef uint16_t u16;
typedef uint32_t u32;

struct list_head {
    struct list_head *next, *prev;
};

struct ecryptfs_crypt_stat {
    char cipher[32];
    int key_size;
};

struct ecryptfs_session_key {
    unsigned char encrypted_key[ECRYPTFS_MAX_ENCRYPTED_KEY_BYTES];
    size_t encrypted_key_size;
    uint32_t flags;
};

struct ecryptfs_password {
    unsigned char salt[ECRYPTFS_SALT_SIZE];
    uint32_t hash_iterations;
    uint8_t hash_algo;
};

struct ecryptfs_auth_tok {
    uint16_t token_type;
    union {
        struct ecryptfs_password password;
    } token;
    struct ecryptfs_session_key session_key;
};

struct ecryptfs_auth_tok_list_item {
    struct ecryptfs_auth_tok auth_tok;
    struct list_head list;
};

extern struct ecryptfs_auth_tok_list_item* ecryptfs_auth_tok_list_item_cache;
extern int ecryptfs_parse_packet_length(unsigned char *data, size_t *body_size, size_t *length_size);
extern void ecryptfs_cipher_code_to_string(char *cipher, u16 code);
extern void ecryptfs_init_crypt_ctx(struct ecryptfs_crypt_stat *crypt_stat);

static inline void* kmem_cache_zalloc(void* cache, int flags) {
    (void)cache; (void)flags;
    return calloc(1, sizeof(struct ecryptfs_auth_tok_list_item));
}

static inline void kmem_cache_free(void* cache, void* ptr) {
    (void)cache;
    free(ptr);
}

static inline void list_add(struct list_head *new, struct list_head *head) {
    new->next = head->next;
    new->prev = head;
    head->next->prev = new;
    head->next = new;
}

#define EINVAL 22
#define ENOMEM 12
#define ENOSYS 38