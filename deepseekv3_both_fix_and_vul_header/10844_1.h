#include <stdio.h>
#include <errno.h>
#include <string.h>

#define ZZIP_PACKAGE ""
#define ZZIP_VERSION ""
#define EXIT_OK 0
#define DBG2(fmt, ...)
#define DBG3(fmt, ...)

typedef struct ZZIP_MEM_DISK ZZIP_MEM_DISK;
typedef struct ZZIP_MEM_ENTRY {
    long long zz_usize;
    long long zz_csize;
    unsigned zz_compr;
} ZZIP_MEM_ENTRY;

extern ZZIP_MEM_DISK* zzip_mem_disk_open(const char*);
extern ZZIP_MEM_ENTRY* zzip_mem_disk_findfirst(ZZIP_MEM_DISK*);
extern ZZIP_MEM_ENTRY* zzip_mem_disk_findnext(ZZIP_MEM_DISK*, ZZIP_MEM_ENTRY*);
extern ZZIP_MEM_ENTRY* zzip_mem_disk_findmatch(ZZIP_MEM_DISK*, const char*, ZZIP_MEM_ENTRY*, int, int);
extern char* zzip_mem_entry_to_name(ZZIP_MEM_ENTRY*);
extern int _zzip_fnmatch(const char*, const char*, int);
extern int exitcode(int);

static const char* comprlevel[] = {""};
#define _zzip_FNM_NOESCAPE 0
#define _zzip_FNM_PATHNAME 0
#define _zzip_FNM_PERIOD 0