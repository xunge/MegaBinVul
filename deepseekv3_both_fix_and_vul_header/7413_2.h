#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char Bool;
#define GF_FALSE 0
#define GF_TRUE 1

typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed int s32;
typedef signed short s16;

typedef enum {
    GF_OK = 0,
    GF_BAD_PARAM,
    GF_IO_ERR,
} GF_Err;

typedef enum {
    GF_LOG_ERROR,
} GF_LogLevel;

typedef enum {
    GF_LOG_MEDIA,
} GF_LogTool;

typedef enum {
    GF_ISOM_MEDIA_TEXT,
    GF_ISOM_MEDIA_MPEG_SUBT,
    GF_ISOM_MEDIA_SUBT,
    GF_ISOM_MEDIA_AUDIO,
} GF_ISOM_MediaType;

typedef enum {
    GF_ISOM_SUBTYPE_WVTT,
    GF_ISOM_SUBTYPE_STXT,
    GF_ISOM_SUBTYPE_STPP,
} GF_ISOM_SubType;

typedef enum {
    RAP,
    RAP_REDUNDANT,
} GF_ISOM_RAPType;

typedef struct GF_Descriptor GF_Descriptor;

typedef struct {
    u32 trackID;
    void *file;
    char *out_name;
    u32 flags;
} GF_MediaExporter;

typedef struct GF_DecoderConfig {
    u32 streamType;
    u32 objectTypeIndication;
    struct GF_DecoderSpecificInfo *decoderSpecificInfo;
} GF_DecoderConfig;

typedef struct GF_DecoderSpecificInfo {
    char *data;
    u32 dataLength;
} GF_DecoderSpecificInfo;

typedef struct GF_ESD {
    GF_DecoderConfig *decoderConfig;
} GF_ESD;

typedef struct {
    char *data;
    u32 dataLength;
    u64 DTS;
    u64 CTS_Offset;
    u32 IsRAP;
} GF_ISOSample;

typedef struct {
    u32 version;
    u32 revision;
    u32 vendor_code;
    u32 width;
    u32 height;
    u32 h_res;
    u32 v_res;
    u32 depth;
    u32 samplerate;
    u32 nb_channels;
    u32 bits_per_sample;
    u32 temporal_quality;
    u32 spatial_quality;
    char *compressor_name;
    char *extension_buf;
    u32 extension_buf_size;
} GF_GenericSampleDescription;

typedef struct {
    u64 value;
} GF_WebVTTTimestamp;

#define GF_EXPORT_PROBE_ONLY (1<<0)
#define GF_EXPORT_WEBVTT_META_EMBEDDED (1<<1)
#define GF_EXPORT_DO_ABORT (1<<2)

#define LLD "%lld"

int gf_fprintf(FILE *stream, const char *format, ...);
size_t gf_fwrite(const void *ptr, size_t size, FILE *stream);
FILE *gf_fopen(const char *filename, const char *mode);
int gf_fclose(FILE *stream);
void gf_free(void *ptr);
void *gf_malloc(size_t size);
void *gf_realloc(void *ptr, size_t size);
void gf_odf_desc_del(GF_Descriptor *desc);