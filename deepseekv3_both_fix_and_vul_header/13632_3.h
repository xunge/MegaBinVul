#include <stddef.h>
#include <stdio.h>

typedef struct _GError GError;
typedef struct _GFile GFile;
typedef struct _GFileInfo GFileInfo;
typedef struct _GList GList;
typedef struct _ThunarTransferJob ThunarTransferJob;
typedef struct _ThunarTransferNode ThunarTransferNode;
typedef struct _ThunarThumbnailCache ThunarThumbnailCache;
typedef struct _ThunarApplication ThunarApplication;

struct _GError {
    int domain;
    int code;
    char *message;
};

typedef enum {
    THUNAR_JOB_RESPONSE_RETRY,
    THUNAR_JOB_RESPONSE_SKIP
} ThunarJobResponse;

enum {
    THUNAR_TRANSFER_JOB_MOVE,
    G_IO_ERROR,
    G_IO_ERROR_NO_SPACE
};

#define THUNAR_IS_TRANSFER_JOB(job) (1)
#define G_IS_FILE(file) (1)
#define G_LIKELY(expr) (expr)
#define G_UNLIKELY(expr) (expr)
#define _thunar_return_if_fail(expr) do { if (!(expr)) return; } while (0)
#define G_FILE_ATTRIBUTE_STANDARD_DISPLAY_NAME "standard::display-name"
#define G_FILE_QUERY_INFO_NOFOLLOW_SYMLINKS (1 << 0)
#define EXO_JOB(job) ((void*)job)
#define THUNAR_JOB(job) ((void*)job)

struct _ThunarTransferNode {
    GFile *source_file;
    ThunarTransferNode *next;
    ThunarTransferNode *children;
};

struct _ThunarTransferJob {
    int type;
};

typedef char gchar;

GFile* thunar_transfer_job_copy_file(ThunarTransferJob *job, GFile *source, GFile *target, GError **error);
void thunar_thumbnail_cache_copy_file(ThunarThumbnailCache *cache, GFile *source, GFile *target);
void thunar_thumbnail_cache_delete_file(ThunarThumbnailCache *cache, GFile *file);
void thunar_transfer_node_free(ThunarTransferNode *node);
GList* thunar_g_file_list_prepend(GList *list, GFile *file);
ThunarApplication* thunar_application_get(void);
ThunarThumbnailCache* thunar_application_get_thumbnail_cache(ThunarApplication *app);
ThunarJobResponse thunar_job_ask_skip(void *job, const char *format, ...);
void exo_job_info_message(void *job, const char *format, ...);
void* exo_job_get_cancellable(void *job);
void g_object_unref(void *object);
void* g_object_ref(void *object);
char* g_file_get_basename(GFile *file);
GFile* g_file_get_child(GFile *parent, const char *path);
void g_free(void *mem);
GFileInfo* g_file_query_info(GFile *file, const char *attributes, int flags, void *cancellable, GError **error);
char* g_file_info_get_display_name(GFileInfo *info);
int g_file_delete(GFile *file, void *cancellable, GError **error);
void g_clear_error(GError **error);
void g_propagate_error(GError **dest, GError *src);