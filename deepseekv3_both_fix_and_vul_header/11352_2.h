#include <string.h>
#include <stddef.h>

#define SECTION_MAKERNOTE 0
#define FOUND_MAKERNOTE (1 << 0)
#define EXIFERR_CC
#define TSRMLS_DC
#define TSRMLS_CC
#define E_NOTICE 0
#define E_WARNING 0
#define MN_ORDER_INTEL 0
#define MN_ORDER_MOTOROLA 1
#define MN_ORDER_NORMAL 2
#define MN_OFFSET_MAKER 0
#define MN_OFFSET_GUESS 1
#define MN_OFFSET_NORMAL 2
#define TRUE 1
#define FALSE 0

typedef struct _image_info_type {
    char *make;
    char *model;
    int motorola_intel;
    unsigned int sections_found;
} image_info_type;

typedef struct _maker_note_type {
    const char *make;
    const char *model;
    const char *id_string;
    size_t id_string_len;
    size_t offset;
    int byte_order;
    int offset_mode;
    void *tag_table;
} maker_note_type;

extern const maker_note_type maker_note_array[1];
extern int php_ifd_get16u(char *dir_start, int motorola_intel);
extern int php_ifd_get32u(char *dir_start, int motorola_intel);
extern void exif_error_docref(const char *docref, image_info_type *ImageInfo, int level, const char *format, ...);
extern char *exif_get_sectionname(int section_index);
extern char *exif_char_dump(char *value_ptr, int value_len, int displacement);
extern int exif_process_IFD_TAG(image_info_type *ImageInfo, char *dir_start, char *offset_base, size_t IFDlength, size_t displacement, int section_index, int tag_table, const maker_note_type *maker_note TSRMLS_DC);