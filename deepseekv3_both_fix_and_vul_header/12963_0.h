#include <stddef.h>
#include <sys/types.h>

typedef unsigned char Quantum;
typedef unsigned char MagickBooleanType;
typedef unsigned short MagickRealType;
typedef float MagickFloatType;

#define MagickFalse 0
#define QuantumRange 255
#define MSBEndian 1

typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _Image {
    size_t columns;
    size_t depth;
} Image;

Quantum* GetAuthenticPixels(Image*, ssize_t, ssize_t, size_t, size_t, ExceptionInfo*);
size_t GetPSDPacketSize(Image*);
void SetPSDPixel(Image*, const PixelChannel, size_t, Quantum, Quantum*, ExceptionInfo*);
size_t GetPixelChannels(Image*);
MagickBooleanType SyncAuthenticPixels(Image*, ExceptionInfo*);
const unsigned char* PushShortPixel(int, const unsigned char*, unsigned short*);
const unsigned char* PushFloatPixel(int, const unsigned char*, MagickFloatType*);

typedef int PixelChannel;

#define ScaleCharToQuantum(x) ((Quantum) (x))
#define ScaleShortToQuantum(x) ((Quantum) ((x) >> 8))
#define ClampToQuantum(x) ((Quantum) ((x) > QuantumRange ? QuantumRange : ((x) < 0 ? 0 : (x))))