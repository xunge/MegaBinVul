#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef struct zzip_mem_entry {
    char* zz_comment;
    char* zz_name;
    void* zz_data;
    unsigned int zz_flags;
    unsigned int zz_compr;
    unsigned int zz_mktime;
    unsigned int zz_crc32;
    unsigned int zz_csize;
    unsigned int zz_usize;
    unsigned int zz_diskstart;
    unsigned int zz_filetype;
    void* zz_ext[3];
    unsigned int zz_extlen[3];
    unsigned int zz_offset;
} ZZIP_MEM_ENTRY;

typedef struct zzip_disk {
    char* endbuf;
} ZZIP_DISK;

typedef struct zzip_disk_entry ZZIP_DISK_ENTRY;
typedef struct zzip_file_header zzip_file_header;

typedef struct zzip_extra_zip64 {
    unsigned long long z_usize;
    unsigned long long z_csize;
    unsigned long long z_offset;
    unsigned int z_diskstart;
} zzip_extra_zip64;

#define ZZIP_IS_STORED 0
#define ZZIP_EXTRA_zip64 0x0001

#define ZZIP_GET64(p) (*(unsigned long long*)(p))
#define ZZIP_GET32(p) (*(unsigned int*)(p))

typedef size_t zzip_size_t;

#define debug1(msg) 

#define ___ 
#define ____

#define zzip__new__
#define _zzip_restrict

struct zzip_file_header* zzip_disk_entry_to_file_header(ZZIP_DISK* disk, ZZIP_DISK_ENTRY* entry);
char* zzip_disk_entry_strdup_comment(ZZIP_DISK* disk, ZZIP_DISK_ENTRY* entry);
char* zzip_disk_entry_strdup_name(ZZIP_DISK* disk, ZZIP_DISK_ENTRY* entry);
void* zzip_file_header_to_data(struct zzip_file_header* header);
unsigned int zzip_disk_entry_get_flags(ZZIP_DISK_ENTRY* entry);
unsigned int zzip_disk_entry_get_compr(ZZIP_DISK_ENTRY* entry);
unsigned int zzip_disk_entry_get_mktime(ZZIP_DISK_ENTRY* entry);
unsigned int zzip_disk_entry_get_crc32(ZZIP_DISK_ENTRY* entry);
unsigned int zzip_disk_entry_get_csize(ZZIP_DISK_ENTRY* entry);
unsigned int zzip_disk_entry_get_usize(ZZIP_DISK_ENTRY* entry);
unsigned int zzip_disk_entry_get_diskstart(ZZIP_DISK_ENTRY* entry);
unsigned int zzip_disk_entry_get_filetype(ZZIP_DISK_ENTRY* entry);
zzip_size_t zzip_disk_entry_get_extras(ZZIP_DISK_ENTRY* entry);
char* zzip_disk_entry_to_extras(ZZIP_DISK_ENTRY* entry);
zzip_size_t zzip_file_header_get_extras(struct zzip_file_header* header);
char* zzip_file_header_to_extras(struct zzip_file_header* header);
void* zzip_mem_entry_find_extra_block(ZZIP_MEM_ENTRY* item, int type, size_t size);
void zzip_mem_entry_free(ZZIP_MEM_ENTRY* item);