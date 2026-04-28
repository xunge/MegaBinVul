#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

#define FALSE 0
#define EXIFERR_CC
#define E_WARNING 0
#define E_NOTICE 0

#define PHP_STREAM_IS_STDIO 0
#define IMAGE_FILETYPE_UNKNOWN 0

typedef struct stat zend_stat_t;

typedef struct _zend_string {
    char *val;
    size_t len;
} zend_string;

#define ZSTR_VAL(s) ((s)->val)
#define ZSTR_LEN(s) ((s)->len)

typedef struct _php_stream {
    char *orig_path;
} php_stream;

typedef struct {
    int motorola_intel;
    php_stream *infile;
    char *FileName;
    time_t FileDateTime;
    off_t FileSize;
    int read_thumbnail;
    int read_all;
    struct {
        int filetype;
    } Thumbnail;
    char *encode_unicode;
    char *decode_unicode_be;
    char *decode_unicode_le;
    char *encode_jis;
    char *decode_jis_be;
    char *decode_jis_le;
    int ifd_nesting_level;
} image_info_type;

typedef struct {
    char *encode_unicode;
    char *decode_unicode_be;
    char *decode_unicode_le;
    char *encode_jis;
    char *decode_jis_be;
    char *decode_jis_le;
} exif_globals;

extern exif_globals EXIF_G;
extern int exif_scan_FILE_header(image_info_type *ImageInfo);
extern void exif_error_docref(const char *docref, image_info_type *ImageInfo, int level, const char *format, ...);
extern char *estrndup(const char *s, size_t length);
extern char *estrdup(const char *s);
extern void zend_string_release(zend_string *s);
extern zend_string *php_basename(const char *path, size_t path_len, const char *suffix, size_t suffix_len);
extern int php_stream_is(php_stream *stream, int flag);
extern void php_stream_close(php_stream *stream);
extern int php_stream_seek(php_stream *stream, off_t offset, int whence);
extern off_t php_stream_tell(php_stream *stream);

#define VCWD_STAT(path, buf) stat(path, buf)

#define EXIF_G(prop) (EXIF_G.prop)