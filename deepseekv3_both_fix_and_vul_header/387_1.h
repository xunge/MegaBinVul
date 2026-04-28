#include <assert.h>
#include <stddef.h>

#define MagickExport
#define MagickCoreSignature 0x1234
#define MagickFalse 0
#define TraceEvent 0

typedef struct _Image Image;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _RectangleInfo RectangleInfo;

enum LayerType { CompareAnyLayer };

struct _RectangleInfo {
    int x;
    int y;
    size_t width;
    size_t height;
};

struct _Image {
    unsigned long signature;
    int debug;
    char *filename;
    size_t columns;
    size_t rows;
    struct {
        int x;
        int y;
    } page;
    unsigned long delay;
    unsigned long ticks_per_second;
    unsigned long iterations;
    Image *next;
    Image *previous;
};

struct _ExceptionInfo {
    unsigned long signature;
};

const char *GetMagickModule(void);
Image *GetFirstImageInList(Image *);
Image *GetNextImageInList(Image *);
void LogMagickEvent(unsigned int, const char *, const char *, ...);
RectangleInfo CompareImagesBounds(Image *, Image *, enum LayerType, ExceptionInfo *);
Image *DeleteImageFromList(Image **);