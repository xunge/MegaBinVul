#include <stdlib.h>
#include <errno.h>

typedef struct ZZIP_MEM_DISK_FILE ZZIP_MEM_DISK_FILE;
typedef struct ZZIP_MEM_DISK ZZIP_MEM_DISK;
typedef struct ZZIP_MEM_ENTRY ZZIP_MEM_ENTRY;
typedef struct ZZIP_DISK ZZIP_DISK;

struct z_stream {
    void* next_in;
    unsigned int avail_in;
    void* opaque;
    void* (*zalloc)(void*, unsigned int, unsigned int);
    void (*zfree)(void*, void*);
};

struct ZZIP_DISK {
    char* buffer;
    char* endbuf;
};

struct ZZIP_MEM_DISK {
    struct ZZIP_DISK* disk;
};

struct ZZIP_MEM_DISK_FILE {
    char* buffer;
    char* endbuf;
    long avail;
    char* stored;
    struct z_stream zlib;
};

#define zzip_off_t long
#define zzip__new__ 
#define Z_NULL 0
#define Z_OK 0
#define MAX_WBITS 15

static inline void debug2(const char* fmt, int val) {}
static inline long zzip_mem_entry_usize(ZZIP_MEM_ENTRY* entry) { return 0; }
static inline int zzip_mem_entry_data_stored(ZZIP_MEM_ENTRY* entry) { return 0; }
static inline char* zzip_mem_entry_to_data(ZZIP_MEM_ENTRY* entry) { return NULL; }
static inline unsigned int zzip_mem_entry_csize(ZZIP_MEM_ENTRY* entry) { return 0; }
static inline int zzip_mem_entry_data_deflated(ZZIP_MEM_ENTRY* entry) { return 0; }
static inline int inflateInit2(struct z_stream* strm, int windowBits) { return 0; }

typedef ZZIP_MEM_DISK_FILE ZZIP_DISK_FILE;