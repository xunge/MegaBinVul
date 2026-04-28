#include <stdint.h>
#include <stddef.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int32_t GF_Err;
typedef int Bool;

#define GF_OK 0
#define GF_NON_COMPLIANT_BITSTREAM 1
#define GF_FALSE 0
#define GF_TRUE 1
#define GF_RTP_TX3G_SIDX_OFFSET 0
#define GF_BITSTREAM_WRITE 1

typedef struct {
    u32 compositionTimeStamp;
} GF_SLHeader;

typedef struct {
    u32 TimeStamp;
    u32 SequenceNumber;
    u8 Marker;
} GF_RTPHeader;

typedef struct {
    u32 bytesInPacket;
    u32 Path_MTU;
    u32 flags;
    GF_SLHeader sl_header;
    GF_RTPHeader rtp_header;
    void* cbk_obj;
    void (*OnPacketDone)(void*, GF_RTPHeader*);
    void (*OnNewPacket)(void*, GF_RTPHeader*);
    void (*OnData)(void*, char*, u32, Bool);
    void (*OnDataReference)(void*, u32, u32);
} GP_RTPPacketizer;

typedef struct GF_BitStream GF_BitStream;

GF_BitStream* gf_bs_new(void*, u32, u32);
void gf_bs_write_int(GF_BitStream*, u32, u32);
void gf_bs_write_u16(GF_BitStream*, u16);
void gf_bs_write_u8(GF_BitStream*, u8);
void gf_bs_write_u24(GF_BitStream*, u32);
void gf_bs_get_content(GF_BitStream*, u8**, u32*);
void gf_bs_del(GF_BitStream*);
void gf_free(void*);

#define GP_RTP_PCK_USE_MULTI 0