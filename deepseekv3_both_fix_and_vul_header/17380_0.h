#include <stdlib.h>
#include <string.h>

typedef struct EXRVersion {
    int multipart;
    int non_image;
} EXRVersion;

typedef struct EXRHeader {
    int num_channels;
    int *pixel_types;
    int *requested_pixel_types;
    struct EXRChannelInfo *channels;
    int tiled;
    int tile_size_x;
    int tile_size_y;
} EXRHeader;

typedef struct EXRImage {
    int width;
    int height;
    unsigned char **images;
    int num_tiles;
    struct EXRTile *tiles;
} EXRImage;

typedef struct EXRTile {
    int offset_x;
    int offset_y;
    unsigned char **images;
} EXRTile;

typedef struct EXRChannelInfo {
    char name[256];
} EXRChannelInfo;

enum {
    TINYEXR_SUCCESS = 0,
    TINYEXR_ERROR_INVALID_ARGUMENT = -1,
    TINYEXR_ERROR_INVALID_DATA = -2
};

enum {
    TINYEXR_PIXELTYPE_HALF = 1,
    TINYEXR_PIXELTYPE_FLOAT = 2
};

void InitEXRHeader(EXRHeader *header);
void InitEXRImage(EXRImage *image);
int ParseEXRVersionFromFile(EXRVersion *version, const char *filename);
int ParseEXRHeaderFromFile(EXRHeader *header, EXRVersion *version, const char *filename, const char **err);
int LoadEXRImageFromFile(EXRImage *image, EXRHeader *header, const char *filename, const char **err);
void FreeEXRHeader(EXRHeader *header);
void FreeEXRImage(EXRImage *image);

namespace tinyexr {
    void SetErrorMessage(const char *msg, const char **err);
}