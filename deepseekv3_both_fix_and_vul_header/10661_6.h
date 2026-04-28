#include <stdint.h>
#include <stddef.h>

typedef int gboolean;
typedef void* gpointer;
typedef long gssize;
typedef void* OstreeRepo;
typedef void* OstreeAsyncProgress;
typedef void* GCancellable;
typedef void* GError;
typedef void* GVariantBuilder;
typedef void* GVariantType;

typedef enum {
    OSTREE_REPO_PULL_FLAGS_UNTRUSTED = 1 << 0,
    OSTREE_REPO_PULL_FLAGS_BAREUSERONLY_FILES = 1 << 1
} OstreeRepoPullFlags;

typedef struct {
    int is_tty;
} GLnxConsoleRef;

#define FLATPAK_DEFAULT_UPDATE_FREQUENCY 0
#define G_VARIANT_TYPE(x) ((GVariantType*)x)
#define TRUE 1

void default_progress_changed(OstreeAsyncProgress *progress, gpointer user_data);
void glnx_console_lock(GLnxConsoleRef *console);
OstreeAsyncProgress* ostree_async_progress_new_and_connect(void (*cb)(OstreeAsyncProgress*, gpointer), gpointer data);
void ostree_async_progress_finish(OstreeAsyncProgress *progress);
gboolean ostree_repo_pull_with_options(OstreeRepo *self, const char *url, void *options, OstreeAsyncProgress *progress, GCancellable *cancellable, GError **error);
void g_variant_builder_init(GVariantBuilder *builder, GVariantType *type);
void g_variant_builder_add(GVariantBuilder *builder, const char *format_string, ...);
void* g_variant_new_variant(void *value);
void* g_variant_new_int32(int32_t value);
void* g_variant_new_strv(const char * const *strv, gssize length);
void* g_variant_new_string(const char *string);
void* g_variant_new_boolean(gboolean value);
void* g_variant_new_uint32(uint32_t value);
void* g_variant_builder_end(GVariantBuilder *builder);

#define g_auto(type) type
#define g_autoptr(type) type*