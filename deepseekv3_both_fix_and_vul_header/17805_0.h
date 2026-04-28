#include <stddef.h>
#include <stdint.h>

typedef struct rdpContext rdpContext;
typedef struct wStream wStream;

typedef struct
{
    uint8_t controlFlags;
    uint8_t orderType;
    uint32_t fieldFlags;
} ORDER_INFO;

#define WINPR_UNUSED(x) (void)(x)
#define ORDER_TYPE_CHANGE (1 << 0)

extern const uint8_t PRIMARY_DRAWING_ORDER_FIELD_BYTES[];

void Stream_Write_UINT8(wStream* s, uint8_t value);
size_t Stream_GetPosition(wStream* s);
void Stream_SetPosition(wStream* s, size_t position);
void update_write_field_flags(wStream* s, uint32_t fieldFlags, uint8_t controlFlags, uint8_t bytes);
void update_write_bounds(wStream* s, ORDER_INFO* orderInfo);