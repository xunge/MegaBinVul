#include <stdint.h>
#include <stddef.h>

typedef struct picoquic_cnx_t picoquic_cnx_t;

#define PICOQUIC_TRANSPORT_FINAL_OFFSET_ERROR 0

int picoquic_parse_stream_header(uint8_t* bytes, size_t bytes_max, uint64_t* stream_id, uint64_t* offset, size_t* data_length, int* fin, size_t* consumed);
void picoquic_connection_error(picoquic_cnx_t* cnx, int error_code, int dummy);
int picoquic_stream_network_input(picoquic_cnx_t* cnx, uint64_t stream_id, uint64_t offset, int fin, uint8_t* bytes, size_t data_length, uint64_t current_time);