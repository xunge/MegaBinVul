#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/mman.h>
#include <unistd.h>

#define ZZIP_CORRUPTED -1
#define ZZIP_DIRSIZE -2
#define ZZIP_DIR_SEEK -3
#define ZZIP_DIR_READ -4
#define USE_MMAP 1
#define _255 255
#define SEEK_SET 0

#define HINT3(...)
#define HINT4(...) 
#define HINT5(...)
#define NOTE2(...)
#define FAIL3(...)
#define FAIL4(...)

struct _disk_trailer {
    /* placeholder for trailer structure */
};

struct zzip_disk_entry {
    uint32_t magic;
    uint32_t crc32;
    uint32_t csize;
    uint32_t usize;
    uint32_t offset;
    uint16_t compr;
    uint16_t extras;
    uint16_t comment;
    uint16_t namlen;
};

struct zzip_dir_hdr {
    uint32_t d_crc32;
    uint32_t d_csize;
    uint32_t d_usize;
    uint32_t d_off;
    uint16_t d_compr;
    uint16_t d_namlen;
    uint16_t d_reclen;
    char d_name[1];
};

typedef int64_t zzip_off64_t;

typedef struct {
    struct {
        int sys;
        int (*seeks)(int, zzip_off64_t, int);
        int (*read)(int, void*, size_t);
    } fd;
} *zzip_plugin_io_t;

static inline size_t __sizeof(struct zzip_disk_entry e) { return sizeof(e); }
static inline char* aligned4(char* p) { return (char*)(((uintptr_t)p + 3) & ~3); }

zzip_off64_t _disk_trailer_localentries(struct _disk_trailer*);
zzip_off64_t _disk_trailer_rootsize(struct _disk_trailer*);
zzip_off64_t _disk_trailer_rootseek(struct _disk_trailer*);
void __correct_rootseek(zzip_off64_t, zzip_off64_t, struct _disk_trailer*);
int zzip_disk_entry_check_magic(struct zzip_disk_entry*);
uint32_t zzip_disk_entry_get_crc32(struct zzip_disk_entry*);
uint32_t zzip_disk_entry_get_csize(struct zzip_disk_entry*);
uint32_t zzip_disk_entry_get_usize(struct zzip_disk_entry*);
uint32_t zzip_disk_entry_get_offset(struct zzip_disk_entry*);
uint16_t zzip_disk_entry_get_compr(struct zzip_disk_entry*);
uint16_t zzip_disk_entry_get_extras(struct zzip_disk_entry*);
uint16_t zzip_disk_entry_get_comment(struct zzip_disk_entry*);
uint16_t zzip_disk_entry_get_namlen(struct zzip_disk_entry*);
void __debug_dir_hdr(struct zzip_dir_hdr*);
long _zzip_getpagesize(int);
void* _zzip_mmap(int, int, zzip_off64_t, zzip_off64_t);
int _zzip_munmap(int, void*, zzip_off64_t);