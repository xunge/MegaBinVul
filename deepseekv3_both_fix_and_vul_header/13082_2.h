#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define g_autofree 
#define TRUE true
#define FALSE false
#define _(x) x

typedef bool gboolean;

typedef enum {
  FLATPAK_FILESYSTEM_MODE_NONE,
  FLATPAK_FILESYSTEM_MODE_READ_ONLY,
  FLATPAK_FILESYSTEM_MODE_READ_WRITE,
  FLATPAK_FILESYSTEM_MODE_CREATE
} FlatpakFilesystemMode;

typedef struct {
  int domain;
  int code;
  char *message;
} GError;

#define G_OPTION_ERROR 0
#define G_OPTION_ERROR_BAD_VALUE 1
#define G_OPTION_ERROR_FAILED 2

extern const char *flatpak_context_special_filesystems[];

char *parse_filesystem_flags(const char *filesystem_and_mode,
                           gboolean negated,
                           FlatpakFilesystemMode *mode_out,
                           GError **error);

char *g_strdup(const char *str);
char *g_strconcat(const char *string1, ...);
void g_set_error(GError **err, int domain, int code, const char *format, ...);
void *g_steal_pointer(void *pp);
bool g_strv_contains(const char * const *strv, const char *str);
bool g_str_has_prefix(const char *str, const char *prefix);
bool g_str_has_suffix(const char *str, const char *suffix);
bool get_xdg_user_dir_from_string(const char *dir, char **name_out, 
                                char **path_out, GError **error);