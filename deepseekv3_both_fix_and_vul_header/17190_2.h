#include <stdint.h>
#include <stdlib.h>

typedef uint16_t utf16_t;

typedef struct {
    uint32_t name_offset;
    uint32_t value_offset;
    utf16_t *name;
    utf16_t *value;
    char *name_utf8;
    char *value_utf8;
} x3f_property_t;

typedef struct {
    uint32_t num_properties;
    x3f_property_t *element;
} x3f_property_table_t;

typedef struct {
    uint32_t data_size;
    void *data;
    uint32_t num_properties;
    x3f_property_table_t property_table;
} x3f_property_list_t;

typedef struct {
    x3f_property_list_t property_list;
} x3f_data_subsection_t;

typedef struct {
    x3f_data_subsection_t data_subsection;
} x3f_directory_entry_header_t;

typedef struct {
    x3f_directory_entry_header_t header;
} x3f_directory_entry_t;

typedef struct {
} x3f_info_t;

#define X3F_PROPERTY_LIST_HEADER_SIZE 0
#define LIBRAW_EXCEPTION_IO_CORRUPT 0

#define GET_PROPERTY_TABLE(table, count) \
    do { \
        (table).element = (x3f_property_t*)calloc((count), sizeof(x3f_property_t)); \
    } while(0)

void read_data_set_offset(x3f_info_t *I, x3f_directory_entry_t *DE, uint32_t size);
uint32_t read_data_block(void **data, x3f_info_t *I, x3f_directory_entry_t *DE, uint32_t flags);