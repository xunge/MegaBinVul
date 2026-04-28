#include <stddef.h>

typedef struct {
    void *data;
    size_t size;
    size_t offset;
} thumbnail_type;

typedef struct {
    thumbnail_type Thumbnail;
    int read_thumbnail;
} image_info_type;

#define EXIFERR_CC
#define TSRMLS_DC
#define TSRMLS_CC
#define E_WARNING 0

void exif_error_docref(const char *msg, image_info_type *ImageInfo, int level, const char *format);
#define EXIF_ERRLOG_THUMBEOF(ImageInfo) ;
char *estrndup(const char *s, size_t length);
void exif_thumbnail_build(image_info_type *ImageInfo TSRMLS_DC);