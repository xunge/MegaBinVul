#include <stdlib.h>
#include <string.h>

typedef struct archive archive;
typedef struct archive_entry archive_entry;

typedef struct _AutoarExtractor {
    int use_raw_format;
    void* error;
    char* source_basename;
    void* cancellable;
    int completed_files;
} AutoarExtractor;

typedef enum {
    AUTOAR_CONFLICT_OVERWRITE,
    AUTOAR_CONFLICT_CHANGE_DESTINATION,
    AUTOAR_CONFLICT_SKIP
} AutoarConflictAction;

typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef void* GFile;
#define g_autoptr(type) type*

#define ARCHIVE_OK 0
#define ARCHIVE_EOF 1

static int libarchive_create_read_object(int use_raw_format, AutoarExtractor* self, archive** a) { return 0; }
static void archive_read_free(archive* a) {}
static int archive_read_next_header(archive* a, archive_entry** entry) { return 0; }
static const char* archive_entry_pathname(archive_entry* entry) { return NULL; }
static const char* archive_entry_hardlink(archive_entry* entry) { return NULL; }
static int archive_entry_filetype(archive_entry* entry) { return 0; }
static void archive_read_data_skip(archive* a) {}

static GFile* autoar_extractor_do_sanitize_pathname(AutoarExtractor* self, const char* path) { return NULL; }
static gboolean autoar_extractor_check_file_conflict(GFile* file, int filetype) { return FALSE; }
static AutoarConflictAction autoar_extractor_signal_conflict(AutoarExtractor* self, GFile* file, GFile** new_file) { return AUTOAR_CONFLICT_SKIP; }
static void autoar_extractor_do_write_entry(AutoarExtractor* self, archive* a, archive_entry* entry, GFile* filename, GFile* hardlink) {}
static void autoar_extractor_signal_progress(AutoarExtractor* self) {}
static void* autoar_common_g_error_new_a(archive* a, const char* basename) { return NULL; }

#define g_debug(...)
#define g_assert_nonnull(expr)
#define g_clear_object(ptr) free(*(ptr)); *(ptr) = NULL
#define g_assert_not_reached() abort()
#define g_cancellable_is_cancelled(cancellable) FALSE