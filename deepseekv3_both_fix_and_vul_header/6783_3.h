#include <stdlib.h>
#include <errno.h>

typedef struct zzip_disk {
    void* buffer;
    void* endbuf;
} ZZIP_DISK;

typedef struct zzip_disk_entry ZZIP_DISK_ENTRY;
typedef struct zzip_disk_file ZZIP_DISK_FILE;
typedef struct zzip_file_header zzip_file_header;

struct z_stream {
    void *opaque;
    void *zalloc;
    void *zfree;
    unsigned int avail_in;
    void *next_in;
};

struct zzip_disk_file {
    void* buffer;
    void* endbuf;
    unsigned long avail;
    void* stored;
    struct z_stream zlib;
};

#define zzip__new__
#define Z_NULL 0
#define Z_OK 0
#define MAX_WBITS 15
#define ___ 
#define ____