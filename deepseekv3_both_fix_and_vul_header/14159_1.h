#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <errno.h>

#define MYSOFA_OK 0
#define MYSOFA_INVALID_FORMAT 1
#define MYSOFA_NO_MEMORY 2
#define MYSOFA_READ_ERROR 3
#define DATAOBJECT_MAX_DIMENSIONALITY 32

struct READER {
    FILE *fhd;
    struct {
        size_t size_of_offsets;
        size_t size_of_lengths;
    } superblock;
};

struct DATAOBJECT {
    void *data;
    size_t data_len;
    uint32_t datalayout_chunk[DATAOBJECT_MAX_DIMENSIONALITY];
    struct {
        int dimensionality;
        int *dimension_size;
    } ds;
};

#define UNUSED(x) (void)(x)

static uint64_t readValue(struct READER *reader, int size);
static int validAddress(struct READER *reader, uint64_t address);
static int treeRead(struct READER *reader, struct DATAOBJECT *data);
static void mylog(const char *format, ...);