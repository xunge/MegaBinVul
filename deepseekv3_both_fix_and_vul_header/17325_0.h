#include <stdio.h>
#include <vector>
#include <cassert>

typedef struct EXRImage EXRImage;
typedef struct EXRHeader EXRHeader;

#define TINYEXR_ERROR_INVALID_ARGUMENT (-1)
#define TINYEXR_ERROR_CANT_OPEN_FILE (-2)
#define TINYEXR_ERROR_INVALID_FILE (-3)

int LoadEXRImageFromMemory(EXRImage *exr_image, const EXRHeader *exr_header, const unsigned char *memory, size_t size, const char **err);