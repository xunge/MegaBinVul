#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef bool gboolean;
typedef int64_t gint64;
typedef int gint;
typedef char gchar;

#define TRUE true
#define FALSE false

typedef FILE* FILE_T;

static gint64 file_tell(FILE_T fh);
static gchar* file_gets(gchar* s, gint size, FILE_T fh);
static gint file_error(FILE_T fh, gchar** err_info);