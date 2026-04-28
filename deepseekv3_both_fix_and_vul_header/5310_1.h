#include <stddef.h>

typedef struct {
    int motorola_intel;
} image_info_type;

void exif_iif_add_value(image_info_type *image_info, int section_index, char *name, int tag, int format, int length, void* value, ...);