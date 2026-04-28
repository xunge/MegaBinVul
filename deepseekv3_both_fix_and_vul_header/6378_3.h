#include <stdint.h>

typedef struct bitfile bitfile;
typedef struct program_config program_config;
typedef struct drc_info drc_info;

typedef struct NeAACDecStruct {
    int fr_channels;
    int fr_ch_ele;
    int first_syn_ele;
    int has_lfe;
    int object_type;
    int channelConfiguration;
} NeAACDecStruct;

typedef struct NeAACDecFrameInfo {
    int error;
} NeAACDecFrameInfo;

#define ERROR_RESILIENCE 0
#define DRM 0
#define COUPLING_DEC 0
#define SBR_DEC 0
#define ER_OBJECT_START 0
#define DRM_ER_LC 0

#define LEN_SE_ID 3
#define ID_END 0
#define ID_SCE 1
#define ID_CPE 2
#define ID_LFE 3
#define ID_CCE 4
#define ID_DSE 5
#define ID_PCE 6
#define ID_FIL 7
#define INVALID_SBR_ELEMENT 0

#define DEBUGVAR(a,b,c)  // Remove debug macro since it's not standard

uint32_t faad_getbits(bitfile *ld, int len);
void decode_sce_lfe(NeAACDecStruct *hDecoder, NeAACDecFrameInfo *hInfo, bitfile *ld, uint8_t id_syn_ele);
void decode_cpe(NeAACDecStruct *hDecoder, NeAACDecFrameInfo *hInfo, bitfile *ld, uint8_t id_syn_ele);
void data_stream_element(NeAACDecStruct *hDecoder, bitfile *ld);
void program_config_element(program_config *pce, bitfile *ld);
int fill_element(NeAACDecStruct *hDecoder, bitfile *ld, drc_info *drc, int sbr_element);
void faad_byte_align(bitfile *ld);
int coupling_channel_element(NeAACDecStruct *hDecoder, bitfile *ld);