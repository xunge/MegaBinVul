#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <assert.h>
#include <inttypes.h>
#include <stdarg.h>

#define UNUSED(x) (void)(x)
#define MYSOFA_INVALID_FORMAT -1
#define MYSOFA_UNSUPPORTED_FORMAT -2
#define MYSOFA_NO_MEMORY -3
#define MYSOFA_READ_ERROR -4
#define MYSOFA_OK 0

struct READER {
    FILE *fhd;
    int recursive_counter;
    struct {
        int size_of_offsets;
    } superblock;
};

struct DATAOBJECT {
    struct MYSOFA_ATTRIBUTE *attributes;
    struct DIR *directory;
};

struct FRACTALHEAP {
    uint64_t maximum_heap_size;
    uint64_t maximum_direct_block_size;
    uint64_t maximum_size;
    uint8_t flags;
};

struct DIR {
    struct DATAOBJECT dataobject;
    struct DIR *next;
};

struct MYSOFA_ATTRIBUTE {
    char *name;
    char *value;
    struct MYSOFA_ATTRIBUTE *next;
};

static uint64_t readValue(struct READER *reader, int size);
static int dataobjectRead(struct READER *reader, struct DATAOBJECT *dataobject, char *name);
static void mylog(const char *format, ...);

#define log mylog

static void mylog(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}