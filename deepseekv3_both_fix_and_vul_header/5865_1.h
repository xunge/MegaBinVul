#include <stdlib.h>

typedef struct dissector_table_t *dissector_table_t;
typedef struct dtbl_entry_t {
    void *initial;
} dtbl_entry_t;
typedef void *dissector_handle_t;
typedef char gchar;

dissector_table_t find_dissector_table(const char *name);
dtbl_entry_t *find_string_dtbl_entry(dissector_table_t sub_dissectors, const gchar *string);