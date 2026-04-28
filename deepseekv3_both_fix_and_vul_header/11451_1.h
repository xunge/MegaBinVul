#include <stddef.h>
#include <string.h>

typedef unsigned char u8;

typedef struct sc_card_t {
    void *drv_data;
    struct sc_context_t *ctx;
} sc_card_t;

typedef struct sc_context_t sc_context_t;

typedef struct mscfs_t {
    struct {
        size_t size;
        struct {
            struct {
                u8 id[4];
            } objectId;
        } *array;
    } cache;
    u8 currentPath[2];
} mscfs_t;

typedef struct muscle_private_t {
    mscfs_t *fs;
} muscle_private_t;

#define MUSCLE_DATA(card) ((muscle_private_t*)(card)->drv_data)
#define SC_LOG_DEBUG_NORMAL 0

void sc_debug(sc_context_t *ctx, int level, const char *fmt, ...);
void mscfs_check_cache(mscfs_t *fs);