#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef int64_t zip_int64_t;
typedef uint64_t zip_uint64_t;
typedef uint32_t zip_uint32_t;
typedef uint16_t zip_uint16_t;
typedef uint8_t zip_uint8_t;

#define CDENTRYSIZE 46
#define LENTRYSIZE 30
#define LOCAL_MAGIC "\x50\x4b\x03\x04"
#define CENTRAL_MAGIC "\x50\x4b\x01\x02"
#define ZIP_UINT32_MAX 0xffffffffU
#define ZIP_UINT16_MAX 0xffffU
#define ZIP_INT64_MAX INT64_MAX
#define ZIP_GPBF_ENCRYPTED 1
#define ZIP_GPBF_STRONG_ENCRYPTION 64
#define ZIP_GPBF_ENCODING_UTF_8 2048
#define ZIP_EM_UNKNOWN 0
#define ZIP_EM_TRAD_PKWARE 1
#define ZIP_EM_NONE 0
#define ZIP_EF_LOCAL 1
#define ZIP_EF_CENTRAL 2
#define ZIP_EF_UTF_8_NAME 0x0001
#define ZIP_EF_UTF_8_COMMENT 0x0002
#define ZIP_EF_ZIP64 0x0001
#define ZIP_ENCODING_UTF8_KNOWN 1
#define ZIP_ENCODING_ERROR 0
#define ZIP_ER_NOZIP 0
#define ZIP_ER_INTERNAL 1
#define ZIP_ER_INCONS 2
#define ZIP_ER_MEMORY 3
#define ZIP_ER_EOF 4
#define ZIP_ER_SEEK 5
#define EFBIG 6

typedef struct zip_dirent {
    uint16_t version_madeby;
    uint16_t version_needed;
    uint16_t bitflags;
    uint16_t comp_method;
    time_t last_mod;
    uint32_t crc;
    uint64_t comp_size;
    uint64_t uncomp_size;
    uint16_t filename_len;
    uint16_t comment_len;
    uint16_t ef_len;
    uint16_t disk_number;
    uint16_t int_attrib;
    uint32_t ext_attrib;
    uint64_t offset;
    uint16_t encryption_method;
    char *filename;
    void *extra_fields;
    char *comment;
    bool local_extra_fields_read;
} zip_dirent_t;

typedef struct zip_source zip_source_t;
typedef struct zip_buffer zip_buffer_t;
typedef struct zip_error zip_error_t;

zip_buffer_t *_zip_buffer_new_from_source(zip_source_t *src, size_t size, zip_uint8_t *buf, zip_error_t *error);
void _zip_buffer_free(zip_buffer_t *buffer);
zip_uint8_t *_zip_buffer_get(zip_buffer_t *buffer, size_t length);
zip_uint16_t _zip_buffer_get_16(zip_buffer_t *buffer);
zip_uint32_t _zip_buffer_get_32(zip_buffer_t *buffer);
zip_uint64_t _zip_buffer_get_64(zip_buffer_t *buffer);
bool _zip_buffer_ok(zip_buffer_t *buffer);
size_t _zip_buffer_left(zip_buffer_t *buffer);
void _zip_buffer_skip(zip_buffer_t *buffer, size_t length);
bool _zip_buffer_eof(zip_buffer_t *buffer);
zip_buffer_t *_zip_buffer_new(zip_uint8_t *data, size_t size);
void _zip_dirent_init(zip_dirent_t *zde);
time_t _zip_d2u_time(zip_uint16_t dostime, zip_uint16_t dosdate);
char *_zip_read_string(zip_buffer_t *buffer, zip_source_t *src, size_t length, bool allow_null, zip_error_t *error);
zip_uint8_t *_zip_read_data(zip_buffer_t *buffer, zip_source_t *src, size_t length, bool allow_null, zip_error_t *error);
bool _zip_ef_parse(const zip_uint8_t *data, zip_uint16_t len, zip_uint16_t flags, void **ef, zip_error_t *error);
int _zip_guess_encoding(const char *str, int known);
char *_zip_dirent_process_ef_utf_8(zip_dirent_t *zde, zip_uint16_t id, char *str);
const zip_uint8_t *_zip_ef_get_by_id(void *ef, zip_uint16_t *lenp, zip_uint16_t id, zip_uint16_t idx, zip_uint16_t flags, zip_error_t *error);
bool _zip_dirent_process_winzip_aes(zip_dirent_t *zde, zip_error_t *error);
void *_zip_ef_remove_internal(void *ef);
void zip_error_set(zip_error_t *error, int ze, int se);
int zip_error_code_zip(zip_error_t *error);