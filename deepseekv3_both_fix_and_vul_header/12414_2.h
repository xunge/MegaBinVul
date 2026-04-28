#include <stdint.h>
#include <stddef.h>

#define GF_EXPORT
typedef int32_t GF_Err;
#define GF_OK 0

typedef uint32_t u32;
typedef uint64_t u64;
typedef uint8_t u8;

#define GF_LOG_ERROR 1
#define GF_LOG_WARNING 2
#define GF_LOG_RTP 3
#define GF_RTP_TX3G_SIDX_OFFSET 0

#define GF_LOG(level, module, ...) 

typedef struct {
    int num;
    int den;
} GF_Fraction;

typedef struct {
    uint32_t timestampResolution;
    uint8_t usePaddingFlag;
} GF_SLConfig;

typedef struct {
    uint64_t compositionTimeStamp;
    uint64_t decodingTimeStamp;
    uint8_t randomAccessPointFlag;
    uint8_t paddingBits;
    uint8_t accessUnitStartFlag;
    uint8_t accessUnitEndFlag;
    uint16_t AU_sequenceNumber;
    uint16_t packetSequenceNumber;
} GF_SLHeader;

typedef struct {
    uint8_t IV_length;
} GF_SLMap;

typedef struct {
    uint8_t *data;
    uint32_t dataLength;
    uint64_t DTS;
    uint64_t CTS_Offset;
    uint8_t IsRAP;
    #define RAP 1
    #define RAP_REDUNDANT 2
} GF_ISOSample;

typedef struct {
    uint8_t *data;
    uint32_t dataLength;
    uint8_t *IV;
    char *key_indicator;
    uint8_t IV_length;
    uint8_t KI_length;
    uint8_t flags;
    #define GF_ISOM_ISMA_USE_SEL_ENC 1
    #define GF_ISOM_ISMA_IS_ENCRYPTED 2
} GF_ISMASample;

typedef struct {
    GF_SLConfig sl_config;
    GF_SLHeader sl_header;
    GF_SLMap slMap;
} GF_RTPPacketizer;

typedef struct {
    void *file;
    uint32_t TrackNum;
    uint32_t HintTrack;
    uint32_t TotalSample;
    uint32_t CurrentSample;
    uint32_t HintSample;
    uint32_t RTPTime;
    uint32_t OrigTimeScale;
    uint32_t base_offset_in_sample;
    uint8_t SampleIsRAP;
    uint8_t avc_nalu_size;
    GF_RTPPacketizer *rtp_p;
} GF_RTPHinter;

GF_Err gf_isom_last_error(void *file);
uint32_t gf_isom_get_sample_count(void *file, uint32_t TrackNum);
GF_ISOSample *gf_isom_get_sample(void *file, uint32_t TrackNum, uint32_t sample_num, uint32_t *descIndex);
GF_ISMASample *gf_isom_get_ismacryp_sample(void *file, uint32_t TrackNum, GF_ISOSample *samp, uint32_t descIndex);
void gf_isom_ismacryp_delete_sample(GF_ISMASample *s);
void gf_free(void *ptr);
uint32_t gf_isom_get_sample_duration(void *file, uint32_t TrackNum, uint32_t sample_num);
void gf_isom_get_sample_padding_bits(void *file, uint32_t TrackNum, uint32_t sample_num, uint8_t *PadBits);
GF_Err gf_rtp_builder_process(GF_RTPPacketizer *rtp_p, void *data, uint32_t size, uint8_t last, uint32_t sampleLength, uint32_t duration, uint8_t descIndex);
void gf_rtp_builder_set_cryp_info(GF_RTPPacketizer *rtp_p, uint8_t *IV, char *key_indicator, uint8_t encrypted);
void gf_set_progress(const char *msg, uint32_t current, uint32_t total);
void gf_isom_sample_del(GF_ISOSample **samp);
GF_Err gf_isom_end_hint_sample(void *file, uint32_t HintTrack, uint8_t SampleIsRAP);