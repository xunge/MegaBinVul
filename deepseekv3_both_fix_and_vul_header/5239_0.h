#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

struct READER {
    FILE *fhd;
    struct {
        int size_of_offsets;
        int size_of_lengths;
    } superblock;
};

struct DATAOBJECT {
    struct {
        int dimensionality;
        int dimension_size[3];
    } ds;
    int datalayout_chunk[3];
    void *data;
};

#define MYSOFA_OK 0
#define MYSOFA_INVALID_FORMAT 1
#define MYSOFA_UNSUPPORTED_FORMAT 2
#define MYSOFA_NO_MEMORY 3
#define MYSOFA_INTERNAL_ERROR 4

#define UNUSED(x) (void)(x)

uint64_t readValue(struct READER *reader, int size);
int gunzip(size_t size, char *input, int *olen, char *output);
void log(const char *format, ...);