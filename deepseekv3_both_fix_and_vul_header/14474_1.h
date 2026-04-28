#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint64_t u64;

#define GF_BITSTREAM_WRITE 0
#define GF_LOG_WARNING 1
#define GF_LOG_CONTAINER 2

typedef enum {
    GF_OK,
    GF_STREAM_AUDIO,
    GF_ISOM_SUBTYPE_3GP_EVRC,
    GF_ISOM_SUBTYPE_3GP_QCELP,
    GF_ISOM_SUBTYPE_3GP_SMV,
    GF_ISOM_SUBTYPE_3GP_AMR,
    GF_ISOM_SUBTYPE_3GP_AMR_WB,
    GF_CODECID_EVRC,
    GF_CODECID_QCELP,
    GF_CODECID_SMV,
    GF_CODECID_AMR,
    GF_CODECID_AMR_WB
} GF_Err;

typedef struct {
    u32 sampleDelta;
} GF_SttsEntry;

typedef struct {
    u32 dataLength;
    u8 *data;
} GF_DecoderSpecificInfo;

typedef struct {
    u16 streamType;
    u16 objectTypeIndication;
    GF_DecoderSpecificInfo *decoderSpecificInfo;
} GF_DecoderConfig;

typedef struct {
    GF_DecoderConfig *decoderConfig;
} GF_ESD;

typedef struct {
    u32 sampleSize;
} GF_SampleSizeBox;

typedef struct {
    u32 nb_entries;
    GF_SttsEntry *entries;
} GF_TimeToSampleBox;

typedef struct {
    u32 type;
    u32 samplerate_hi;
    u16 bitspersample;
} GF_GenericAudioSampleEntryBox;

typedef struct {
    GF_SampleSizeBox *SampleSize;
    GF_TimeToSampleBox *TimeToSample;
} GF_SampleTableBox;

typedef struct {
    u8 *buffer;
    u32 size;
    u32 position;
    u32 mode;
} GF_BitStream;

GF_ESD *gf_odf_desc_esd_new(int version);
GF_BitStream *gf_bs_new(const void *buffer, u64 size, u32 mode);
void gf_bs_write_data(GF_BitStream *bs, const char *data, u32 size);
void gf_bs_write_u32_le(GF_BitStream *bs, u32 value);
void gf_bs_write_u16_le(GF_BitStream *bs, u16 value);
void gf_bs_write_u8(GF_BitStream *bs, u8 value);
void gf_bs_write_u16(GF_BitStream *bs, u16 value);
void gf_bs_get_content(GF_BitStream *bs, u8 **data, u32 *dataLength);
void gf_bs_del(GF_BitStream *bs);
void GF_LOG(u32 level, u32 category, const char *fmt, ...);
char *gf_4cc_to_str(u32 type);