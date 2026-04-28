#include <stddef.h>

typedef struct ZZIP_DISK ZZIP_DISK;
typedef struct ZZIP_MEM_DISK ZZIP_MEM_DISK;

#define zzip__new__
#define ___
#define ____

extern ZZIP_DISK* zzip_disk_buffer(char* buffer, size_t buflen);
extern ZZIP_MEM_DISK* zzip_mem_disk_new();
extern int zzip_mem_disk_load(ZZIP_MEM_DISK* dir, ZZIP_DISK* disk);
extern void debug2(const char* format, ...);