#include <stdint.h>
#include <stdbool.h>

#define EXIF_TYPE_SHORT 3

int find_exif_tag(uint8_t* exif, int size, uint16_t modify_tag, bool* little_endian);
int read16(uint8_t* exif, int size, int pos, bool little_endian);
int read32(uint8_t* exif, int size, int pos, bool little_endian);
void write16(uint8_t* exif, int size, int pos, uint16_t value, bool little_endian);