#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

#define FALSE 0
#define TRUE 1
#define MAX_IFD_NESTING_LEVEL 100
#define NUM_FORMATS 12
#define TAG_FMT_BYTE 1
#define TAG_FMT_UNDEFINED 7
#define TAG_FMT_STRING 2
#define TAG_FMT_IFD 13
#define SECTION_THUMBNAIL 1
#define SECTION_IFD0 2
#define SECTION_EXIF 3
#define SECTION_GPS 4
#define SECTION_INTEROP 5
#define FOUND_ANY_TAG 1
#define FOUND_EXIF 2
#define FOUND_GPS 4
#define FOUND_INTEROP 8
#define FOUND_WINXP 16
#define IMAGE_FILETYPE_TIFF_II 1
#define IMAGE_FILETYPE_TIFF_MM 2
#define IMAGE_FILETYPE_JPEG 3
#define IMAGE_FILETYPE_UNKNOWN 0
#define TAG_IMAGEWIDTH 256
#define TAG_COMP_IMAGE_WIDTH 40962
#define TAG_IMAGEHEIGHT 257
#define TAG_COMP_IMAGE_HEIGHT 40963
#define TAG_STRIP_OFFSETS 273
#define TAG_JPEG_INTERCHANGE_FORMAT 513
#define TAG_STRIP_BYTE_COUNTS 279
#define TAG_JPEG_INTERCHANGE_FORMAT_LEN 514
#define TAG_COPYRIGHT 33432
#define TAG_USERCOMMENT 37510
#define TAG_XP_TITLE 40091
#define TAG_XP_COMMENTS 40092
#define TAG_XP_AUTHOR 40093
#define TAG_XP_KEYWORDS 40094
#define TAG_XP_SUBJECT 40095
#define TAG_FNUMBER 33437
#define TAG_APERTURE 37378
#define TAG_MAX_APERTURE 37381
#define TAG_SHUTTERSPEED 37377
#define TAG_EXPOSURETIME 33434
#define TAG_FOCALPLANE_X_RES 41486
#define TAG_SUBJECT_DISTANCE 37382
#define TAG_FOCALPLANE_RESOLUTION_UNIT 41488
#define TAG_SUB_IFD 330
#define TAG_MAKE 271
#define TAG_MODEL 272
#define TAG_MAKER_NOTE 37500
#define TAG_EXIF_IFD_POINTER 34665
#define TAG_GPS_IFD_POINTER 34853
#define TAG_INTEROP_IFD_POINTER 40965
#define EXIFERR_CC
#define E_WARNING 2
#define E_NOTICE 8
#define TSRMLS_DC
#define TSRMLS_CC

static const size_t php_tiff_bytes_per_format[] = {
    0,  /* dummy */
    1,  /* BYTE */
    1,  /* ASCII */
    2,  /* SHORT */
    4,  /* LONG */
    8,  /* RATIONAL */
    1,  /* SBYTE */
    1,  /* UNDEFINED */
    2,  /* SSHORT */
    4,  /* SLONG */
    8,  /* SRATIONAL */
    4,  /* FLOAT */
    8   /* DOUBLE */
};

typedef struct {
    int tag;
    char *data;
    int length;
} xp_field_type;

typedef struct {
    int count;
    xp_field_type *list;
} xp_fields_type;

typedef struct {
    int width;
    int height;
    int offset;
    int size;
    int filetype;
    void *data;
} thumbnail_type;

typedef struct {
    int FileType;
    size_t FileSize;
    FILE *infile;
    int motorola_intel;
    int ifd_nesting_level;
    thumbnail_type Thumbnail;
    char *Copyright;
    char *CopyrightPhotographer;
    char *CopyrightEditor;
    char *UserComment;
    int UserCommentLength;
    int UserCommentEncoding;
    xp_fields_type xp_fields;
    float ApertureFNumber;
    float ExposureTime;
    int ExifImageWidth;
    float FocalplaneXRes;
    float Distance;
    float FocalplaneUnits;
    char *make;
    char *model;
    int sections_found;
} image_info_type;

typedef struct {
    int tag;
    char *name;
} tag_table_type;

extern int php_ifd_get16u(void *, int);
extern int php_ifd_get32u(void *, int);
extern char *exif_get_tagname(int, char *, int, tag_table_type);
extern char *exif_get_tagformat(int);
extern int exif_convert_any_to_int(void *, int, int);
extern float exif_convert_any_format(void *, int, int);
extern int exif_process_user_comment(image_info_type *, char **, int *, char *, size_t);
extern void exif_process_unicode(image_info_type *, xp_field_type *, int, char *, size_t);
extern int exif_process_IFD_in_MAKERNOTE(image_info_type *, char *, size_t, char *, size_t, size_t);
extern int exif_process_IFD_in_JPEG(image_info_type *, char *, char *, size_t, size_t, int);
extern void exif_iif_add_tag(image_info_type *, int, char *, int, int, int, void *);
extern void *safe_emalloc(size_t, size_t, size_t);
extern void *safe_erealloc(void *, size_t, size_t, size_t);
extern char *estrdup(const char *);
extern char *estrndup(const char *, size_t);
extern void spprintf(char **, size_t, const char *, ...);
extern void exif_error_docref(const char *, image_info_type *, int, const char *, ...);
extern size_t php_strnlen(const char *, size_t);
extern void *efree(void *);
#define EFREE_IF(ptr) if (ptr) efree(ptr)
#define EXIF_ERRLOG_FILEEOF(ImageInfo)