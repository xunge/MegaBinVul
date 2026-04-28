#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define IDN2_OK 0
#define IDN2_MALLOC -1
#define IDN2_ENCODING_ERROR -2
#define IDN2_TOO_BIG_DOMAIN -3

extern int idn2_lookup_u8(uint8_t *src, uint8_t **dst, int flags);
extern uint8_t *u32_to_u8(uint32_t *src, size_t srclen, uint8_t *dst, size_t *dstlen);
extern void u32_cpy(uint32_t *dst, const uint32_t *src, size_t n);