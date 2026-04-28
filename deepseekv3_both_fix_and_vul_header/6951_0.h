#include <stddef.h>
#include <string.h>

typedef unsigned char Bool;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long long s64;

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_ISOSample {
    u32 dataLength;
    u64 DTS;
} GF_ISOSample;
typedef struct GF_ESD {
    struct {
        u32 avgBitrate;
        u32 maxBitrate;
        u32 bufferSizeDB;
    } *decoderConfig;
} GF_ESD;
typedef struct GF_Descriptor GF_Descriptor;

#define GPAC_DISABLE_ISOM_WRITE
#define GF_ISOM_MEDIA_AUDIO 0

u32 gf_isom_get_media_type(GF_ISOFile *file, u32 track);
u32 gf_isom_get_constant_sample_size(GF_ISOFile *file, u32 track);
u32 gf_isom_get_constant_sample_duration(GF_ISOFile *file, u32 track);
u32 gf_isom_get_media_timescale(GF_ISOFile *file, u32 track);
u32 gf_isom_get_sample_count(GF_ISOFile *file, u32 track);
GF_ISOSample *gf_isom_get_sample_info_ex(GF_ISOFile *file, u32 track, u32 sample_num, u32 *di, void *unused, GF_ISOSample *sample);
u64 gf_isom_get_media_duration(GF_ISOFile *file, u32 track);
GF_ESD *gf_isom_get_esd(GF_ISOFile *file, u32 track, u32 stream_desc_index);
void gf_isom_change_mpeg4_description(GF_ISOFile *file, u32 track, u32 desc_index, GF_ESD *esd);
void gf_isom_update_bitrate(GF_ISOFile *file, u32 track, u32 desc_index, u32 avg_bitrate, u32 max_bitrate, u32 buffer_size);
void gf_odf_desc_del(GF_Descriptor *desc);