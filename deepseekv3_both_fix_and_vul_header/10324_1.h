#include <stddef.h>
#include <string.h>
#include <sys/types.h>

#define MaxTextExtent 2048
#define DDSD_CAPS 0x00000001
#define DDSD_WIDTH 0x00000004
#define DDSD_HEIGHT 0x00000002
#define DDSD_PIXELFORMAT 0x00001000
#define DDSD_LINEARSIZE 0x00080000
#define DDSD_MIPMAPCOUNT 0x00020000
#define DDSCAPS_TEXTURE 0x00001000
#define DDSCAPS_MIPMAP 0x00400000
#define DDSCAPS_COMPLEX 0x00000008
#define DDPF_FOURCC 0x00000004
#define DDPF_ALPHAPIXELS 0x00000001
#define FOURCC_DXT1 0x31545844

typedef struct _Image {
    size_t rows;
    size_t columns;
    int matte;
} Image;

void WriteBlob(Image *image, size_t count, unsigned char *data);
void WriteBlobLSBLong(Image *image, unsigned int value);
void ResetMagickMemory(void *buffer, int c, size_t count);
int Max(int a, int b);