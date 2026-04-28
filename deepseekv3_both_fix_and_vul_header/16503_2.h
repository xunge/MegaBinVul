#include <stddef.h>

typedef struct _AutoarExtractor AutoarExtractor;
struct _AutoarExtractor {
    void *destination_dir;
    void *prefix;
    void *new_prefix;
};

typedef void GFile;
typedef int gboolean;
#define g_autofree
#define g_debug(...)
#define g_object_unref(...)
#define g_file_get_child(...) NULL
#define g_file_equal(...) 0
#define g_file_has_prefix(...) 0
#define g_file_get_basename(...) NULL
#define g_file_get_relative_path(...) NULL
#define g_strdup(...) NULL
#define g_file_get_path(...) NULL

char* autoar_common_get_utf8_pathname(const char*);