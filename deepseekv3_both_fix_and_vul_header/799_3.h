#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned char GifByteType;
typedef unsigned char GifPixelType;
typedef int GifRecordType;

#define GIF_ERROR 1
#define D_GIF_ERR_NOT_ENOUGH_MEM 2
#define IMAGE_DESC_RECORD_TYPE 1
#define EXTENSION_RECORD_TYPE 2
#define TERMINATE_RECORD_TYPE 3

typedef struct SavedImage {
    struct {
        int Top;
        int Left;
    } ImageDesc;
} SavedImage;

typedef struct GifFileType {
    struct {
        int Width;
        int Height;
        int Top;
        int Left;
        bool Interlace;
    } Image;
    int SWidth;
    int SHeight;
    int ImageCount;
    int Error;
    SavedImage *SavedImages;
} GifFileType;

typedef struct GifInfo {
    GifFileType *gifFilePtr;
    uint_fast32_t originalWidth;
    uint_fast32_t originalHeight;
    uint_fast32_t rasterSize;
    GifPixelType *rasterBits;
    uint_fast32_t sampleSize;
    void (*rewindFunction)(struct GifInfo*);
} GifInfo;

int DGifGetRecordType(GifFileType*, GifRecordType*);
int DGifGetImageDesc(GifFileType*, bool);
int DGifGetLine(GifFileType*, GifPixelType*, int);
int DGifGetCodeNext(GifFileType*, GifByteType**);
int DGifGetExtension(GifFileType*, int*, GifByteType**);
int DGifGetExtensionNext(GifFileType*, GifByteType**);
bool updateGCB(GifInfo*, uint_fast32_t*);
int readExtensions(int, GifByteType*, GifInfo*);

void *reallocarray(void *ptr, size_t nmemb, size_t size);