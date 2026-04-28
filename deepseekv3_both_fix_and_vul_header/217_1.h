#include <stdint.h>

typedef int32_t GF_Err;
#define GF_OK 0
#define GF_CORRUPTED_DATA -1

typedef uint32_t u32;
typedef uint8_t u8;

typedef struct {
    uint8_t *data;
    uint32_t position;
    uint32_t size;
} GF_BitStream;

typedef struct {
    int type;
} GF_IPMPX_Data;

typedef struct {
    GF_IPMPX_Data base;
    u8 eventTypeCount;
    u8 eventType[256];
} GF_IPMPX_RemoveToolNotificationListener;

#define ARRAY_LENGTH(a) (sizeof(a)/sizeof(a[0]))

static u32 gf_bs_read_int(GF_BitStream *bs, u8 numBits);