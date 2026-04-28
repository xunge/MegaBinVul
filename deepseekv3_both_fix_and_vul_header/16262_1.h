#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define LOCAL static
#define MMDB_SUCCESS 0
#define MMDB_INVALID_METADATA_ERROR 1
#define MMDB_OUT_OF_MEMORY_ERROR 2
#define MMDB_DATA_TYPE_ARRAY 1
#define MMDB_DATA_TYPE_UTF8_STRING 2

#define MAYBE_CHECK_SIZE_OVERFLOW(size, max, error) \
    do { if ((size) > (max)) return (error); } while (0)

typedef struct MMDB_s MMDB_s;
typedef struct MMDB_entry_s MMDB_entry_s;
typedef struct MMDB_entry_data_s MMDB_entry_data_s;
typedef struct MMDB_entry_data_list_s MMDB_entry_data_list_s;

struct MMDB_s {
    struct {
        struct {
            uint32_t count;
            char **names;
        } languages;
    } metadata;
};

struct MMDB_entry_s {
    MMDB_s *mmdb;
    uint32_t offset;
};

struct MMDB_entry_data_s {
    uint32_t type;
    uint32_t offset;
    uint32_t data_size;
    const uint8_t *utf8_string;
};

struct MMDB_entry_data_list_s {
    MMDB_entry_data_s entry_data;
    MMDB_entry_data_list_s *next;
};

extern int MMDB_aget_value(MMDB_entry_s *start, MMDB_entry_data_s *entry_data, const char **path);
extern int MMDB_get_entry_data_list(MMDB_entry_s *start, MMDB_entry_data_list_s **entry_data_list);
extern void MMDB_free_entry_data_list(MMDB_entry_data_list_s *entry_data_list);
extern char *mmdb_strndup(const char *s, size_t n);