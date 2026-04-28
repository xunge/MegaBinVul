#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fnmatch.h>

#define ZZIP_PACKAGE ""
#define ZZIP_VERSION ""
#define EXIT_OK 0
#define EXIT_ERRORS 1
#define DBG2(fmt, ...)
#define DBG3(fmt, ...)

typedef struct ZZIP_MEM_DISK ZZIP_MEM_DISK;
typedef struct ZZIP_MEM_ENTRY ZZIP_MEM_ENTRY;

extern ZZIP_MEM_DISK* zzip_mem_disk_open(const char*);
extern ZZIP_MEM_ENTRY* zzip_mem_disk_findfirst(ZZIP_MEM_DISK*);
extern ZZIP_MEM_ENTRY* zzip_mem_disk_findnext(ZZIP_MEM_DISK*, ZZIP_MEM_ENTRY*);
extern ZZIP_MEM_ENTRY* zzip_mem_disk_findmatch(ZZIP_MEM_DISK*, const char*, ZZIP_MEM_ENTRY*, int, int);
extern char* zzip_mem_entry_to_name(ZZIP_MEM_ENTRY*);
extern void unzzip_mem_disk_cat_file(ZZIP_MEM_DISK*, const char*, FILE*);
extern void unzzip_mem_entry_fprint(ZZIP_MEM_DISK*, ZZIP_MEM_ENTRY*, FILE*);
extern FILE* create_fopen(const char*, const char*, int);
extern int exitcode(int);
extern int _zzip_fnmatch(const char*, const char*, int);