#include <stdio.h>

typedef struct ZZIP_MEM_DISK ZZIP_MEM_DISK;
typedef struct ZZIP_DISK_FILE ZZIP_DISK_FILE;

ZZIP_DISK_FILE* zzip_mem_disk_fopen(ZZIP_MEM_DISK* disk, char* name);
int zzip_mem_disk_fread(void* ptr, int size, int nmemb, ZZIP_DISK_FILE* file);
int zzip_mem_disk_fclose(ZZIP_DISK_FILE* file);