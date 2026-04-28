#include <stdlib.h>
#include <string.h>

#define COMMENT_LENGTH_MAX 1024
#define GIF_OK 0
#define GIF_ERROR 1
#define D_GIF_ERR_NOT_ENOUGH_MEM 2

typedef unsigned char GifByteType;

typedef struct GifFileType {
    int Error;
} GifFileType;

typedef struct GifInfo {
    char *comment;
    GifFileType *gifFilePtr;
} GifInfo;