#include <stdint.h>

typedef enum { BLOCK_LUMA, BLOCK_CHROMA } BlockType;

static const int zigzag[64];
static unsigned short quantization_table_[2][64];
static int icos_idct_linear_8192_scaled[64];
static int icos_base_8192_scaled[64];
static int icos_idct_linear_8192_dequantized[2][64];
static int icos_idct_edge_8192_dequantized_x[2][64];
static int icos_idct_edge_8192_dequantized_y[2][64];
static unsigned freqmax_[2][64];
static uint8_t bitlen_freqmax_[2][64];
static uint8_t min_noise_threshold_[2][64];
static const int RESIDUAL_NOISE_FLOOR = 0;

static uint8_t uint16bit_length(unsigned value) {
    uint8_t len = 0;
    while (value) {
        value >>= 1;
        len++;
    }
    return len;
}

#define icos_idct_linear_8192_dequantized(color) (icos_idct_linear_8192_dequantized[color])
#define icos_idct_edge_8192_dequantized_x(color) (icos_idct_edge_8192_dequantized_x[color])
#define icos_idct_edge_8192_dequantized_y(color) (icos_idct_edge_8192_dequantized_y[color])