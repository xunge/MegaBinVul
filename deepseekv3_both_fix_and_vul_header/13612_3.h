#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define CCP_VERSION(major, minor) ((major << 16) | minor)
#define CCP_SB_BYTES 32
#define LSB_ITEM_SIZE 16
#define CCP_NEW_JOBID(ccp) (0)
#define CCP_PASSTHRU_BYTESWAP_256BIT 0
#define CCP_ENGINE_SHA 0
#define GFP_KERNEL 0

#define SHA1_DIGEST_SIZE 20
#define SHA224_DIGEST_SIZE 28
#define SHA256_DIGEST_SIZE 32
#define SHA384_DIGEST_SIZE 48
#define SHA512_DIGEST_SIZE 64
#define SHA1_BLOCK_SIZE 64
#define SHA224_BLOCK_SIZE 64
#define SHA256_BLOCK_SIZE 64
#define SHA384_BLOCK_SIZE 128
#define SHA512_BLOCK_SIZE 128

#define DMA_BIDIRECTIONAL 0
#define DMA_TO_DEVICE 1

#define EINVAL 22
#define ENOMEM 12

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;

struct scatterlist {
    void *address;
    unsigned int length;
};

struct ccp_cmd_queue;
struct ccp_dm_workarea {
    void *address;
};
struct ccp_data {
    struct {
        size_t bytes_left;
    } sg_wa;
};
struct ccp_op {
    struct ccp_cmd_queue *cmd_q;
    u32 jobid;
    void *sb_ctx;
    struct {
        struct {
            int type;
            int msg_bits;
        } sha;
    } u;
    int eom;
};

struct ccp_sha_engine {
    int type;
    size_t ctx_len;
    void *ctx;
    int final;
    size_t src_len;
    void *src;
    int msg_bits;
    int first;
    void *opad;
    size_t opad_len;
};

struct ccp_cmd {
    int engine;
    struct {
        struct ccp_sha_engine sha;
    } u;
    int engine_error;
};

struct ccp_vdata {
    unsigned int version;
    struct {
        int (*sha)(struct ccp_op *op);
    } *perform;
};

struct ccp_device {
    struct ccp_vdata *vdata;
};

struct ccp_cmd_queue {
    struct ccp_device *ccp;
    int cmd_error;
    void *sb_ctx;
};

extern const u8 sha1_zero_message_hash[SHA1_DIGEST_SIZE];
extern const u8 sha224_zero_message_hash[SHA224_DIGEST_SIZE];
extern const u8 sha256_zero_message_hash[SHA256_DIGEST_SIZE];
extern const u32 ccp_sha1_init[SHA1_DIGEST_SIZE / sizeof(u32)];
extern const u32 ccp_sha224_init[SHA256_DIGEST_SIZE / sizeof(u32)];
extern const u32 ccp_sha256_init[SHA256_DIGEST_SIZE / sizeof(u32)];
extern const u64 ccp_sha384_init[SHA512_DIGEST_SIZE / sizeof(u64)];
extern const u64 ccp_sha512_init[SHA512_DIGEST_SIZE / sizeof(u64)];

enum {
    CCP_SHA_TYPE_1 = 0,
    CCP_SHA_TYPE_224,
    CCP_SHA_TYPE_256,
    CCP_SHA_TYPE_384,
    CCP_SHA_TYPE_512,
};

static inline void scatterwalk_map_and_copy(void *buf, void *sg, unsigned int start, unsigned int nbytes, int out) {}
static inline void sg_init_one(struct scatterlist *sg, void *buf, unsigned int nbytes) {}

static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }

static inline int ccp_init_dm_workarea(struct ccp_dm_workarea *wa, struct ccp_cmd_queue *cmd_q, size_t size, int dir) { return 0; }
static inline int ccp_set_dm_area(struct ccp_dm_workarea *wa, unsigned int wa_offset, void *src, unsigned int src_offset, size_t len) { return 0; }
static inline int ccp_copy_to_sb(struct ccp_cmd_queue *cmd_q, struct ccp_dm_workarea *wa, u32 jobid, void *sb_ctx, int swap_type) { return 0; }
static inline int ccp_init_data(struct ccp_data *data, struct ccp_cmd_queue *cmd_q, void *src, size_t len, size_t block_size, int dir) { return 0; }
static inline void ccp_prepare_data(struct ccp_data *data, void *dst, struct ccp_op *op, size_t block_size, bool final) {}
static inline void ccp_process_data(struct ccp_data *data, void *dst, struct ccp_op *op) {}
static inline void ccp_free_data(struct ccp_data *data, struct ccp_cmd_queue *cmd_q) {}
static inline int ccp_copy_from_sb(struct ccp_cmd_queue *cmd_q, struct ccp_dm_workarea *wa, u32 jobid, void *sb_ctx, int swap_type) { return 0; }
static inline void ccp_get_dm_area(struct ccp_dm_workarea *wa, unsigned int wa_offset, void *dest, unsigned int dest_offset, size_t len) {}
static inline void ccp_dm_free(struct ccp_dm_workarea *wa) {}

#define noinline_for_stack