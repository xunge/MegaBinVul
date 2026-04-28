#include <string.h>
#include <errno.h>

#define UEV_MAX_EVENTS 1024

typedef struct uev_ctx_s {
    int maxevents;
} uev_ctx_t;

int _init(uev_ctx_t *ctx, int flags);