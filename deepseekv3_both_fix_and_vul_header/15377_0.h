#include <stdint.h>
#include <stdbool.h>

#define EXIF_TAG_ORIENTATION 0x0112
#define EXIF_TYPE_SHORT 3
#define DEFAULT_EXIF_ORIENTATION 1

int find_exif_tag(const uint8_t* exif, int size, int tag, bool* little_endian);
int read16(const uint8_t* exif, int size, int pos, bool little_endian);
int read32(const uint8_t* exif, int size, int pos, bool little_endian);