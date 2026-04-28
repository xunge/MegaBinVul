#include <stddef.h>
#include <sys/types.h>

typedef unsigned char Quantum;
typedef unsigned char IndexPacket;
typedef unsigned char PixelPacket;
typedef int MagickBooleanType;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _Image Image;
typedef double MagickFloatType;
typedef double MagickRealType;

#define MagickFalse 0
#define QuantumRange 255
#define MSBEndian 0

struct _Image {
    size_t columns;
    size_t depth;
};

Image *GetAuthenticPixels(Image *, size_t, ssize_t, size_t, size_t, ExceptionInfo *);
IndexPacket *GetAuthenticIndexQueue(Image *);
size_t GetPSDPacketSize(Image *);
unsigned char *PushShortPixel(int, const unsigned char *, unsigned short *);
unsigned char *PushFloatPixel(int, const unsigned char *, MagickFloatType *);
void SetPSDPixel(Image *, size_t, ssize_t, size_t, Quantum, PixelPacket *, IndexPacket *, ssize_t);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
Quantum ScaleCharToQuantum(unsigned char);
Quantum ScaleShortToQuantum(unsigned short);
Quantum ClampToQuantum(MagickRealType);