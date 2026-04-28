#include <stdint.h>
#include <arpa/inet.h>

extern u_int32_t ndpi_bytestream_to_number(const u_int8_t *str, u_int16_t max_chars_to_read, u_int16_t *bytes_read);