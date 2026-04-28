#include <stdint.h>

extern int8_t sn_coap_parser_read_packet_u8(uint8_t *dst, uint8_t *packet_data_ptr, uint8_t *packet_data_start_ptr, uint16_t packet_len);
extern int8_t sn_coap_parser_read_packet_u16(uint16_t *dst, uint8_t *packet_data_ptr, uint8_t *packet_data_start_ptr, uint16_t packet_len);
extern uint16_t sn_coap_parser_move_packet_ptr(uint8_t **packet_data_pptr, uint8_t *packet_data_start_ptr, uint16_t packet_len, uint16_t move_len);
extern void tr_error(const char *format);