#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef int64_t st64;
typedef uint8_t ut8;
typedef uint16_t ut16;
typedef uint32_t ut32;
typedef uint64_t ut64;

typedef struct RBuffer RBuffer;

st64 r_buf_read(RBuffer *b, ut8 *buf, int len);
st64 r_buf_write(RBuffer *b, const ut8 *buf, int len);
int r_num_get(void *user, const char *str);
ut8 r_read_ble8(const ut8 *buf);
ut16 r_read_ble16(const ut8 *buf, bool big_endian);
ut32 r_read_ble32(const ut8 *buf, bool big_endian);
ut64 r_read_ble64(const ut8 *buf, bool big_endian);