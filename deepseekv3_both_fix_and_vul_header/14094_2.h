#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>

typedef enum {
    GIMP_GRAY,
    GIMP_RGB
} GimpImageType;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef struct {
    int code;
    char *description;
} ExceptionInfo;

typedef struct {
    size_t columns;
    size_t rows;
    char *filename;
    ExceptionInfo exception;
} Image;

typedef struct {
    GimpImageType image_type;
} XCFDocInfo;

typedef struct {
    unsigned char alpha;
} XCFLayerInfo;

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;
} PixelPacket;

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;
} XCFPixelPacket;

#define TransparentOpacity 0U
#define CorruptImageError 1
#define ResourceLimitError 2

#define ThrowBinaryException(code, reason, description) ((void)0)
#define AcquireQuantumMemory(size, element_size) malloc((size)*(element_size))
#define RelinquishMagickMemory(memory) (free(memory), NULL)
#define ScaleCharToQuantum(value) (value)
#define GetPixelRed(pixel) ((pixel)->red)
#define SetPixelRed(pixel, value) ((pixel)->red = (value))
#define SetPixelGreen(pixel, value) ((pixel)->green = (value))
#define SetPixelBlue(pixel, value) ((pixel)->blue = (value))
#define SetPixelAlpha(pixel, value) ((pixel)->alpha = (value))
#define MagickMax(x, y) ((x) > (y) ? (x) : (y))
#define ReadBlob(image, length, data) (length)
#define GetAuthenticPixels(image, x, y, columns, rows, exception) NULL
#define SyncAuthenticPixels(image, exception) MagickFalse