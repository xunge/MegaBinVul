#include <stddef.h>
#include <string.h>
#include <sys/types.h>

#define MaxPixelChannels 32
#define ThreadResource 1

typedef struct _Image {
    size_t columns;
    struct _Image *next;
} Image;

typedef struct _PixelChannels {
    double channel[MaxPixelChannels];
} PixelChannels;

size_t GetMagickResourceLimit(int);
void *AcquireQuantumMemory(size_t, size_t);
PixelChannels **DestroyPixelThreadSet(PixelChannels **);
size_t MagickMax(size_t, size_t);