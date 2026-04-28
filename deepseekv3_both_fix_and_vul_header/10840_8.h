#include <stdlib.h>
#include <errno.h>

struct zzip_file_header;

struct z_stream {
    void* opaque;
    void* zalloc;
    void* zfree;
    unsigned int avail_in;
    void* next_in;
};

struct ZZIP_DISK {
    char* buffer;
    char* endbuf;
};

struct ZZIP_DISK_ENTRY {
    // dummy structure
};

struct ZZIP_DISK_FILE {
    char* buffer;
    char* endbuf;
    long avail;
    char* stored;
    struct z_stream zlib;
};

#define zzip__new__ struct
#define Z_NULL 0
#define MAX_WBITS 15
#define Z_OK 0
#define EBADMSG 74
#define ENOMEM 12
#define ___ 
#define ____

struct zzip_file_header* zzip_disk_entry_to_file_header(struct ZZIP_DISK*, struct ZZIP_DISK_ENTRY*);
long zzip_file_header_usize(struct zzip_file_header*);
int zzip_file_header_data_stored(struct zzip_file_header*);
char* zzip_file_header_to_data(struct zzip_file_header*);
unsigned int zzip_file_header_csize(struct zzip_file_header*);
int zzip_file_header_data_deflated(struct zzip_file_header*);
int inflateInit2(struct z_stream*, int);
void DBG2(const char*, int);

typedef struct ZZIP_DISK ZZIP_DISK;
typedef struct ZZIP_DISK_ENTRY ZZIP_DISK_ENTRY;
typedef struct ZZIP_DISK_FILE ZZIP_DISK_FILE;