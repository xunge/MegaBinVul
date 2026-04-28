#include <stddef.h>
#include <stdint.h>
#include <wchar.h>
#include <errno.h>

typedef uint8_t u8;
typedef wchar_t u16;
typedef uint32_t unicode_t;

enum utf16_endian {
    UTF16_LITTLE_ENDIAN,
    UTF16_BIG_ENDIAN
};

#define PLANE_SIZE 0x10000
#define SURROGATE_PAIR 0xD800
#define SURROGATE_LOW 0xDC00
#define SURROGATE_BITS 0x03FF

extern int utf8_to_utf32(const u8 *s, int len, unicode_t *pu);
extern void put_utf16(u16 *p, u16 utf16, enum utf16_endian endian);