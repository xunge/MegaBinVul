#include <stdbool.h>
#include <stddef.h>

#define FALSE false
#define TRUE true
#define G_FILE_ATTRIBUTE_STANDARD_TYPE "standard::type"
#define G_FILE_ATTRIBUTE_STANDARD_SYMLINK_TARGET "standard::symlink-target"
#define G_FILE_COPY_NOFOLLOW_SYMLINKS (1 << 0)
#define G_FILE_TYPE_SYMBOLIC_LINK 1
#define G_FILE_TYPE_SPECIAL 2
#define G_IO_ERROR 0
#define G_IO_ERROR_NOT_SUPPORTED 1
#define G_FILE_QUERY_INFO_NOFOLLOW_SYMLINKS (1 << 0)
#define G_FILE_CREATE_REPLACE_DESTINATION (1 << 0)
#define G_FILE_CREATE_PRIVATE (1 << 1)
#define G_FILE_COPY_OVERWRITE (1 << 1)
#define G_FILE_COPY_BACKUP (1 << 2)

typedef bool gboolean;
typedef void* gpointer;
typedef struct _GFile GFile;
typedef struct _GFileInputStream GFileInputStream;
typedef struct _GInputStream GInputStream;
typedef struct _GOutputStream GOutputStream;
typedef struct _GFileInfo GFileInfo;
typedef struct _GCancellable GCancellable;
typedef struct _GError GError;

typedef unsigned int GFileCopyFlags;
typedef unsigned int GFileAttributeType;
typedef unsigned int GFileCreateFlags;

typedef bool (*GFileProgressCallback)(size_t current_num_bytes,
                                     size_t total_num_bytes,
                                     void* user_data);

static void g_object_unref(void* object) {}
static void g_free(void* ptr) {}
static void g_clear_error(GError** error) {}
static void g_propagate_error(GError** dest, GError* src) {}
static void g_clear_object(void** object) {}
static void g_set_error_literal(GError** error, int domain, int code, const char* message) {}
static bool g_error_matches(const GError* error, int domain, int code) { return false; }
static const char* _(const char* str) { return str; }

static gboolean copy_symlink(GFile* destination,
                           GFileCopyFlags flags,
                           GCancellable* cancellable,
                           const char* target,
                           GError** error);

static GFileInputStream* open_source_for_copy(GFile* source,
                                            GFile* destination,
                                            GFileCopyFlags flags,
                                            GCancellable* cancellable,
                                            GError** error);

static gboolean build_attribute_list_for_copy(GFile* destination,
                                            GFileCopyFlags flags,
                                            char** attrs_to_read,
                                            GCancellable* cancellable,
                                            GError** error);

static gboolean btrfs_reflink_with_progress(GInputStream* in,
                                          GOutputStream* out,
                                          GFileInfo* info,
                                          GCancellable* cancellable,
                                          GFileProgressCallback progress_callback,
                                          gpointer progress_callback_data,
                                          GError** error);

static gboolean splice_stream_with_progress(GInputStream* in,
                                          GOutputStream* out,
                                          GCancellable* cancellable,
                                          GFileProgressCallback progress_callback,
                                          gpointer progress_callback_data,
                                          GError** error);

static gboolean copy_stream_with_progress(GInputStream* in,
                                        GOutputStream* out,
                                        GFile* source,
                                        GCancellable* cancellable,
                                        GFileProgressCallback progress_callback,
                                        gpointer progress_callback_data,
                                        GError** error);