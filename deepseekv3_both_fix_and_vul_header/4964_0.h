#include <stdint.h>
#include <string.h>

#define G_MAXUINT16 65535
#define WTAP_ERR_UNC_TRUNCATED 1
#define WTAP_ERR_UNC_OVERFLOW 2
#define WTAP_ERR_UNC_BAD_OFFSET 3

static inline uint16_t pletoh16(const unsigned char *p) {
    return (uint16_t)(p[0] | (p[1] << 8));
}