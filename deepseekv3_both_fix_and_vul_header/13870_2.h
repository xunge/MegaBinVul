#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef int MagickBooleanType;
#define MagickFalse 0
#define MagickTrue 1
#define MagickCoreSignature 0

typedef struct _ImageInfo {
    unsigned long signature;
    int quality;
    char *extract;
    char *sampling_factor;
    char *magick;
} ImageInfo;

typedef struct _Image {
    unsigned long signature;
    size_t columns;
    size_t rows;
    int depth;
    int colorspace;
    int alpha_trait;
    char *filename;
    const char *magick;
    MagickBooleanType debug;
} Image;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef int Quantum;
typedef int MagickOffsetType;

typedef struct {
    int width;
    int height;
    int x;
    int y;
} RectangleInfo;

#define UndefinedPixelTrait 0
#define YUVColorspace 0
#define sRGBColorspace 0
#define WriteBinaryBlobMode 0
#define TraceEvent 0
#define SaveImageTag 0
#define HeightValue 0
#define XValue 0
#define YValue 0
#define DelegateError 0

typedef enum {
    OPJ_CLRSPC_SRGB,
    OPJ_CLRSPC_GRAY,
    OPJ_CLRSPC_SYCC
} OPJ_COLOR_SPACE;

typedef struct {
    int prec;
    int bpp;
    int sgnd;
    int dx;
    int dy;
    int w;
    int h;
} opj_image_cmptparm_t;

typedef struct {
    int x0;
    int y0;
    int x1;
    int y1;
    int numcomps;
    struct {
        int prec;
        int bpp;
        int sgnd;
        int dx;
        int dy;
        int w;
        int h;
        int alpha;
        int *data;
    } *comps;
} opj_image_t;

typedef struct {
    int numresolution;
    int tcp_numlayers;
    float tcp_rates[100];
    float tcp_distoratio[100];
    int cp_disto_alloc;
    int cp_fixed_quality;
    int cp_tdx;
    int cp_tdy;
    int cp_tx0;
    int cp_ty0;
    int tile_size_on;
    int prog_order;
    int subsampling_dx;
    int subsampling_dy;
    int image_offset_x0;
    int image_offset_y0;
    char *cp_comment;
    int tcp_mct;
} opj_cparameters_t;

typedef void *opj_codec_t;
typedef void *opj_stream_t;

#define OPJ_UINT32 unsigned int
#define OPJ_TRUE 1
#define OPJ_FALSE 0
#define OPJ_CODEC_JPT 0
#define OPJ_CODEC_J2K 1
#define OPJ_CODEC_JP2 2
#define OPJ_J2K_STREAM_CHUNK_SIZE 0
#define OPJ_LRCP 0
#define OPJ_RLCP 1
#define OPJ_RPCL 2
#define OPJ_PCRL 3
#define OPJ_CPRL 4

#define QuantumRange 1.0

void *GetMagickModule(void);
void LogMagickEvent(int, void *, const char *, const char *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
const char *GetImageOption(const ImageInfo *, const char *);
int StringToInteger(const char *);
int ParseAbsoluteGeometry(const char *, RectangleInfo *);
int LocaleCompare(const char *, const char *);
const char *GetImageProperty(Image *, const char *, ExceptionInfo *);
char *ConstantString(const char *);
int IsGrayColorspace(int);
void TransformImageColorspace(Image *, int, ExceptionInfo *);
void ResetMagickMemory(void *, int, size_t);
opj_image_t *opj_image_create(OPJ_UINT32, opj_image_cmptparm_t *, OPJ_COLOR_SPACE);
void ThrowWriterException(int, const char *);
void CinemaProfileCompliance(opj_image_t *, opj_cparameters_t *);
const Quantum *GetVirtualPixels(Image *, int, ssize_t, size_t, size_t, ExceptionInfo *);
double GetPixelLuma(Image *, const Quantum *);
double GetPixelRed(Image *, const Quantum *);
double GetPixelGreen(Image *, const Quantum *);
double GetPixelBlue(Image *, const Quantum *);
double GetPixelAlpha(Image *, const Quantum *);
int GetPixelChannels(Image *);
MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, size_t);
opj_codec_t *opj_create_compress(int);
void opj_set_default_encoder_parameters(opj_cparameters_t *);
void opj_set_warning_handler(opj_codec_t *, void *, ExceptionInfo *);
void opj_set_error_handler(opj_codec_t *, void *, ExceptionInfo *);
void opj_setup_encoder(opj_codec_t *, opj_cparameters_t *, opj_image_t *);
opj_stream_t *opj_stream_create(int, int);
void opj_stream_set_read_function(opj_stream_t *, void *);
void opj_stream_set_write_function(opj_stream_t *, void *);
void opj_stream_set_seek_function(opj_stream_t *, void *);
void opj_stream_set_skip_function(opj_stream_t *, void *);
void opj_stream_set_user_data(opj_stream_t *, Image *, void *);
int opj_start_compress(opj_codec_t *, opj_image_t *, opj_stream_t *);
int opj_encode(opj_codec_t *, opj_stream_t *);
int opj_end_compress(opj_codec_t *, opj_stream_t *);
void opj_stream_destroy(opj_stream_t *);
void opj_destroy_codec(opj_codec_t *);
void opj_image_destroy(opj_image_t *);
int CloseBlob(Image *);
void JP2WarningHandler(void *, const char *, void *);
void JP2ErrorHandler(void *, const char *, void *);
void *JP2ReadHandler(void *, OPJ_UINT32, void *);
OPJ_UINT32 JP2WriteHandler(void *, OPJ_UINT32, void *);
int JP2SeekHandler(OPJ_UINT32, void *);
OPJ_UINT32 JP2SkipHandler(OPJ_UINT32, void *);