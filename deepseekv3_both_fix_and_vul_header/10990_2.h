#include <string.h>
#include <stddef.h>

#define SECTION_MAKERNOTE 0
#define FOUND_MAKERNOTE (1 << 0)
#define TRUE 1
#define FALSE 0
#define EXIFERR_CC
#define E_NOTICE 0
#define E_WARNING 1
#define EXIF_DEBUG
#define KALLE_0

#define MN_ORDER_INTEL 0
#define MN_ORDER_MOTOROLA 1
#define MN_ORDER_NORMAL 2
#define MN_OFFSET_MAKER 0
#define MN_OFFSET_GUESS 1
#define MN_OFFSET_NORMAL 2

typedef struct {
    const char *make;
    const char *model;
    const char *id_string;
    size_t id_string_len;
    int offset;
    int byte_order;
    int offset_mode;
    void *tag_table;
} maker_note_type;

static maker_note_type maker_note_array[] = {
    {NULL, NULL, NULL, 0, 0, MN_ORDER_NORMAL, MN_OFFSET_NORMAL, NULL}
};

typedef struct {
    char *make;
    char *model;
    int motorola_intel;
    unsigned int sections_found;
} image_info_type;

int php_ifd_get16u(char *dir_start, int motorola_intel);
int php_ifd_get32u(char *dir_start, int motorola_intel);
int exif_process_IFD_TAG(image_info_type *ImageInfo, char *dir_entry, char *offset_base, int data_len, size_t displacement, int section_index, int read_thumbnail, void *tag_table);
void exif_error_docref(const char *docref, image_info_type *ImageInfo, int level, const char *format, ...);
const char *exif_get_sectionname(int section_index);
char *exif_char_dump(char *value_ptr, int value_len, int offset);