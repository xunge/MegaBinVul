#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef struct bitreader bitreader;
typedef struct seq_parameter_set seq_parameter_set;

typedef struct position {
    int x;
    int y;
} position;

typedef struct scaling_list_data {
    uint8_t ScalingFactor_Size0[6][4][4];
    uint8_t ScalingFactor_Size1[6][8][8];
    uint8_t ScalingFactor_Size2[6][16][16];
    uint8_t ScalingFactor_Size3[6][32][32];
} scaling_list_data;

typedef enum {
    DE265_OK,
    DE265_ERROR_CODED_PARAMETER_OUT_OF_RANGE,
    UVLC_ERROR
} de265_error;

extern const uint8_t default_ScalingList_4x4[16];
extern const uint8_t default_ScalingList_8x8_intra[64];
extern const uint8_t default_ScalingList_8x8_inter[64];

int get_bits(bitreader* br, int n);
int get_uvlc(bitreader* br);
int get_svlc(bitreader* br);
const position* get_scan_order(int sizeId, int scanIdx);
void fill_scaling_factor(uint8_t* dst, uint8_t* src, int sizeId);