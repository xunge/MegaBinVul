#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define EOCD64LEN 56
#define EOCD64_MAGIC "\x50\x4b\x06\x06"
#define ZIP_INT64_MAX INT64_MAX
#define ZIP_ER_SEEK 1
#define ZIP_ER_INCONS 2
#define ZIP_ER_MULTIDISK 3
#define ZIP_ER_INTERNAL 4
#define EFBIG 1
#define ZIP_CHECKCONS 1
#define SEEK_SET 0

typedef uint64_t zip_uint64_t;
typedef uint32_t zip_uint32_t;
typedef uint16_t zip_uint16_t;
typedef uint8_t zip_uint8_t;
typedef int64_t zip_int64_t;

typedef struct zip_cdir_t {
    bool is_zip64;
    zip_uint64_t size;
    zip_uint64_t offset;
} zip_cdir_t;

typedef struct zip_source_t zip_source_t;
typedef struct zip_buffer_t zip_buffer_t;
typedef struct zip_error_t zip_error_t;

int zip_source_seek(zip_source_t *src, zip_int64_t offset, int whence);
zip_cdir_t* _zip_cdir_new(zip_uint64_t nentry, zip_error_t* error);
zip_buffer_t* _zip_buffer_new_from_source(zip_source_t* src, zip_uint64_t size, zip_uint8_t* buf, zip_error_t* error);
void _zip_buffer_free(zip_buffer_t* buffer);
void _zip_error_set_from_source(zip_error_t* error, zip_source_t* src);
void zip_error_set(zip_error_t* error, int code, int system_error);
bool _zip_buffer_ok(zip_buffer_t* buffer);
zip_uint64_t _zip_buffer_size(zip_buffer_t* buffer);
zip_uint64_t _zip_buffer_offset(zip_buffer_t* buffer);
void _zip_buffer_set_offset(zip_buffer_t* buffer, zip_uint64_t offset);
void* _zip_buffer_get(zip_buffer_t* buffer, zip_uint64_t length);
zip_uint64_t _zip_buffer_get_64(zip_buffer_t* buffer);
zip_uint32_t _zip_buffer_get_32(zip_buffer_t* buffer);
zip_uint16_t _zip_buffer_get_16(zip_buffer_t* buffer);