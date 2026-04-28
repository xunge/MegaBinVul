#include <assert.h>
#include <stddef.h>

enum entity_charset {
    cs_utf_8,
    cs_big5,
    cs_big5hkscs,
    cs_gb2312,
    cs_sjis,
    cs_eucjp
};

#define SUCCESS 0
#define FAILURE 1

#define CHECK_LEN(pos, len) ((pos) + (len) <= str_len)
#define MB_FAILURE(pos, len) do { *status = FAILURE; *cursor = (pos) + (len); return 0; } while (0)

static inline int utf8_lead(unsigned char c) { return (c & 0xC0) == 0x80; }
static inline int utf8_trail(unsigned char c) { return (c & 0xC0) == 0x80; }
static inline int gb2312_lead(unsigned char c) { return (c >= 0xA1 && c <= 0xFE); }
static inline int gb2312_trail(unsigned char c) { return (c >= 0xA1 && c <= 0xFE); }
static inline int sjis_lead(unsigned char c) { return (c >= 0x81 && c <= 0x9F) || (c >= 0xE0 && c <= 0xFC); }
static inline int sjis_trail(unsigned char c) { return (c >= 0x40 && c <= 0x7E) || (c >= 0x80 && c <= 0xFC); }