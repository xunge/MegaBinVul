#include <stddef.h>

#define FALSE 0
#define TRUE 1
#define EXIF_DEBUG
#define EXIFERR_CC
#define TSRMLS_DC
#define TSRMLS_CC
#define E_NOTICE 0
#define E_WARNING 0
#define FOUND_IFD0 0
#define SECTION_THUMBNAIL 0
#define IMAGE_FILETYPE_UNKNOWN 0

typedef struct {
    int motorola_intel;
    int sections_found;
    struct {
        size_t size;
        int filetype;
        size_t offset;
    } Thumbnail;
    int read_thumbnail;
} image_info_type;

void exif_error_docref(const char *msg, image_info_type *ImageInfo, int level, const char *format, ...);
int php_ifd_get16u(char *dir_start, int motorola_intel);
int php_ifd_get32u(char *dir_start, int motorola_intel);
int exif_process_IFD_TAG(image_info_type *ImageInfo, char *dir_start, char *offset_base, size_t IFDlength, size_t displacement, int section_index, int tag_table, void *tsrm_ls);
const char *exif_get_sectionname(int section_index);
void *exif_get_tag_table(int section_index);
void exif_thumbnail_extract(image_info_type *ImageInfo, char *offset_base, size_t IFDlength);