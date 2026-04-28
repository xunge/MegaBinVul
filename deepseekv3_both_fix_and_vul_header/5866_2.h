#include <stddef.h>

typedef void* dissector_handle_t;
typedef void* dissector_table_t;
typedef char gchar;

typedef struct dtbl_entry_t {
    dissector_handle_t *current;
} dtbl_entry_t;

extern dtbl_entry_t *find_string_dtbl_entry(dissector_table_t sub_dissectors, const gchar *string);