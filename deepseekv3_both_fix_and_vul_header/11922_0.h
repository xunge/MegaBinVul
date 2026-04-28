#include <stdint.h>

#define HI_RES 0
#define LO_RES 1
#define MAX_M 64

typedef struct {
    uint8_t N_master;
    uint8_t N_high;
    uint8_t N_low;
    uint8_t n[2];
    uint8_t f_table_res[2][64];
    uint8_t M;
    uint8_t kx;
    uint8_t bs_noise_bands;
    uint8_t N_Q;
    uint8_t f_table_noise[6];
    uint8_t table_map_k_to_g[64];
    uint8_t f_master[64];
} sbr_info;

uint8_t max(uint8_t a, uint8_t b) {
    return (a > b) ? a : b;
}

uint8_t min(uint8_t a, uint8_t b) {
    return (a < b) ? a : b;
}

uint8_t find_bands(uint8_t start, uint8_t bands, uint8_t kx, uint8_t k2) {
    return 0;
}