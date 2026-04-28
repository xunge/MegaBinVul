#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef uint32_t TEE_Result;
typedef struct {
    uint32_t timeLow;
    uint16_t timeMid;
    uint16_t timeHiAndVersion;
    uint8_t clockSeqAndNode[8];
} TEE_UUID;

struct tee_ta_session {
    struct tee_ta_ctx *ctx;
};

struct tee_ta_ctx {
    TEE_UUID uuid;
    uint32_t flags;
    const void *ops;
    struct {
        struct tee_ta_ctx *tqe_next;
        struct tee_ta_ctx **tqe_prev;
    } link;
};

struct pseudo_ta_head {
    TEE_UUID uuid;
    const char *name;
    uint32_t flags;
};

struct pseudo_ta_ctx {
    struct tee_ta_ctx ctx;
    const struct pseudo_ta_head *pseudo_ta;
};

extern const struct pseudo_ta_head __start_ta_head_section;
extern const struct pseudo_ta_head __stop_ta_head_section;
extern struct {
    struct tee_ta_ctx *tqh_first;
    struct tee_ta_ctx **tqh_last;
} tee_ctxes;
extern const void *pseudo_ta_ops;

#define TAILQ_INSERT_TAIL(head, elm, field) do { \
    (elm)->field.tqe_next = NULL; \
    (elm)->field.tqe_prev = (head)->tqh_last; \
    *(head)->tqh_last = (elm); \
    (head)->tqh_last = &(elm)->field.tqe_next; \
} while (0)

#define DMSG(fmt, ...) printf(fmt, ##__VA_ARGS__)

#define TEE_Malloc(size, flags) calloc(1, size)
#define TEE_MALLOC_FILL_ZERO 0

#define TEE_SUCCESS 0
#define TEE_ERROR_ITEM_NOT_FOUND 0xFFFF0006
#define TEE_ERROR_OUT_OF_MEMORY 0xFFFF000C