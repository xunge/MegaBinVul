#include <stdint.h>

typedef uint8_t u8;
typedef uint32_t u32;
typedef int32_t GF_Err;
typedef int Bool;

#define GF_OK 0
#define GF_NON_COMPLIANT_BITSTREAM 1
#define GF_FALSE 0
#define GF_TRUE 1

#define MPEG12_SEQUENCE_START_CODE 0x000001B3
#define MPEG12_PICTURE_START_CODE 0x00000100

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    u32 compositionTimeStamp;
} GP_SLHeader;

typedef struct {
    u32 TimeStamp;
    u32 SequenceNumber;
    u8 Marker;
} GP_RTPHeader;

typedef struct {
    u32 Path_MTU;
    GP_RTPHeader rtp_header;
    GP_SLHeader sl_header;
    void *cbk_obj;
    void (*OnNewPacket)(void *, GP_RTPHeader *);
    void (*OnData)(void *, u8 *, u32, Bool);
    void (*OnDataReference)(void *, u32, u32);
    void (*OnPacketDone)(void *, GP_RTPHeader *);
} GP_RTPPacketizer;

int gf_mv12_next_start_code(unsigned char *data, u32 data_size, u32 *offset, u32 *startcode);
int gf_mv12_next_slice_start(unsigned char *data, u32 offset, u32 data_size, u32 *next_slice);