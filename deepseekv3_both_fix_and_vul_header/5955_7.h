#include <stdint.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

#define MAX_IFD_NESTING_LEVEL 100
#define NUM_FORMATS 12
#define TAG_FMT_BYTE 1
#define FALSE 0
#define TRUE 1
#define EXIFERR_CC
#define TSRMLS_DC
#define TSRMLS_CC
#define SECTION_THUMBNAIL 1
#define SECTION_IFD0 2
#define SECTION_EXIF 3
#define SECTION_GPS 4
#define SECTION_INTEROP 5
#define FOUND_ANY_TAG 1
#define FOUND_WINXP 2
#define FOUND_EXIF 4
#define FOUND_GPS 8
#define FOUND_INTEROP 16
#define E_WARNING 1
#define E_NOTICE 2
#define IMAGE_FILETYPE_TIFF_II 1
#define IMAGE_FILETYPE_TIFF_MM 2
#define IMAGE_FILETYPE_JPEG 3
#define IMAGE_FILETYPE_UNKNOWN 0
#define TAG_IMAGEWIDTH 1
#define TAG_COMP_IMAGE_WIDTH 2
#define TAG_IMAGEHEIGHT 3
#define TAG_COMP_IMAGE_HEIGHT 4
#define TAG_STRIP_OFFSETS 5
#define TAG_JPEG_INTERCHANGE_FORMAT 6
#define TAG_STRIP_BYTE_COUNTS 7
#define TAG_JPEG_INTERCHANGE_FORMAT_LEN 8
#define TAG_COPYRIGHT 9
#define TAG_USERCOMMENT 10
#define TAG_XP_TITLE 11
#define TAG_XP_COMMENTS 12
#define TAG_XP_AUTHOR 13
#define TAG_XP_KEYWORDS 14
#define TAG_XP_SUBJECT 15
#define TAG_FNUMBER 16
#define TAG_APERTURE 17
#define TAG_MAX_APERTURE 18
#define TAG_SHUTTERSPEED 19
#define TAG_EXPOSURETIME 20
#define TAG_FOCALPLANE_X_RES 21
#define TAG_SUBJECT_DISTANCE 22
#define TAG_FOCALPLANE_RESOLUTION_UNIT 23
#define TAG_SUB_IFD 24
#define TAG_MAKE 25
#define TAG_MODEL 26
#define TAG_MAKER_NOTE 27
#define TAG_EXIF_IFD_POINTER 28
#define TAG_GPS_IFD_POINTER 29
#define TAG_INTEROP_IFD_POINTER 30
#define TAG_FMT_UNDEFINED 7
#define TAG_FMT_STRING 2
#define TAG_FMT_IFD 13
#define SEEK_SET 0

typedef struct {
    char *data;
    size_t length;
} xp_field_type;

typedef struct {
    int tag;
    char *name;
} tag_table_type;

typedef struct {
    int ifd_nesting_level;
    int motorola_intel;
    size_t FileSize;
    int FileType;
    void *infile;
    unsigned int sections_found;
    struct {
        int width;
        int height;
        size_t offset;
        int filetype;
        size_t size;
        void *data;
    } Thumbnail;
    char *CopyrightPhotographer;
    char *CopyrightEditor;
    char *Copyright;
    size_t UserCommentLength;
    char *UserComment;
    int UserCommentEncoding;
    struct {
        xp_field_type *list;
        int count;
    } xp_fields;
    float ApertureFNumber;
    float ExposureTime;
    int ExifImageWidth;
    double FocalplaneXRes;
    float Distance;
    double FocalplaneUnits;
    char *make;
    char *model;
} image_info_type;

extern int php_ifd_get16u(char *dir_entry, int motorola_intel);
extern unsigned int php_ifd_get32u(char *dir_entry, int motorola_intel);
extern char *exif_get_tagname(int tag, char *tagname, int len, tag_table_type tag_table TSRMLS_DC);
extern void exif_error_docref(const char *docref EXIFERR_CC, image_info_type *ImageInfo, int level, const char *format, ...);
extern int64_t exif_convert_any_format(char *value_ptr, int format, int motorola_intel TSRMLS_DC);
extern int exif_convert_any_to_int(char *value_ptr, int format, int motorola_intel TSRMLS_DC);
extern size_t exif_process_user_comment(image_info_type *ImageInfo, char **UserComment, int *UserCommentEncoding, char *value_ptr, size_t byte_count TSRMLS_DC);
extern void exif_process_unicode(image_info_type *ImageInfo, xp_field_type *xp_field, int tag, char *value_ptr, size_t byte_count TSRMLS_DC);
extern int exif_process_IFD_in_JPEG(image_info_type *ImageInfo, char *dir_entry, char *offset_base, size_t IFDlength, size_t displacement, int section_index TSRMLS_DC);
extern void exif_process_IFD_in_MAKERNOTE(image_info_type *ImageInfo, char *value_ptr, size_t byte_count, char *offset_base, size_t IFDlength, size_t displacement TSRMLS_DC);
extern void exif_iif_add_tag(image_info_type *ImageInfo, int section_index, char *tagname, int tag, int format, int components, char *value_ptr TSRMLS_DC);
extern char *exif_get_sectionname(int section_index);
extern char *exif_get_tagformat(int format);
extern char *exif_dump_data(int *dump_free, int format, int components, size_t length, int motorola_intel, char *value_ptr TSRMLS_DC);
extern size_t php_strnlen(char *str, size_t maxlen);
extern char *estrdup(char *str);
extern void *safe_emalloc(size_t nmemb, size_t size, size_t offset);
extern void *safe_erealloc(void *ptr, size_t nmemb, size_t size, size_t offset);
extern void EFREE_IF(char *ptr);
extern int php_stream_tell(void *stream);
extern int php_stream_seek(void *stream, size_t offset, int whence);
extern size_t php_stream_read(void *stream, char *buf, size_t count);
extern void spprintf(char **str, size_t max_len, const char *format, ...);
extern void EXIF_ERRLOG_FILEEOF(image_info_type *ImageInfo);
extern int php_tiff_bytes_per_format[NUM_FORMATS+1];

#define EXIF_ERRLOG_FILEEOF(ImageInfo) EXIF_ERRLOG_FILEEOF(ImageInfo);