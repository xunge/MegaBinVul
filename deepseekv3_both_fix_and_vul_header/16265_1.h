#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>

typedef enum {
    MMDB_DATA_TYPE_EXTENDED,
    MMDB_DATA_TYPE_POINTER,
    MMDB_DATA_TYPE_UTF8_STRING,
    MMDB_DATA_TYPE_DOUBLE,
    MMDB_DATA_TYPE_BYTES,
    MMDB_DATA_TYPE_UINT16,
    MMDB_DATA_TYPE_UINT32,
    MMDB_DATA_TYPE_MAP,
    MMDB_DATA_TYPE_INT32,
    MMDB_DATA_TYPE_UINT64,
    MMDB_DATA_TYPE_UINT128,
    MMDB_DATA_TYPE_ARRAY,
    MMDB_DATA_TYPE_FLOAT,
    MMDB_DATA_TYPE_BOOLEAN
} MMDB_data_type_t;

typedef enum {
    MMDB_SUCCESS,
    MMDB_INVALID_DATA_ERROR,
    MMDB_OUT_OF_MEMORY_ERROR
} MMDB_status_t;

typedef struct MMDB_entry_data_s {
    MMDB_data_type_t type;
    uint16_t data_size;
    union {
        uint16_t uint16;
        uint32_t uint32;
        int32_t int32;
        uint64_t uint64;
        double double_value;
        float float_value;
        bool boolean;
        uint8_t *bytes;
        char *utf8_string;
        uint8_t uint128[16];
    };
} MMDB_entry_data_s;

typedef struct MMDB_entry_data_list_s {
    MMDB_entry_data_s entry_data;
    struct MMDB_entry_data_list_s *next;
} MMDB_entry_data_list_s;

#define MMDB_UINT128_IS_BYTE_ARRAY 1
#define LOCAL static

extern char *mmdb_strndup(const char *s, size_t n);
extern char *bytes_to_hex(uint8_t *bytes, size_t size);
extern void print_indentation(FILE *stream, int indent);