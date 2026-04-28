#include <stdint.h>
#include <string.h>

#define ILLEGAL_CHAR_MARK '_'
#define EXT_MARK '.'
#define EXT_SIZE 5
#define CRC_LEN 5
#define CRC_MARK '#'

extern unsigned short crc_itu_t(unsigned short crc, const unsigned char *buffer, int len);
extern uint8_t hex_asc_upper_hi(unsigned char value);
extern uint8_t hex_asc_upper_lo(unsigned char value);