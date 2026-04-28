#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define CCP_SB_BYTES 32
#define CCP_AES_CTX_SB_COUNT 1
#define CCP_PASSTHRU_BYTESWAP_256BIT 0
#define AES_BLOCK_SIZE 16
#define AES_KEYSIZE_128 16
#define AES_KEYSIZE_192 24
#define AES_KEYSIZE_256 32
#define EINVAL 22
#define EBADMSG 74

#define CCP_AES_ACTION_ENCRYPT 0
#define CCP_AES_ACTION_DECRYPT 1
#define CCP_AES_MODE_GHASH 0
#define CCP_AES_MODE_GCTR 1
#define CCP_AES_GHASHAAD 0
#define CCP_AES_GHASHFINAL 1
#define CCP_MEMTYPE_SYSTEM 0

#define DMA_TO_DEVICE 1
#define DMA_FROM_DEVICE 2
#define DMA_BIDIRECTIONAL 3

typedef uint64_t __be64;

struct scatterlist {
    void *virt;
    unsigned int length;
};

struct ccp_cmd_queue;
struct ccp_cmd;
struct ccp_dm_workarea;
struct ccp_data;
struct ccp_op;
struct ccp_vdata;

struct ccp_aes_engine {
    unsigned int key_len;
    unsigned int iv_len;
    unsigned int authsize;
    unsigned int src_len;
    unsigned int aad_len;
    int action;
    int type;
    struct scatterlist *src;
    struct scatterlist *dst;
    struct scatterlist *key;
    struct scatterlist *iv;
};

struct ccp_cmd_queue {
    struct ccp_cmd *cmd;
    struct ccp_vdata *vdata;
    int cmd_error;
    int id;
    void *sb_key;
    void *sb_ctx;
    struct ccp_cmd_queue *ccp;
};

struct ccp_cmd {
    struct {
        struct ccp_aes_engine aes;
    } u;
    int engine_error;
};

struct ccp_dm_workarea {
    void *address;
    struct {
        uintptr_t address;
    } dma;
    size_t length;
    unsigned int bytes_left;
};

struct ccp_data {
    struct ccp_dm_workarea sg_wa;
};

struct ccp_op {
    struct ccp_cmd_queue *cmd_q;
    unsigned int jobid;
    void *sb_key;
    void *sb_ctx;
    int init;
    int eom;
    int soc;
    union {
        struct {
            int type;
            int mode;
            int action;
            unsigned int size;
        } aes;
    } u;
    struct {
        int type;
        union {
            struct {
                uintptr_t address;
                size_t length;
            } dma;
        } u;
    } src, dst;
};

struct ccp_vdata {
    struct {
        int (*aes)(struct ccp_op *op);
    } *perform;
};

#define CCP_NEW_JOBID(q) ((q)->id++)

static inline struct scatterlist *scatterwalk_ffwd(struct scatterlist dst[2],
                          struct scatterlist *src,
                          unsigned int len)
{
    return src;
}

static inline void *sg_virt(struct scatterlist *sg)
{
    return sg ? sg->virt : NULL;
}

static inline int ccp_init_dm_workarea(struct ccp_dm_workarea *wa,
                      struct ccp_cmd_queue *cmd_q,
                      size_t len,
                      int dir)
{
    wa->bytes_left = len;
    return 0;
}

static inline int ccp_set_dm_area(struct ccp_dm_workarea *wa,
                 unsigned int wa_offset,
                 struct scatterlist *sg,
                 unsigned int sg_offset,
                 unsigned int len)
{
    return 0;
}

static inline int ccp_copy_to_sb(struct ccp_cmd_queue *cmd_q,
                struct ccp_dm_workarea *wa,
                unsigned int jobid,
                void *sb,
                int passthru)
{
    return 0;
}

static inline int ccp_init_data(struct ccp_data *data,
                struct ccp_cmd_queue *cmd_q,
                struct scatterlist *sg,
                unsigned int len,
                unsigned int block_size,
                int dir)
{
    data->sg_wa.bytes_left = len;
    return 0;
}

static inline void ccp_prepare_data(struct ccp_data *src,
                   struct ccp_data *dst,
                   struct ccp_op *op,
                   unsigned int block_size,
                   bool last_block)
{
}

static inline void ccp_process_data(struct ccp_data *src,
                   struct ccp_data *dst,
                   struct ccp_op *op)
{
    src->sg_wa.bytes_left -= (src->sg_wa.bytes_left > AES_BLOCK_SIZE) ? 
                            AES_BLOCK_SIZE : src->sg_wa.bytes_left;
}

static inline int ccp_copy_from_sb(struct ccp_cmd_queue *cmd_q,
                  struct ccp_dm_workarea *wa,
                  unsigned int jobid,
                  void *sb,
                  int passthru)
{
    return 0;
}

static inline void ccp_get_dm_area(struct ccp_dm_workarea *wa,
                  unsigned int wa_offset,
                  struct scatterlist *sg,
                  unsigned int sg_offset,
                  unsigned int len)
{
}

static inline void ccp_dm_free(struct ccp_dm_workarea *wa)
{
}

static inline void ccp_free_data(struct ccp_data *data,
                struct ccp_cmd_queue *cmd_q)
{
}

static inline int crypto_memneq(const void *a, const void *b, size_t size)
{
    return memcmp(a, b, size) != 0;
}

#define noinline_for_stack
#define cpu_to_be64(x) __builtin_bswap64(x)