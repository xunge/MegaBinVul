#include <stddef.h>
#include <string.h>

typedef size_t zzip_size_t;

typedef struct {
    unsigned avail;
    unsigned char* stored;
    unsigned char* endbuf;
    struct {
        void* next_in;
        unsigned avail_in;
        void* next_out;
        unsigned avail_out;
        zzip_size_t total_out;
    } zlib;
} ZZIP_DISK_FILE;

#define Z_NO_FLUSH 0
#define Z_OK 0
#define Z_STREAM_END 1

static int inflate(void* stream, int flush) {
    return Z_OK;
}

#define DBG1(msg)
#define DBG3(fmt, arg1, arg2)

#define ___
#define ____