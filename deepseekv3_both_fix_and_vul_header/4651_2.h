#include <string.h>

typedef struct _image_info_type {
    int motorola_intel;
    unsigned int sections_found;
    float FocalplaneXRes;
    unsigned int ExifImageWidth;
    float FocalplaneUnits;
    float CCDWidth;
} image_info_type;

#define TSRMLS_DC
#define TSRMLS_CC
#define EXIFERR_CC
#define E_WARNING 2
#define E_NOTICE 8
#define FOUND_IFD0 1
#define SECTION_IFD0 1
#define EXIF_DEBUG 1

unsigned int php_ifd_get16u(char *buffer, int motorola_intel);
unsigned int php_ifd_get32u(char *buffer, int motorola_intel);
void exif_error_docref(const char *docref, image_info_type *ImageInfo, int type, const char *format);
void exif_process_IFD_in_JPEG(image_info_type *ImageInfo, char *dir_start, char *offset_base, size_t length, size_t displacement, int section_index);