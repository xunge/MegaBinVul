#include <stdlib.h>
#include <string.h>

typedef unsigned char Bool;
#define GF_FALSE 0
#define GF_TRUE 1

typedef struct {
    unsigned int bufferSizeDB;
    unsigned int avgBitrate;
    unsigned int maxBitrate;
} GF_BitRateBox;

typedef struct {
    void *data;
    unsigned int dataLength;
} GF_DecoderSpecificInfo;

typedef struct {
    GF_DecoderSpecificInfo *decoderSpecificInfo;
    unsigned int bufferSizeDB;
    unsigned int avgBitrate;
    unsigned int maxBitrate;
    unsigned int streamType;
    unsigned int objectTypeIndication;
} GF_DecoderConfig;

typedef struct {
    GF_DecoderConfig *decoderConfig;
} GF_ESD;

typedef struct {
    void *config;
} GF_AV1ConfigBox;

typedef struct {
    GF_ESD *emul_esd;
    GF_AV1ConfigBox *av1_config;
} GF_MPEGVisualSampleEntryBox;

typedef struct {
} GF_MediaBox;

typedef struct {
} GF_SampleEntryBox;

typedef struct {
} GF_Descriptor;

typedef struct {
} GF_AV1Config;

#define GF_STREAM_VISUAL 0
#define GF_CODECID_AV1 0

GF_BitRateBox *gf_isom_sample_entry_get_bitrate(GF_SampleEntryBox *entry, Bool is_video);
void gf_odf_desc_del(GF_Descriptor *desc);
GF_ESD *gf_odf_desc_esd_new(int version);
GF_AV1Config *AV1_DuplicateConfig(void *config);
void gf_odf_av1_cfg_write(GF_AV1Config *cfg, void **data, unsigned int *dataLength);
void gf_odf_av1_cfg_del(GF_AV1Config *cfg);