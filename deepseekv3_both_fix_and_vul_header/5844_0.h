#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef long glong;
extern int u8_check(const uint8_t *str, size_t len);
extern uint32_t *g_utf8_to_ucs4_fast(const char *str, glong len, glong *items_written);