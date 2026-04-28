#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef size_t gsize;
typedef char gchar;
typedef int gboolean;
typedef int gint;

#define G_MAXSIZE ((gsize)-1)
#define G_STRLOC ""
#define g_return_if_fail(expr) do { if (!(expr)) return; } while (0)
#define g_warning(...)
#define g_renew(type, mem, count) ((type*)realloc((mem), sizeof(type) * (count)))

typedef enum {
  G_OPTION_ARG_NONE,
  G_OPTION_ARG_CALLBACK
} GOptionArg;

typedef struct {
  const gchar *long_name;
  gchar short_name;
  GOptionArg arg;
  gint flags;
} GOptionEntry;

typedef struct {
  GOptionEntry *entries;
  gsize n_entries;
  const gchar *name;
} GOptionGroup;

#define G_OPTION_FLAG_REVERSE (1 << 0)
#define G_OPTION_FLAG_NO_ARG (1 << 1)
#define G_OPTION_FLAG_OPTIONAL_ARG (1 << 2)
#define G_OPTION_FLAG_FILENAME (1 << 3)

static inline gboolean g_ascii_isprint(gchar c) {
  return isprint((unsigned char)c);
}