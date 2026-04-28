#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>

typedef bool gboolean;
typedef int64_t gint64;
typedef uint64_t guint64;
typedef size_t gsize;
typedef ssize_t gssize;
typedef unsigned int guint;
typedef char gchar;
typedef void* gpointer;
typedef const void* gconstpointer;

typedef struct {
    int dummy;
} GError;
typedef struct {
    int dummy;
} GCancellable;
typedef struct {
    int dummy;
} GOptionContext;
typedef struct {
    int dummy;
} GPtrArray;
typedef struct {
    int dummy;
} GKeyFile;
typedef struct {
    int dummy;
} GVariant;
typedef struct {
    int dummy;
} GOptionEntry;
typedef enum {
    G_KEY_FILE_NONE = 0
} GKeyFileFlags;

typedef enum {
    FLATPAK_KINDS_APP,
    FLATPAK_KINDS_RUNTIME
} FlatpakKinds;

typedef struct {
    int dummy;
} FlatpakDir;
typedef struct {
    int dummy;
} FlatpakDecomposed;
typedef struct {
    int dummy;
} FlatpakRemoteState;
typedef struct {
    int dummy;
} AsMetadata;
typedef struct {
    int dummy;
} AsComponent;
typedef struct {
    int dummy;
} VarCommitRef;
typedef struct {
    int dummy;
} VarMetadataRef;

#define FLATPAK_SPARSE_CACHE_KEY_ENDOFLINE "eol"
#define FLATPAK_SPARSE_CACHE_KEY_ENDOFLINE_REBASE "eol-rebase"
#define FLATPAK_BUILTIN_FLAG_STANDARD_DIRS (1 << 0)
#define GETTEXT_PACKAGE "flatpak"
#define TRUE 1
#define FALSE 0
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define FLATPAK_ESCAPE_ALLOW_NEWLINES (1 << 0)
#define FLATPAK_ESCAPE_DO_NOT_QUOTE (1 << 1)

gboolean opt_app = FALSE;
gboolean opt_runtime = FALSE;
const char *opt_arch = NULL;
gboolean opt_cached = FALSE;
gboolean opt_sideloaded = FALSE;
const char *opt_commit = NULL;
gboolean opt_show_ref = FALSE;
gboolean opt_show_commit = FALSE;
gboolean opt_show_parent = FALSE;
gboolean opt_show_metadata = FALSE;
gboolean opt_show_runtime = FALSE;
gboolean opt_show_sdk = FALSE;
gboolean opt_log = FALSE;
GOptionEntry options[] = {0};

#define g_autoptr(x) 
#define g_autofree 
#define g_assert(expr) 
#define g_printerr printf
#define g_print printf
#define g_strdup strdup
#define g_free free
#define g_steal_pointer(ptr) (ptr)

char* _(const char* str) { return (char*)str; }

static inline GOptionContext* g_option_context_new(const char* desc) { return NULL; }
static inline void g_option_context_set_translation_domain(GOptionContext* ctx, const char* domain) {}
static inline gboolean flatpak_option_context_parse(GOptionContext* ctx, GOptionEntry* entries, int* argc, char*** argv, int flags, GPtrArray** dirs, GCancellable* cancellable, GError** error) { return FALSE; }
static inline gboolean usage_error(GOptionContext* ctx, const char* msg, GError** error) { return FALSE; }
static inline gboolean flatpak_resolve_duplicate_remotes(GPtrArray* dirs, const char* remote, FlatpakDir** dir, GCancellable* cancellable, GError** error) { return FALSE; }
static inline char* flatpak_dir_get_remote_default_branch(FlatpakDir* dir, const char* remote) { return NULL; }
static inline FlatpakKinds flatpak_kinds_from_bools(gboolean app, gboolean runtime) { return FLATPAK_KINDS_APP; }
static inline gboolean flatpak_split_partial_ref_arg(const char* pref, FlatpakKinds kinds, const char* arch, const char* branch, FlatpakKinds* matched_kinds, char** id, char** match_arch, char** match_branch, GError** error) { return FALSE; }
static inline FlatpakRemoteState* get_remote_state(FlatpakDir* dir, const char* remote, gboolean cached, gboolean sideloaded, const char* arch, const char* cid, const char* commit, GError** error) { return NULL; }
static inline FlatpakDecomposed* flatpak_dir_find_remote_ref(FlatpakDir* dir, FlatpakRemoteState* state, const char* id, const char* branch, const char* default_branch, const char* arch, FlatpakKinds kinds, GCancellable* cancellable, GError** error) { return NULL; }
static inline gboolean flatpak_remote_state_lookup_ref(FlatpakRemoteState* state, const char* ref, char** commit, char** parent, guint64* timestamp, const char** subject, GError** error) { return FALSE; }
static inline GVariant* flatpak_remote_state_load_ref_commit(FlatpakRemoteState* state, FlatpakDir* dir, const char* ref, const char* commit, const char* parent, char** out_commit, GCancellable* cancellable, GError** error) { return NULL; }
static inline gboolean flatpak_remote_state_lookup_sparse_cache(FlatpakRemoteState* state, const char* ref, VarMetadataRef* cache, GError** error) { return FALSE; }
static inline const char* var_metadata_lookup_string(VarMetadataRef metadata, const char* key, const char* def) { return NULL; }
static inline guint64 var_metadata_lookup_uint64(VarMetadataRef metadata, const char* key, guint64 def) { return 0; }
static inline void flatpak_get_window_size(int* rows, int* cols) {}
static inline AsMetadata* as_metadata_new() { return NULL; }
static inline char* flatpak_decomposed_dup_id(FlatpakDecomposed* ref) { return NULL; }
static inline void flatpak_dir_load_appstream_store(FlatpakDir* dir, const char* remote, const char* id, AsMetadata* mdata, GCancellable* cancellable, GError** error) {}
static inline AsComponent* as_store_find_app(AsMetadata* mdata, const char* ref) { return NULL; }
static inline const char* as_component_get_name(AsComponent* app) { return NULL; }
static inline const char* as_component_get_summary(AsComponent* app) { return NULL; }
static inline void print_wrapped(int width, const char* fmt, ...) {}
static inline const char* as_app_get_version(AsComponent* app) { return NULL; }
static inline const char* as_component_get_project_license(AsComponent* app) { return NULL; }
static inline VarCommitRef var_commit_from_gvariant(GVariant* variant) { VarCommitRef r = {0}; return r; }
static inline const char* var_commit_get_subject(VarCommitRef commit) { return NULL; }
static inline char* ostree_commit_get_parent(GVariant* commit) { return NULL; }
static inline guint64 ostree_commit_get_timestamp(GVariant* commit) { return 0; }
static inline VarMetadataRef var_commit_get_metadata(VarCommitRef commit) { VarMetadataRef r = {0}; return r; }
static inline GKeyFile* g_key_file_new() { return NULL; }
static inline gboolean g_key_file_load_from_data(GKeyFile* key_file, const char* data, gsize length, GKeyFileFlags flags, GError** error) { return FALSE; }
static inline char* g_format_size(guint64 size) { return NULL; }
static inline char* format_timestamp(guint64 timestamp) { return NULL; }
static inline void print_aligned(int len, const char* label, const char* value) {}
static inline void print_aligned_take(int len, const char* label, char* value) {}
static inline char* ellipsize_string(const char* str, int width) { return NULL; }
static inline gboolean flatpak_decomposed_is_app(FlatpakDecomposed* ref) { return FALSE; }
static inline const char* flatpak_decomposed_get_ref(FlatpakDecomposed* ref) { return NULL; }
static inline char* flatpak_decomposed_dup_arch(FlatpakDecomposed* ref) { return NULL; }
static inline char* flatpak_decomposed_dup_branch(FlatpakDecomposed* ref) { return NULL; }
static inline char* g_key_file_get_string(GKeyFile* key_file, const char* group, const char* key, GError** error) { return NULL; }
static inline void maybe_print_space(gboolean* first) {}
static inline GVariant* g_variant_ref(GVariant* variant) { return NULL; }
static inline GVariant* g_variant_get_child_value(GVariant* variant, guint index) { return NULL; }
static inline void g_variant_lookup(GVariant* variant, const char* key, const char* format, ...) {}
static inline gboolean g_str_has_suffix(const char* str, const char* suffix) { return FALSE; }
static inline void g_variant_unref(GVariant* variant) {}
static inline const char* flatpak_decomposed_get_kind_metadata_group(FlatpakDecomposed* ref) { return NULL; }
static inline size_t g_utf8_strlen(const char* str, gssize max) { return strlen(str); }
static inline guint64 GUINT64_FROM_BE(guint64 val) { return val; }
static inline void flatpak_print_escaped_string(const char* str, int flags) {}

GOptionContext* context = NULL;
GPtrArray* dirs = NULL;
FlatpakDir* preferred_dir = NULL;
GVariant* commit_v = NULL;
FlatpakDecomposed* ref = NULL;
FlatpakRemoteState* state = NULL;
GKeyFile* metakey = NULL;
AsMetadata* mdata = NULL;
GVariant* p_commit_v = NULL;
GVariant* c_v = NULL;
GVariant* c_m = NULL;