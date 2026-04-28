#include <stdint.h>
#include <stddef.h>

typedef uint16_t ut16;
typedef uint8_t ut8;
#define UT16_MAX UINT16_MAX

static inline ut16 r_read_le16(const ut8 *s);