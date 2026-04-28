#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct MMDB_entry_s MMDB_entry_s;
typedef struct MMDB_entry_data_s MMDB_entry_data_s;

#define MMDB_INVALID_METADATA_ERROR -1
#define MMDB_OUT_OF_MEMORY_ERROR -2

#define MAYBE_CHECK_SIZE_OVERFLOW(a, b, c) 

int path_length(va_list va_path);
int MMDB_aget_value(MMDB_entry_s *const start, MMDB_entry_data_s *const entry_data, const char **path);