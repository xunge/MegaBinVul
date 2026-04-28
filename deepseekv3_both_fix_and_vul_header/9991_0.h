#include <stdlib.h>
#include <stdint.h>

#define FALSE 0
#define TRUE 1

typedef struct {
    int byte_length;
    unsigned char *data;
} WavpackMetadata;

typedef struct {
    int qmode;
    int num_channels;
} Config;

typedef struct {
    int version_five;
    int file_format;
    int channel_layout;
    unsigned char *channel_reordering;
    Config config;
} WavpackContext;