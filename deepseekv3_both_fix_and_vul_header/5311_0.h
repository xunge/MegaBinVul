#include <stddef.h>

#define SECTION_COMMENT 0
#define TAG_COMPUTED_VALUE 0
#define TAG_FMT_STRING 0

typedef struct {
    int dummy;
} image_info_type;

void exif_iif_add_tag(image_info_type *image_info, int section, const char *name, int tag_type, int tag_format, size_t length, char *value, ...);