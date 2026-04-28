#include <string.h>
#include <stddef.h>

#define SECTION_MAKERNOTE 0
#define FOUND_MAKERNOTE 1
#define EXIFERR_CC
#define E_NOTICE 0
#define E_WARNING 1
#define TRUE 1
#define FALSE 0

#define MN_ORDER_INTEL 0
#define MN_ORDER_MOTOROLA 1
#define MN_ORDER_NORMAL 2
#define MN_OFFSET_MAKER 0
#define MN_OFFSET_GUESS 1
#define MN_OFFSET_NORMAL 2

typedef struct _image_info_type {
    char *make;
    int motorola_intel;
    unsigned int sections_found;
} image_info_type;

typedef struct _maker_note_type {
    char *make;
    char *id_string;
    int id_string_len;
    int offset;
    int byte_order;
    int offset_mode;
    void *tag_table;
} maker_note_type;

extern const maker_note_type maker_note_array[1];
extern int php_ifd_get16u(char *, int);
extern int php_ifd_get32u(char *, int);
extern void exif_error_docref(const char *, image_info_type *, int, const char *, ...);
extern int exif_process_IFD_TAG(image_info_type *, char *, char *, int, size_t, int, int, void *);
extern char *exif_get_sectionname(int);
extern char *exif_char_dump(char *, int, int);