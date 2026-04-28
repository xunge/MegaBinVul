#include <stdint.h>
#include <assert.h>

typedef uint8_t u8;
typedef uint32_t u32;
typedef int32_t GF_Err;
typedef enum { GF_FALSE, GF_TRUE } Bool;

#define GF_OK 0
#define GF_NON_COMPLIANT_BITSTREAM 1

#define GF_AVC_NALU_NON_IDR_SLICE 1
#define GF_AVC_NALU_ACCESS_UNIT 2
#define GF_AVC_NALU_END_OF_SEQ 10
#define GF_AVC_NALU_END_OF_STREAM 11
#define GF_AVC_NALU_FILLER_DATA 12

#define GP_RTP_PCK_USE_MULTI 1

typedef struct {
    u32 compositionTimeStamp;
    u8 accessUnitStartFlag;
} GP_SLHeader;

typedef struct {
    u8 PayloadType;
    u32 Marker;
    u32 TimeStamp;
    u32 SequenceNumber;
} GP_RTPHeader;

typedef struct {
    u32 bytesInPacket;
    u32 Path_MTU;
    u32 flags;
    u8 PayloadType;
    Bool avc_non_idr;
    GP_SLHeader sl_header;
    GP_RTPHeader rtp_header;
    void* cbk_obj;
    void (*OnPacketDone)(void*, GP_RTPHeader*);
    void (*OnNewPacket)(void*, GP_RTPHeader*);
    void (*OnData)(void*, char*, u32, Bool);
    void (*OnDataReference)(void*, u32, u32);
} GP_RTPPacketizer;