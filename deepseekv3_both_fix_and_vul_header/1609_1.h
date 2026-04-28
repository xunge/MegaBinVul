#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/queue.h>

typedef uint32_t TEE_Result;
typedef struct {
    uint8_t data[16];
} TEE_UUID;

struct tee_file_operations;

struct tee_pobj {
    TEE_UUID uuid;
    uint32_t flags;
    uint32_t obj_id_len;
    void *obj_id;
    bool temporary;
    uint32_t refcnt;
    const struct tee_file_operations *fops;
    TAILQ_ENTRY(tee_pobj) link;
};

TAILQ_HEAD(tee_pobj_head, tee_pobj);
extern struct tee_pobj_head tee_pobjs;

#define TEE_SUCCESS 0
#define TEE_ERROR_ACCESS_CONFLICT 1
#define TEE_ERROR_OUT_OF_MEMORY 2

#define TEE_Malloc(size, flags) calloc(1, size)
#define TEE_MALLOC_FILL_ZERO 0

TEE_Result tee_pobj_check_access(uint32_t obj_flags, uint32_t flags);