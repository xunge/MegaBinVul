#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

#define MagickExport
#define restrict __restrict

typedef int MagickBooleanType;
#define MagickFalse 0
#define MagickTrue 1

typedef int64_t MagickOffsetType;
typedef uint64_t MagickSizeType;
typedef double Quantum;

#define MagickCoreSignature 0xabacadabUL
#define MaxMap 65535
#define QuantumRange 65535.0
#define ResourceLimitError 1
#define PseudoClass 1
#define SyncChannels 0x01
#define TraceEvent 0
#define CompositePixelChannel 4

typedef enum {
    UndefinedPixelChannel,
    RedPixelChannel,
    GreenPixelChannel,
    BluePixelChannel,
    AlphaPixelChannel
} PixelChannel;

typedef enum {
    UndefinedPixelTrait,
    CopyPixelTrait,
    UpdatePixelTrait = 0x01,
    BlendPixelTrait
} PixelTrait;

typedef struct _Image Image;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _CacheView CacheView;
typedef struct _PixelPacket PixelPacket;

struct _Image {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    unsigned long columns;
    unsigned long rows;
    unsigned long colors;
    PixelPacket *colormap;
    unsigned int storage_class;
    unsigned int channel_mask;
    void *progress_monitor;
};

struct _PixelPacket {
    double red;
    double green;
    double blue;
    double alpha;
};

typedef void *(*AcquireMemoryHandler)(size_t, size_t);
typedef void *(*RelinquishMemoryHandler)(void *);
typedef void (*ResetMemoryHandler)(void *, int, size_t);
typedef MagickBooleanType (*MagickProgressMonitor)(const char *, MagickOffsetType, MagickSizeType, void *);

extern AcquireMemoryHandler AcquireQuantumMemory;
extern RelinquishMemoryHandler RelinquishMagickMemory;
extern ResetMemoryHandler ResetMagickMemory;
extern size_t GetPixelChannels(const Image *);
extern PixelChannel GetPixelChannelChannel(const Image *, PixelChannel);
extern PixelTrait GetPixelChannelTraits(const Image *, PixelChannel);
extern double GetPixelIntensity(const Image *, const Quantum *);
extern unsigned int GetPixelReadMask(const Image *, const Quantum *);
extern unsigned int GetPixelRedTraits(const Image *);
extern unsigned int GetPixelGreenTraits(const Image *);
extern unsigned int GetPixelBlueTraits(const Image *);
extern unsigned int GetPixelAlphaTraits(const Image *);
extern void ThrowBinaryException(int, const char *, const char *);
extern CacheView *AcquireVirtualCacheView(Image *, ExceptionInfo *);
extern CacheView *AcquireAuthenticCacheView(Image *, ExceptionInfo *);
extern CacheView *DestroyCacheView(CacheView *);
extern const Quantum *GetCacheViewVirtualPixels(CacheView *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
extern Quantum *GetCacheViewAuthenticPixels(CacheView *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
extern MagickBooleanType SyncCacheViewAuthenticPixels(CacheView *, ExceptionInfo *);
extern MagickBooleanType SetImageProgress(Image *, const char *, MagickOffsetType, MagickSizeType);
extern MagickBooleanType AccelerateEqualizeImage(Image *, ExceptionInfo *);
extern const char *GetMagickModule(void);
extern int LogMagickEvent(int, const char *, const char *, ...);

#define ScaleQuantumToMap(x) ((unsigned long)((x)*(MaxMap+1)/QuantumRange))
#define ScaleMapToQuantum(x) ((Quantum)((x)*QuantumRange/(MaxMap+1)))
#define ClampToQuantum(x) ((Quantum)((x) < 0.0 ? 0.0 : (x) > QuantumRange ? QuantumRange : (x)))

/* Remove the 'magick_restrict' qualifier from pointer declarations */
#define magick_restrict