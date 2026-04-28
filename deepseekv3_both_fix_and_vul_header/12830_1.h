#include <stdint.h>

#define DRWAV_API

typedef uint8_t drwav_uint8;
typedef uint16_t drwav_uint16;
typedef int16_t drwav_int16;

drwav_uint16 drwav_bytes_to_u16(const drwav_uint8* data);