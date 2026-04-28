#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fnmatch.h>

#define EXIT_WARNINGS 1
#define DBG3(fmt, ...) 

typedef struct ZZIP_ENTRY ZZIP_ENTRY;

static int exitcode(int errno_val);
static int unzzip_cat_file(FILE* disk, char* name, FILE* out);
static FILE* create_fopen(char* name, char* mode, int allow_stdout);
static void unzzip_big_entry_fprint(ZZIP_ENTRY* entry, FILE* out);
static ZZIP_ENTRY* zzip_entry_findfirst(FILE* disk);
static ZZIP_ENTRY* zzip_entry_findnext(ZZIP_ENTRY* entry);
static char* zzip_entry_strdup_name(ZZIP_ENTRY* entry);
static ZZIP_ENTRY* zzip_entry_findmatch(FILE* disk, char* pattern, ZZIP_ENTRY* entry, int flags1, int flags2);
static int _zzip_fnmatch(const char* pattern, const char* string, int flags);