#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

typedef char char_t;
typedef unsigned int uint_t;
typedef int sint_t;

#define AUBIO_NEW(type) ((type *)malloc(sizeof(type)))
#define AUBIO_FREE(ptr) free(ptr)
#define AUBIO_ARRAY(type, size) ((type *)malloc((size) * sizeof(type)))
#define AUBIO_ERR(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define PATH_MAX 4096
#define AUBIO_WAVREAD_BUFSIZE 1024

typedef struct {
    char_t *path;
    uint_t samplerate;
    uint_t hop_size;
    FILE *fid;
    uint_t input_samplerate;
    uint_t input_channels;
    size_t seek_start;
    void *output;
    uint_t blockalign;
    uint_t bitspersample;
    uint_t duration;
    unsigned char *short_output;
    uint_t read_index;
    uint_t read_samples;
    int eof;
} aubio_source_wavread_t;

typedef struct {
    uint_t channels;
    uint_t length;
    float **data;
} fmat_t;

fmat_t *new_fmat(uint_t channels, uint_t length);
unsigned int read_little_endian(unsigned char *buf, int size);
void del_aubio_source_wavread(aubio_source_wavread_t *s);