#include <stddef.h>

typedef struct _image_info_type image_info_type;

#define SECTION_COMMENT 0
#define TAG_COMPUTED_VALUE 0
#define TAG_FMT_UNDEFINED 0
#define TAG_FMT_STRING 0
#define E_NOTICE 0

void exif_iif_add_tag(image_info_type *image_info, int section, const char *name, int tag, int format, size_t length, const char *value, ...);
void php_error_docref(const char *docref, int type, const char *format, ...);