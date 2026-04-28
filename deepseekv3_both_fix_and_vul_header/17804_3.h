#include <stdint.h>
#include <stddef.h>

typedef uint32_t UINT32;

typedef struct rdpContext rdpContext;

typedef struct {
    UINT32 fieldFlags;
    UINT32 orderType;
    UINT32 controlFlags;
} ORDER_INFO;

#define ORDER_STANDARD 0
#define ORDER_TYPE_CHANGE 0

extern const UINT32 PRIMARY_DRAWING_ORDER_FIELD_BYTES[];
extern int get_primary_drawing_order_field_bytes(UINT32 orderType, void* unused);
extern int update_prepare_bounds(rdpContext* context, ORDER_INFO* orderInfo);