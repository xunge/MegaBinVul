#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef int32_t GF_Err;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int Bool;

typedef struct GF_BitStream GF_BitStream;

typedef struct GF_Box {
    u32 size;
} GF_Box;

typedef struct GF_GenericDTE {
    u8 type;
} GF_GenericDTE;

typedef struct GF_ImmediateDTE {
    u8 type;
    u32 dataLength;
} GF_ImmediateDTE;

typedef struct GF_SampleDTE {
    u8 type;
    u32 dataLength;
} GF_SampleDTE;

typedef struct GF_StreamDescDTE {
    u8 type;
    u32 dataLength;
} GF_StreamDescDTE;

typedef struct GF_RTPPacket {
    uint32_t relativeTransTime;
    uint8_t P_bit;
    uint8_t X_bit;
    uint8_t M_bit;
    uint8_t payloadType;
    uint16_t SequenceNumber;
    uint8_t B_bit;
    uint8_t R_bit;
    void *TLV;
    void *DataTable;
    uint32_t sampleNumber;
    uint32_t trackID;
} GF_RTPPacket;

#define GF_OK 0
#define GF_ISOM_INVALID_FILE 1
#define GF_LOG_ERROR 1
#define GF_LOG_CONTAINER 2

uint32_t gf_bs_read_u32(GF_BitStream *bs);
uint16_t gf_bs_read_u16(GF_BitStream *bs);
uint8_t gf_bs_read_u8(GF_BitStream *bs);
int gf_bs_read_int(GF_BitStream *bs, int bits);
GF_Err gf_isom_box_parse(GF_Box **box, GF_BitStream *bs);
void gf_list_add(void *list, void *item);
GF_GenericDTE* NewDTE(uint8_t type);
GF_Err ReadDTE(GF_GenericDTE *dte, GF_BitStream *bs);
void DelDTE(GF_GenericDTE *dte);
void GF_LOG(int level, int category, const char *format, ...);