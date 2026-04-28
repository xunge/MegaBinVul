#include <stdint.h>
#include <stddef.h>

typedef struct r_device r_device;
typedef struct data_t data_t;

typedef struct {
    uint8_t **bb;
    uint16_t *bits_per_row;
    unsigned num_rows;
} bitbuffer_t;

#define DECODE_ABORT_LENGTH 0
#define DECODE_FAIL_MIC 0

#define DATA_STRING 0
#define DATA_INT 1
#define DATA_FORMAT 2
#define DATA_DOUBLE 3
#define DATA_COND 4

void bitbuffer_invert(bitbuffer_t *bitbuffer);
uint16_t crc16lsb(uint8_t const *message, int nBytes, uint16_t polynomial, uint16_t init);
void decoder_log_bitrow(r_device *decoder, int level, const char *func, uint8_t *b, int bits, const char *msg);
data_t *data_make(const char *key, const char *description, ...);
void decoder_output_data(r_device *decoder, data_t *data);