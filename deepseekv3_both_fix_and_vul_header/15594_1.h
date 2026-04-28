#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>

typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef void* gpointer;
typedef char gchar;
typedef size_t gsize;
typedef struct _GString GString;
typedef struct _GFile GFile;
typedef struct _GFileOutputStream GFileOutputStream;
typedef struct _GOutputStream GOutputStream;
typedef struct _GError GError;

struct _GString {
    char *str;
    size_t len;
    size_t allocated_len;
};

typedef void* unzFile;
typedef struct {
    unzFile epubDocument;
    char* tmp_archive_dir;
} EpubDocument;

typedef struct {
    unsigned long uncompressed_size;
} unz_file_info64;

#define UNZ_OK 0
#define G_FILE_CREATE_PRIVATE 0
#define EV_DOCUMENT_ERROR 0
#define EV_DOCUMENT_ERROR_INVALID 0

#define g_autofree
#define _(x) x

GString* g_string_new(const char *init);
void g_string_free(GString *string, int free_segment);
void g_string_append_printf(GString *string, const char *format, ...);
void* g_malloc0(size_t n_bytes);
void g_free(void *mem);
char* g_strrstr(const char *haystack, const char *needle);
int g_mkdir(const char *filename, int mode);
int g_mkdir_with_parents(const char *pathname, int mode);
GFile* g_file_new_for_path(const char *path);
GFileOutputStream* g_file_create(GFile *file, int flags, void *cancellable, GError **error);
int g_output_stream_write(GOutputStream *stream, const void *buffer, size_t count, void *cancellable, GError **error);
int g_output_stream_close(GOutputStream *stream, void *cancellable, GError **error);
void g_object_unref(void *object);
char* g_file_get_relative_path(GFile *parent, GFile *descendant);
void g_set_error_literal(GError **err, int domain, int code, const char *message);
void g_critical(const char *format, ...);

int unzOpenCurrentFile(unzFile file);
int unzCloseCurrentFile(unzFile file);
int unzGetCurrentFileInfo64(unzFile file, unz_file_info64 *pfile_info, char *filename, 
                          unsigned long filename_size, void *extrafield, 
                          unsigned long extrafield_size, char *comment, 
                          unsigned long comment_size);
int unzReadCurrentFile(unzFile file, void *buf, unsigned len);