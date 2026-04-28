#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef long ssize_t;

int u8_check(const uint8_t *str, size_t len);
char *g_utf8_normalize(const char *str, ssize_t len, int mode);

#define G_NORMALIZE_NFKC 0