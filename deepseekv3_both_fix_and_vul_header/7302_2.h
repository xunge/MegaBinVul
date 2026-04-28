#include <stdint.h>
#include <stdio.h>

typedef struct r_device r_device;

typedef struct {
    int num_rows;
    int bits_per_row[1];
    uint8_t bb[1][1];
} bitbuffer_t;

typedef struct data_t data_t;

#define DECODE_ABORT_EARLY 0
#define DECODE_ABORT_LENGTH 0
#define DECODE_FAIL_MIC 0

#define DATA_STRING 0
#define DATA_FORMAT 1
#define DATA_INT 2

int bitbuffer_search(bitbuffer_t *bitbuffer, int row, int start, uint8_t const *pattern, int pattern_bits);
int extract_bytes_uart(uint8_t *bits, int offset, int num_bits, uint8_t *bytes);
uint16_t crc16lsb(uint8_t const *message, int nBytes, uint16_t polynomial, uint16_t init);
void bitrow_printf(uint8_t const *bits, int num_bits, char const *fmt, ...);
void bitrow_snprint(uint8_t const *bits, int num_bits, char *str, int size);
data_t *data_make(char const *key, char const *description, ...);
void decoder_output_data(r_device *decoder, data_t *data);