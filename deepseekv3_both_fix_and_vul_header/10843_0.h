#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define ZZIP_PACKAGE ""
#define ZZIP_VERSION ""
#define EXIT_OK 0
#define EXIT_ERRORS 1
#define DBG2(fmt, ...)
#define DBG3(fmt, ...)

typedef struct ZZIP_MEM_DISK ZZIP_MEM_DISK;
typedef struct ZZIP_MEM_ENTRY ZZIP_MEM_ENTRY;

#define _zzip_FNM_NOESCAPE 0
#define _zzip_FNM_PATHNAME 0
#define _zzip_FNM_PERIOD 0

static ZZIP_MEM_DISK* zzip_mem_disk_open(const char*);
static ZZIP_MEM_ENTRY* zzip_mem_disk_findfirst(ZZIP_MEM_DISK*);
static ZZIP_MEM_ENTRY* zzip_mem_disk_findnext(ZZIP_MEM_DISK*, ZZIP_MEM_ENTRY*);
static char* zzip_mem_entry_to_name(ZZIP_MEM_ENTRY*);
static void unzzip_mem_disk_cat_file(ZZIP_MEM_DISK*, char*, FILE*);
static ZZIP_MEM_ENTRY* zzip_mem_disk_findmatch(ZZIP_MEM_DISK*, const char*, ZZIP_MEM_ENTRY*, int, int);
static void unzzip_mem_entry_fprint(ZZIP_MEM_DISK*, ZZIP_MEM_ENTRY*, FILE*);
static int _zzip_fnmatch(const char*, const char*, int);
static FILE* create_fopen(const char*, const char*, int);
static int exitcode(int);