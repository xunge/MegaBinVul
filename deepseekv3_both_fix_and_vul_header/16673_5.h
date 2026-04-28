#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct archive archive;
typedef struct archive_entry archive_entry;
typedef void GFile;
typedef int gboolean;

typedef enum {
    AUTOAR_CONFLICT_OVERWRITE,
    AUTOAR_CONFLICT_CHANGE_DESTINATION,
    AUTOAR_CONFLICT_SKIP
} AutoarConflictAction;

typedef struct AutoarExtractor {
    int use_raw_format;
    char *source_basename;
    void *cancellable;
    void *error;
    int total_files;
    long total_size;
    int completed_files;
} AutoarExtractor;

#define g_debug printf
#define g_autoptr(x) x*
#define g_assert_nonnull(expr) if(!(expr)) abort()
#define g_assert_not_reached() abort()
#define g_clear_object(ptr) free(*(ptr)); *(ptr) = NULL
#define g_file_delete(filename, cancellable, error) (0)
#define g_file_equal(a, b) (0)
#define g_error_new(domain, code, format) NULL
#define g_cancellable_is_cancelled(cancellable) (0)

#define ARCHIVE_OK 0
#define ARCHIVE_EOF 1
#define G_IO_ERROR 0
#define G_IO_ERROR_NOT_DIRECTORY 0

int libarchive_create_read_object(int use_raw_format, void *self, struct archive **a) { return 0; }
int archive_read_next_header(struct archive *a, struct archive_entry **entry) { return 0; }
void archive_read_free(struct archive *a) {}
const char* archive_entry_pathname(struct archive_entry *entry) { return NULL; }
const char* archive_entry_hardlink(struct archive_entry *entry) { return NULL; }
int archive_entry_filetype(struct archive_entry *entry) { return 0; }
long archive_entry_size(struct archive_entry *entry) { return 0; }
void archive_read_data_skip(struct archive *a) {}