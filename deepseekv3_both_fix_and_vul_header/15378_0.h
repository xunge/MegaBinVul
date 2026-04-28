#include <stdint.h>

#define EXIF_TAG_ORIENTATION 0x0112

void modify_exif_tag_if_it_exists(uint8_t* exifData, int size, uint16_t tag, uint16_t value);