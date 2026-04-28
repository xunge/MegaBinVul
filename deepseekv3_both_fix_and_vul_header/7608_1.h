#include <stdint.h>
#include <string.h>
#include <assert.h>

typedef uint8_t u8;
typedef uint32_t u32;
typedef int32_t Bool;
typedef int32_t GF_Err;

#define GF_OK 0
#define GF_NON_COMPLIANT_BITSTREAM 1
#define GF_TRUE 1
#define GF_FALSE 0

typedef struct {
    u32 compositionTimeStamp;
    u8 accessUnitStartFlag;
} GP_SLHeader;

typedef struct {
    u8 PayloadType;
    u32 TimeStamp;
    u32 SequenceNumber;
    u8 Marker;
} GP_RTPHeader;

typedef struct {
    GP_RTPHeader rtp_header;
    GP_SLHeader sl_header;
    u32 bytesInPacket;
    u32 Path_MTU;
    u32 flags;
    u8 PayloadType;
    u8 hevc_payload_hdr[2];
    void* cbk_obj;
    void (*OnData)(void*, char*, u32, Bool);
    void (*OnDataReference)(void*, u32, u32);
    void (*OnNewPacket)(void*, GP_RTPHeader*);
    void (*OnPacketDone)(void*, GP_RTPHeader*);
} GP_RTPPacketizer;

#define GP_RTP_PCK_USE_MULTI (1 << 0)