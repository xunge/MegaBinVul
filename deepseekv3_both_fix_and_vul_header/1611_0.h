#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef uint32_t TEE_Result;

typedef struct {
    uint8_t data[16];
} TEE_UUID;

struct tee_ta_session {
    void *ctx;
};

struct user_ta_ctx {
    struct {
        uint32_t flags;
        TEE_UUID uuid;
        void *ops;
    } ctx;
    void *user_ta;
    void *open_sessions;
    void *cryp_states;
    void *objects;
};

struct user_ta_head {
    TEE_UUID uuid;
    uint32_t flags;
    char *name;
};

extern struct user_ta_head __start_user_ta_head_section;
extern struct user_ta_head __stop_user_ta_head_section;
extern void *tee_ctxes;
extern void *user_ta_ops;

#define DMSG(...) 
#define TAILQ_INIT(head) 
#define TAILQ_INSERT_TAIL(head, elm, field) 
#define TEE_Malloc(size, flags) calloc(1, size)
#define TEE_MALLOC_FILL_ZERO 0
#define TEE_ERROR_ITEM_NOT_FOUND 0xFFFF0000
#define TEE_ERROR_OUT_OF_MEMORY 0xFFFF0001
#define TEE_SUCCESS 0