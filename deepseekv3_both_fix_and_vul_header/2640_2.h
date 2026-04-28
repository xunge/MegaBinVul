#include <stddef.h>

typedef int gboolean;
typedef void GFile;
typedef char gchar;

#define TRUE 1
#define FALSE 0
#define g_autofree
#define g_object_unref(ptr)

struct _NautilusFile;
typedef struct _NautilusFile NautilusFile;

#define NAUTILUS_METADATA_KEY_DESKTOP_FILE_TRUSTED "trusted"

gboolean nautilus_file_get_metadata(NautilusFile *file, const gchar *key, const gchar *default_value);
gboolean nautilus_file_can_execute(NautilusFile *file);
gboolean nautilus_file_is_local(NautilusFile *file);
GFile* nautilus_file_get_location(NautilusFile *file);
gboolean nautilus_is_in_system_dir(GFile *location);