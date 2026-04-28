#include <stdint.h>

typedef struct bitfile {
    // Placeholder for bitfile structure
} bitfile;

typedef struct sbr_info {
    uint8_t psResetFlag;
    uint8_t Is_DRM_SBR;
    uint16_t bs_sbr_crc_bits;
    uint8_t bs_start_freq;
    uint8_t bs_samplerate_mode;
    uint8_t bs_stop_freq;
    uint8_t bs_freq_scale;
    uint8_t bs_alter_scale;
    uint8_t bs_xover_band;
    uint8_t bs_header_flag;
    uint8_t Reset;
    uint8_t just_seeked;
    uint8_t header_count;
    uint8_t ps_used;
} sbr_info;

#define EXT_SBR_DATA_CRC 0
#define PS_DEC
#define DRM
#define DRM_PS
#define DEBUGVAR(a,b,c) // Empty macro to remove DEBUGVAR calls

uint32_t faad_get_processed_bits(bitfile *ld);
uint32_t faad_getbits(bitfile *ld, int n);
uint8_t faad_get1bit(bitfile *ld);
void faad_resetbits(bitfile *ld, uint16_t n);
void sbr_header(bitfile *ld, sbr_info *sbr);
void sbr_reset(sbr_info *sbr);
uint8_t calc_sbr_tables(sbr_info *sbr, uint8_t start_freq, uint8_t stop_freq,
                       uint8_t samplerate_mode, uint8_t freq_scale,
                       uint8_t alter_scale, uint8_t xover_band);
uint8_t sbr_data(bitfile *ld, sbr_info *sbr);