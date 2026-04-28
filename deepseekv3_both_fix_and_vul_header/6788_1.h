#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fnmatch.h>

#define EXIT_OK 0
#define EXIT_ERRORS 1
#define ZZIP_PACKAGE ""
#define ZZIP_VERSION ""

typedef struct ZZIP_DIR ZZIP_DIR;
typedef struct ZZIP_DIRENT {
    char* d_name;
} ZZIP_DIRENT;
typedef int zzip_error_t;

static int exitcode(zzip_error_t error) {
    return error == 0 ? EXIT_OK : EXIT_ERRORS;
}

static const char* zzip_strerror(zzip_error_t error) {
    return "zzip error";
}

static ZZIP_DIR* zzip_dir_open(const char* name, zzip_error_t* error) {
    *error = 0;
    return NULL;
}

static int zzip_dir_read(ZZIP_DIR* dir, ZZIP_DIRENT* entry) {
    return 0;
}

static void zzip_dir_close(ZZIP_DIR* dir) {
}

static int _zzip_fnmatch(const char* pattern, const char* string, int flags) {
    return fnmatch(pattern, string, flags);
}

static FILE* create_fopen(const char* name, const char* mode, int create) {
    return fopen(name, mode);
}

static void unzzip_cat_file(ZZIP_DIR* disk, char* name, FILE* out) {
}