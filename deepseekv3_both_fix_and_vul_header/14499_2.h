#include <stdint.h>
#include <stddef.h>

#define GF_BITSTREAM_WRITE 0

typedef uint32_t u32;
typedef uint8_t u8;

typedef struct {
    u32 layer_id_plus_one;
    u32 min_temporal_id;
    u32 max_temporal_id;
} GF_NALULayerInfo;

typedef struct {
    GF_NALULayerInfo linf[64];
    void *opid;
} GF_NALUDmxCtx;

typedef struct {
    void *data;
    u32 size;
} GF_BitStream;

typedef struct {
    u8 *data;
    u32 size;
} PROP_DATA_NO_COPY;

#define PROP_DATA_NO_COPY(d, s) (PROP_DATA_NO_COPY){.data=(d), .size=(s)}

GF_BitStream *gf_bs_new(void *data, u32 size, u32 mode);
void gf_bs_write_int(GF_BitStream *bs, u32 value, u32 bits);
void gf_bs_get_content(GF_BitStream *bs, u8 **data, u32 *data_size);
void gf_bs_del(GF_BitStream *bs);
void gf_filter_pid_set_info_str(void *opid, const char *info, PROP_DATA_NO_COPY *data);