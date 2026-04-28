#include <stdint.h>

typedef int32_t GF_Err;
#define GF_OK 0

typedef uint32_t u32;

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_Box GF_Box;

typedef struct {
    uint8_t position;
    int16_t azimuth;
    int8_t elevation;
} GF_ChannelLayout;

typedef struct {
    uint8_t stream_structure;
    uint8_t definedLayout;
    u32 channels_count;
    GF_ChannelLayout *layouts;
    uint8_t format_ordering;
    uint8_t base_channel_count;
    uint8_t channel_order_definition;
    uint8_t omitted_channels_present;
    uint64_t omittedChannelsMap;
    uint8_t object_count;
} GF_ChannelLayoutInfo;

typedef struct GF_ChannelLayoutBox {
    GF_Box *s;
    uint8_t version;
    GF_ChannelLayoutInfo layout;
} GF_ChannelLayoutBox;

GF_Err gf_isom_full_box_write(GF_Box *s, GF_BitStream *bs);
void gf_bs_write_u8(GF_BitStream *bs, uint8_t val);
void gf_bs_write_int(GF_BitStream *bs, int32_t val, int32_t nBits);
void gf_bs_write_u64(GF_BitStream *bs, uint64_t val);