#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

typedef struct _XcfInfo XcfInfo;
typedef struct _Gimp Gimp;
typedef struct _GimpImage GimpImage;
typedef struct _GimpProgress GimpProgress;
typedef struct _GInputStream GInputStream;
typedef struct _GFile GFile;
typedef struct _GError GError;
typedef int gboolean;
typedef int gint;
typedef char gchar;
typedef uint8_t guint8;
typedef size_t gsize;

#define FALSE 0
#define TRUE 1

struct _XcfInfo {
    Gimp *gimp;
    GInputStream *input;
    void *seekable;
    int bytes_per_offset;
    GimpProgress *progress;
    GFile *file;
    int compression;
    int file_version;
};

enum {
    COMPRESS_NONE,
    G_FILE_ERROR,
    G_FILE_ERROR_FAILED
};

#define G_IS_INPUT_STREAM(x) (1)
#define G_IS_FILE(x) (1)
#define GIMP_IS_GIMP(x) (1)
#define GIMP_IS_PROGRESS(x) (1)
#define G_SEEKABLE(x) (x)
#define G_N_ELEMENTS(x) (sizeof(x)/sizeof(x[0]))
#define g_return_val_if_fail(expr, val) do { if (!(expr)) return (val); } while (0)

extern GimpImage* (*xcf_loaders[1])(Gimp*, XcfInfo*, GError**);
extern int xcf_read_int8(XcfInfo*, guint8*, int);
extern const char* gimp_file_get_utf8_name(GFile*);
extern const char* _(const char*);
extern void gimp_progress_start(GimpProgress*, gboolean, const char*, ...);
extern void gimp_progress_end(GimpProgress*);
extern void g_input_stream_close(GInputStream*, void*, void*);
extern void g_set_error(GError**, int, int, const char*, ...);
extern int g_str_has_prefix(const char*, const char*);