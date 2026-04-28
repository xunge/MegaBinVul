#include <stdint.h>

#define MAX_CHANNELS 64
#define MAX_SYNTAX_ELEMENTS 64

typedef struct bitfile bitfile;

typedef struct {
    int error;
} NeAACDecFrameInfo;

typedef struct {
    uint8_t sce_channel[MAX_CHANNELS];
} PCE;

typedef struct {
    uint8_t fr_channels;
    uint8_t fr_ch_ele;
    uint8_t element_id[MAX_SYNTAX_ELEMENTS];
    uint8_t element_output_channels[MAX_SYNTAX_ELEMENTS];
    uint8_t internal_channel[MAX_CHANNELS];
    int frame;
    int pce_set;
    PCE pce;
} NeAACDecStruct;

extern int single_lfe_channel_element(NeAACDecStruct *hDecoder, bitfile *ld, uint8_t channels, uint8_t *tag);