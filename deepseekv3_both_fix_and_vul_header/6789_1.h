#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fnmatch.h>

#define EXIT_OK 0
#define EXIT_ERRORS 1
#define DBG2(...)
#define DBG3(...)
#define ZZIP_PACKAGE ""
#define ZZIP_VERSION ""

typedef struct ZZIP_DIR ZZIP_DIR;
typedef struct ZZIP_DIRENT {
    char* d_name;
} ZZIP_DIRENT;

static int exitcode(int errno_val);
static int create_fopen(const char* name, const char* mode, int allow_stdout);
static int unzzip_cat_file(ZZIP_DIR* disk, const char* name, FILE* out);
static int _zzip_fnmatch(const char* pattern, const char* string, int flags);
static ZZIP_DIR* zzip_opendir(const char* name);
static ZZIP_DIRENT* zzip_readdir(ZZIP_DIR* dir);
static int zzip_closedir(ZZIP_DIR* dir);