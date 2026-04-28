#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Display Display;
typedef struct _Screen Screen;
typedef struct _XErrorEvent XErrorEvent;
typedef int (*XErrorHandler)(Display *, XErrorEvent *);
static XErrorHandler XError;

typedef unsigned long Quantum;
typedef unsigned long Colormap;
typedef unsigned long VisualID;
typedef unsigned long XID;
typedef unsigned long DPSContext;

typedef int MagickBooleanType;
#define MagickFalse 0
#define MagickTrue 1

#define MagickCoreSignature 0xabacadabUL
#define OpaqueAlpha 0UL
#define TransparentAlpha 1UL
#define BlendPixelTrait 1UL
#define DefaultResolution 72.0
#define PseudoClass 1
#define DirectClass 2
#define TraceEvent 0
#define LoadImageTag 0
#define ResourceLimitError 0
#define ReadBinaryBlobMode 0
#define AllPlanes (~0L)
#define ZPixmap 2
#define DirectColor 5
#define TrueColor 4

typedef struct _Image {
    size_t columns;
    size_t rows;
    struct {
        double x;
        double y;
    } resolution;
    MagickBooleanType ping;
    MagickBooleanType debug;
    const char *filename;
    const char *server_name;
    unsigned long signature;
    unsigned long storage_class;
    unsigned long alpha_trait;
    size_t colors;
    struct {
        Quantum red;
        Quantum green;
        Quantum blue;
    } *colormap;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    const char *filename;
    const char *server_name;
    MagickBooleanType ping;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _XResourceInfo {
    char *visual_type;
} XResourceInfo;

typedef struct _XWindowInfo {
    int dummy;
} XWindowInfo;

typedef struct _XPixelInfo {
    int dummy;
} XPixelInfo;

typedef struct _XFontStruct {
    int dummy;
} XFontStruct;

typedef struct _XStandardColormap {
    Colormap colormap;
    unsigned long red_max;
    unsigned long red_mult;
    unsigned long green_max;
    unsigned long green_mult;
    unsigned long blue_max;
    unsigned long blue_mult;
    unsigned long base_pixel;
    VisualID visualid;
    XID killid;
} XStandardColormap;

typedef struct _XImage {
    int width;
    int height;
    int xoffset;
    int format;
    char *data;
    int byte_order;
    int bitmap_unit;
    int bitmap_bit_order;
    int bitmap_pad;
    int depth;
    int bytes_per_line;
    int bits_per_pixel;
    unsigned long red_mask;
    unsigned long green_mask;
    unsigned long blue_mask;
    XID *obdata;
    struct funcs {
        void *create_image;
        void *destroy_image;
        void *get_pixel;
        void *put_pixel;
        void *sub_image;
        void *add_pixel;
    } f;
} XImage;

typedef long ssize_t;
typedef unsigned long size_t;
typedef void* Pixmap;
typedef void* XrmDatabase;
typedef void* Visual;

enum {
    dps_status_failure,
    dps_status_no_extension,
    dps_status_success
};

typedef struct _XRectangle {
    short x, y;
    unsigned short width, height;
} XRectangle;

typedef struct _XColor {
    unsigned long pixel;
    unsigned short red, green, blue;
    char flags;
    char pad;
} XColor;

typedef struct _XVisualInfo {
    Visual *visual;
    VisualID visualid;
    int screen;
    unsigned int depth;
    int klass;
    unsigned long red_mask;
    unsigned long green_mask;
    unsigned long blue_mask;
    int colormap_size;
    int bits_per_rgb;
} XVisualInfo;

// Function prototypes
void* AcquireImage(const ImageInfo*, ExceptionInfo*);
void* DestroyImage(void*);
void* DestroyImageList(void*);
void* GetFirstImageInList(void*);
void* GetBlobFileHandle(void*);
Display* XOpenDisplay(const char*);
void XSetErrorHandler(XErrorHandler);
int OpenBlob(const ImageInfo*, void*, int, ExceptionInfo*);
int CloseBlob(void*);
const char* GetClientName();
XrmDatabase XGetResourceDatabase(Display*, const char*);
void XGetResourceInfo(const ImageInfo*, XrmDatabase, const char*, XResourceInfo*);
XStandardColormap* XAllocStandardColormap();
void ThrowReaderException(int, const char*);
XVisualInfo* XBestVisualInfo(Display*, XStandardColormap*, XResourceInfo*);
float XDPSPixelsPerPoint(Screen*);
float MagickMin(double, double);
int XDPSCreatePixmapForEPSF(DPSContext, Screen*, void*, int, float, Pixmap*, XRectangle*, XRectangle*);
int XDPSImageFileIntoDrawable(DPSContext, Screen*, Pixmap, void*, int, int, XRectangle*, int, int, float, MagickBooleanType, MagickBooleanType, MagickBooleanType, int*);
XImage* XGetImage(Display*, Pixmap, int, int, unsigned int, unsigned int, unsigned long, int);
void XFreePixmap(Display*, Pixmap);
void* AcquireQuantumMemory(size_t, size_t);
void* RelinquishMagickMemory(void*);
void XDestroyImage(XImage*);
void XFreeResources(Display*, XVisualInfo*, XStandardColormap*, XPixelInfo*, XFontStruct*, XResourceInfo*, XWindowInfo*);
void XQueryColors(Display*, Colormap, XColor*, int);
int SetImageExtent(Image*, size_t, size_t, ExceptionInfo*);
Quantum* QueueAuthenticPixels(Image*, ssize_t, ssize_t, size_t, size_t, ExceptionInfo*);
Quantum ScaleShortToQuantum(unsigned short);
void SetPixelRed(Image*, Quantum, Quantum*);
void SetPixelGreen(Image*, Quantum, Quantum*);
void SetPixelBlue(Image*, Quantum, Quantum*);
size_t GetPixelChannels(const Image*);
MagickBooleanType SyncAuthenticPixels(Image*, ExceptionInfo*);
MagickBooleanType SetImageProgress(Image*, int, ssize_t, size_t);
MagickBooleanType AcquireImageColormap(Image*, size_t, ExceptionInfo*);
void SetPixelIndex(Image*, unsigned short, Quantum*);
void SyncImage(Image*, ExceptionInfo*);
void SetPixelAlpha(Image*, unsigned long, Quantum*);
void LogMagickEvent(int, const char*, const char*, const char*);
const char* GetMagickModule();
void CloneString(char**, const char*);
unsigned long XGetPixel(XImage*, int, int);
Colormap XDefaultColormap(Display*, int);
Screen* ScreenOfDisplay(Display*, int);

#define ThrowReaderException(code,message) \
    { ThrowException(exception,code,message,(const char *)NULL); return (Image *)NULL; }