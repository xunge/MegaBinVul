#include <stddef.h>

typedef struct _image_info_type image_info_type;

#define SECTION_APP12 0
#define TAG_NONE 0
#define TAG_FMT_STRING 0

size_t php_strnlen(const char *s, size_t maxlen);
void exif_iif_add_tag(image_info_type *ImageInfo, int section, const char *name, 
                     int tag, int format, size_t length, void *value);