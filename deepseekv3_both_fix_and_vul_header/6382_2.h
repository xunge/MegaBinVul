#include <stdint.h>
#include <stdlib.h>

#define ALIGN
#define LTP_DEC
#define DRM
#define SBR_DEC
#define PS_DEC
#define DRM_PS
#define ID_CPE 1
#define ID_SCE 2
#define DRM_ER_LC 1

typedef struct bitfile {
    uint8_t *buffer;
    uint32_t buf_size;
    uint32_t buf_byte_idx;
    uint8_t buf_bit_idx;
    uint32_t bytes_processed;
    uint8_t error;
} bitfile;

typedef struct tns_info {
    uint8_t data_present;
} tns_info;

typedef struct ic_stream {
    uint8_t tns_data_present;
    tns_info tns;
    tns_info ltp;
} ic_stream;

typedef struct element {
    uint8_t common_window;
    uint8_t channel;
    uint8_t paired_channel;
    ic_stream ics1;
    ic_stream ics2;
} element;

typedef struct NeAACDecFrameInfo {
    uint8_t error;
} NeAACDecFrameInfo;

typedef struct sbr_info {
    uint32_t sample_rate;
    uint8_t ret;
    uint8_t ps_used;
    uint8_t header_count;
} sbr_info;

typedef struct NeAACDecStruct {
    uint8_t fr_channels;
    uint8_t channelConfiguration;
    uint8_t fr_ch_ele;
    uint8_t element_id[1];
    uint8_t element_output_channels[1];
    uint8_t internal_channel[2];
    uint8_t object_type;
    uint8_t sbr_present_flag;
    sbr_info *sbr[1];
    uint16_t frameLength;
    uint8_t sf_index;
    uint8_t postSeekResetFlag;
    uint8_t ps_used[1];
    uint8_t ps_used_global;
} NeAACDecStruct;

typedef struct program_config program_config;
typedef struct drc_info drc_info;

uint8_t faad_get1bit(bitfile *ld);
uint32_t faad_get_processed_bits(bitfile *ld);
uint8_t* faad_origbitbuffer(bitfile *ld);
uint32_t faad_origbitbuffer_size(bitfile *ld);
void faad_initbits(bitfile *ld, uint8_t *buffer, uint16_t len);
uint32_t faad_getbits(bitfile *ld, uint8_t n);
void faad_endbits(bitfile *ld);
uint8_t faad_check_CRC(bitfile *ld, uint16_t len);
uint8_t tabFlipbits[256];
uint16_t bit2byte(uint32_t bits);

uint8_t DRM_aac_scalable_main_header(NeAACDecStruct *hDecoder, ic_stream *ics1, ic_stream *ics2, bitfile *ld, uint8_t this_layer_stereo);
uint8_t side_info(NeAACDecStruct *hDecoder, element *cpe, bitfile *ld, ic_stream *ics, uint8_t flag);
void tns_data(ic_stream *ics, tns_info *tns, bitfile *ld);
uint8_t reordered_spectral_data(NeAACDecStruct *hDecoder, ic_stream *ics, bitfile *ld, int16_t *spec_data);
uint8_t reconstruct_channel_pair(NeAACDecStruct *hDecoder, ic_stream *ics1, ic_stream *ics2, element *cpe, int16_t *spec_data1, int16_t *spec_data2);
uint8_t reconstruct_single_channel(NeAACDecStruct *hDecoder, ic_stream *ics, element *cpe, int16_t *spec_data);

uint32_t get_sample_rate(uint8_t sf_index);
void* faad_malloc(uint32_t size);
void faad_free(void *ptr);

sbr_info* sbrDecodeInit(uint16_t frameLength, uint8_t id, uint32_t sample_rate, uint8_t downSampledSBR, uint8_t drm);
uint8_t sbr_extension_data(bitfile *ld, sbr_info *sbr, uint16_t count, uint8_t postSeekResetFlag);