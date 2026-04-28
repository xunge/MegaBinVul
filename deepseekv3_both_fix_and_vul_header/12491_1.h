#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    bool has_data_length;
    uint16_t data_length;
    struct {
        uint8_t bytes[1024];
    } data_initial_chunk;
} EthereumSignTx;