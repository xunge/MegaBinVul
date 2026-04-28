typedef int gboolean;
typedef void* gpointer;
typedef char gchar;

#define TRUE 1
#define FALSE 0

typedef struct {
    int dummy;
} GError;

typedef struct _FlatpakContext FlatpakContext;

gboolean flatpak_context_set_persistent(FlatpakContext *context, const gchar *value, ...);