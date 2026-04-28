#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define LOCAL static
#define MMDB_SUCCESS 0
#define MMDB_INVALID_METADATA_ERROR 1
#define MMDB_OUT_OF_MEMORY_ERROR 2
#define MMDB_DATA_TYPE_MAP 2
#define MMDB_DATA_TYPE_UTF8_STRING 8

typedef struct MMDB_s {
    struct {
        struct {
            uint32_t count;
            struct MMDB_description_s **descriptions;
        } description;
    } metadata;
} MMDB_s;

typedef struct MMDB_entry_s {
    MMDB_s *mmdb;
    uint32_t offset;
} MMDB_entry_s;

typedef struct MMDB_entry_data_s {
    uint32_t type;
    uint32_t offset;
    uint32_t data_size;
    union {
        char *utf8_string;
    };
} MMDB_entry_data_s;

typedef struct MMDB_entry_data_list_s {
    MMDB_entry_data_s entry_data;
    struct MMDB_entry_data_list_s *next;
} MMDB_entry_data_list_s;

typedef struct MMDB_description_s {
    char *language;
    char *description;
} MMDB_description_s;

#define DEBUG_MSGF(...)
#define MAYBE_CHECK_SIZE_OVERFLOW(a, b, c)

char *mmdb_strndup(const char *s, size_t n);
void MMDB_free_entry_data_list(MMDB_entry_data_list_s *first_member);
int MMDB_aget_value(MMDB_entry_s *start, MMDB_entry_data_s *entry_data, const char **path);
int MMDB_get_entry_data_list(MMDB_entry_s *start, MMDB_entry_data_list_s **entry_data_list);
const char *MMDB_strerror(int error_code);