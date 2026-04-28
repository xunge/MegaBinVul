#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fnmatch.h>

#define EXIT_WARNINGS 1
#define EXIT_ERRORS 2
#define DBG3(...)

typedef struct ZZIP_ENTRY ZZIP_ENTRY;

extern ZZIP_ENTRY* zzip_entry_findfirst(FILE* disk);
extern ZZIP_ENTRY* zzip_entry_findnext(ZZIP_ENTRY* entry);
extern char* zzip_entry_strdup_name(ZZIP_ENTRY* entry);
extern ZZIP_ENTRY* zzip_entry_findmatch(FILE* disk, const char* pattern, ZZIP_ENTRY* entry, int flags, int offset);
extern void unzzip_big_entry_fprint(ZZIP_ENTRY* entry, FILE* out);
extern int unzzip_cat_file(FILE* disk, char* name, FILE* out);
extern FILE* create_fopen(const char* name, const char* mode, int allow_stdout);
extern int exitcode(int errno_val);
extern int _zzip_fnmatch(const char* pattern, const char* string, int flags);