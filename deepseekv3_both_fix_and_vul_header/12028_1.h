#include <stdint.h>

typedef int32_t GF_Err;
#define GF_OK 0
#define GF_ISOM_INVALID_FILE 1

typedef uint32_t u32;

typedef struct {
    uint8_t position;
    int16_t azimuth;
    int8_t elevation;
} GF_ChannelLayout;

typedef struct {
    uint8_t stream_structure;
    uint8_t format_ordering;
    uint8_t base_channel_count;
    uint8_t definedLayout;
    uint8_t channels_count;
    GF_ChannelLayout layouts[64];
    uint64_t omittedChannelsMap;
    uint8_t omitted_channels_present;
    uint8_t channel_order_definition;
    uint8_t object_count;
} GF_ChannelLayoutInfo;

typedef struct {
    uint8_t version;
    GF_ChannelLayoutInfo layout;
    u32 size;
} GF_ChannelLayoutBox;

typedef struct GF_Box GF_Box;
typedef struct GF_BitStream GF_BitStream;

#define ISOM_DECREASE_SIZE(s, n)

uint8_t gf_bs_read_u8(GF_BitStream *bs);
int gf_bs_read_int(GF_BitStream *bs, int bits);
uint64_t gf_bs_read_u64(GF_BitStream *bs);