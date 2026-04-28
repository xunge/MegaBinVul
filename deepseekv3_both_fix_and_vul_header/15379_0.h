#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

static int read32(const uint8_t* exif, int size, int offset, bool littleEndian);
static int read16(const uint8_t* exif, int size, int offset, bool littleEndian);