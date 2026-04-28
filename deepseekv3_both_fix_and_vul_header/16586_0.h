#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

#define stdoutmark "stdout"
#define nulmark "nul"
#define ZSTD_SPARSE_DEFAULT 0

typedef struct FIO_prefs_s FIO_prefs_t;
struct FIO_prefs_s {
    int sparseFileSupport;
    int overwrite;
};

typedef struct {
    int displayLevel;
} g_display_prefs_t;
extern g_display_prefs_t g_display_prefs;

#define DISPLAYLEVEL(level, ...)
#define DISPLAY(...)
#define SET_BINARY_MODE(stream)
#define EXM_THROW(code, ...)

int UTIL_isSameFile(const char* file1, const char* file2);
int UTIL_isRegularFile(const char* filename);
void FIO_remove(const char* path);