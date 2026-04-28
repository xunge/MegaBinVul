#include <stdint.h>
#include <string.h>
#include <assert.h>

typedef uint8_t u8;
typedef uint32_t u32;
typedef int32_t GF_Err;
typedef int32_t Bool;

#define GF_OK 0
#define GF_NON_COMPLIANT_BITSTREAM 1
#define GF_TRUE 1
#define GF_FALSE 0
#define GP_RTP_PCK_USE_MULTI 0x01
#define RTP_VVC_AGG_NAL 0
#define RTP_VVC_FRAG_NAL 0
#define GF_VVC_NALU_SLICE_GDR 0

typedef struct {
    u32 compositionTimeStamp;
    u8 accessUnitStartFlag;
} GP_SLHeader;

typedef struct {
    u8 PayloadType;
    u32 SequenceNumber;
    u32 TimeStamp;
    u8 Marker;
} GP_RTPHeader;

typedef struct {
    u32 bytesInPacket;
    u32 Path_MTU;
    u8 flags;
    u8 PayloadType;
    GP_SLHeader sl_header;
    GP_RTPHeader rtp_header;
    char hevc_payload_hdr[3];
    void *cbk_obj;
    void (*OnData)(void *, char *, u32, Bool);
    void (*OnDataReference)(void *, u32, u32);
    void (*OnNewPacket)(void *, GP_RTPHeader *);
    void (*OnPacketDone)(void *, GP_RTPHeader *);
} GP_RTPPacketizer;