#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

struct sshbuf {
    // Minimal definition for compilation
    size_t len;
    uint8_t *data;
};

struct ssh {
    struct kex *kex;
};

struct kex {
    struct newkeys *newkeys[2];
};

struct sshcomp {
    uint32_t type;
    uint32_t enabled;
    char *name;
};

struct sshenc {
    char *name;
    int cipher;
    uint32_t enabled;
    uint32_t block_size;
    uint8_t *key;
    size_t key_len;
    uint8_t *iv;
    size_t iv_len;
};

struct sshmac {
    char *name;
    uint32_t enabled;
    uint8_t *key;
    size_t key_len;
};

struct newkeys {
    struct sshenc enc;
    struct sshmac mac;
    struct sshcomp comp;
};

#define SSH_ERR_ALLOC_FAIL -1
#define SSH_ERR_INVALID_FORMAT -2
#define DEBUG_PK 0

typedef uint32_t u_int;

// Minimal function declarations for compilation
static int sshbuf_froms(struct sshbuf *m, struct sshbuf **b) { return 0; }
static void sshbuf_dump(struct sshbuf *b, FILE *f) {}
static int sshbuf_get_cstring(struct sshbuf *b, char **s, size_t *len) { return 0; }
static int sshbuf_get(struct sshbuf *b, void *v, size_t len) { return 0; }
static int sshbuf_get_u32(struct sshbuf *b, uint32_t *val) { return 0; }
static int sshbuf_get_string(struct sshbuf *b, uint8_t **val, size_t *len) { return 0; }
static size_t sshbuf_len(struct sshbuf *b) { return 0; }
static void sshbuf_free(struct sshbuf *b) {}
static int cipher_authlen(int cipher) { return 0; }
static int cipher_by_name(const char *name) { return 0; }
static int mac_setup(struct sshmac *mac, const char *name) { return 0; }