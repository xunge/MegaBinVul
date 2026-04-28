#include <stdint.h>
#include <stddef.h>

typedef int32_t GF_Err;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;
typedef int Bool;

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_IPMPX_Data GF_IPMPX_Data;
typedef struct GF_IPMPX_WatermarkingInit GF_IPMPX_WatermarkingInit;

struct GF_IPMPX_WatermarkingInit {
    u8 inputFormat;
    u8 requiredOp;
    u8 nChannels;
    u8 bitPerSample;
    u32 frequency;
    u16 frame_horizontal_size;
    u16 frame_vertical_size;
    u8 chroma_format;
    u16 wmPayloadLen;
    char* wmPayload;
    u16 wmRecipientId;
    u16 opaqueDataSize;
    char* opaqueData;
    u32 tag;
};

#define GF_OK 0
#define GF_IPMPX_AUDIO_WM_INIT_TAG 0
#define GF_IPMPX_WM_INSERT 1
#define GF_IPMPX_WM_REMARK 2
#define GF_IPMPX_WM_EXTRACT 3
#define GF_IPMPX_WM_DETECT_COMPRESSION 4

extern int gf_bs_read_int(GF_BitStream *bs, int bits);
extern void gf_bs_read_data(GF_BitStream *bs, char *data, u32 size);
extern void* gf_malloc(size_t size);