#include <stddef.h>
#include <string.h>
#include <sys/types.h>

typedef struct _Image Image;
typedef struct _MagickPixelPacket MagickPixelPacket;

struct _Image {
    size_t columns;
    Image *next;
};

struct _MagickPixelPacket {
    // 定义MagickPixelPacket的成员
    // 由于原代码中没有使用具体成员，这里保持空结构体
};

size_t GetMagickResourceLimit(int);
void *AcquireQuantumMemory(size_t, size_t);
size_t MagickMax(size_t, size_t);
void GetMagickPixelPacket(const Image *, MagickPixelPacket *);
MagickPixelPacket **DestroyPixelThreadSet(MagickPixelPacket **);

enum {
    ThreadResource
};