#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

typedef int MagickBooleanType;
typedef int OPJ_BOOL;
typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;
typedef uint64_t OPJ_UINT64;

typedef enum {
    OPJ_CLRSPC_UNKNOWN = -1,
    OPJ_CLRSPC_UNSPECIFIED = 0,
    OPJ_CLRSPC_SRGB = 1,
    OPJ_CLRSPC_GRAY = 2,
    OPJ_CLRSPC_SYCC = 3,
    OPJ_CLRSPC_EYCC = 4,
    OPJ_CLRSPC_CMYK = 5
} OPJ_COLOR_SPACE;

typedef enum {
    OPJ_PROG_UNKNOWN = -1,
    OPJ_LRCP = 0,
    OPJ_RLCP = 1,
    OPJ_RPCL = 2,
    OPJ_PCRL = 3,
    OPJ_CPRL = 4
} OPJ_PROG_ORDER;

typedef struct {
    OPJ_UINT32 dx;
    OPJ_UINT32 dy;
    OPJ_UINT32 w;
    OPJ_UINT32 h;
    OPJ_UINT32 x0;
    OPJ_UINT32 y0;
    OPJ_UINT32 prec;
    OPJ_UINT32 bpp;
    OPJ_INT32 sgnd;
    OPJ_UINT32 resno_decoded;
    OPJ_UINT32 factor;
    OPJ_INT32 *data;
    OPJ_UINT32 alpha;
} opj_image_comp_t;

typedef struct {
    OPJ_UINT32 x0;
    OPJ_UINT32 y0;
    OPJ_UINT32 x1;
    OPJ_UINT32 y1;
    OPJ_UINT32 numcomps;
    OPJ_COLOR_SPACE color_space;
    opj_image_comp_t *comps;
} opj_image_t;

typedef struct {
    OPJ_UINT32 tx0;
    OPJ_UINT32 ty0;
    OPJ_UINT32 tdx;
    OPJ_UINT32 tdy;
    OPJ_UINT32 tw;
    OPJ_UINT32 th;
    OPJ_UINT32 numlayers;
    float tcp_rates[100];
    float tcp_distoratio[100];
    OPJ_PROG_ORDER prog_order;
} opj_tcp_t;

typedef struct {
    OPJ_UINT32 tx0;
    OPJ_UINT32 ty0;
    OPJ_UINT32 tdx;
    OPJ_UINT32 tdy;
    OPJ_UINT32 tw;
    OPJ_UINT32 th;
    OPJ_UINT32 numlayers;
    OPJ_UINT32 numresolution;
    OPJ_PROG_ORDER prog_order;
    OPJ_UINT32 subsampling_dx;
    OPJ_UINT32 subsampling_dy;
    OPJ_UINT32 image_offset_x0;
    OPJ_UINT32 image_offset_y0;
    OPJ_UINT32 tile_size_on;
    OPJ_UINT32 cp_tx0;
    OPJ_UINT32 cp_ty0;
    OPJ_UINT32 cp_tdx;
    OPJ_UINT32 cp_tdy;
    OPJ_UINT32 cp_disto_alloc;
    OPJ_UINT32 cp_fixed_quality;
    float tcp_rates[100];
    float tcp_distoratio[100];
    char *cp_comment;
    opj_tcp_t *tcps;
    OPJ_UINT32 tcp_numlayers;
    OPJ_UINT32 tcp_mct;
} opj_cparameters_t;

typedef struct {
    OPJ_UINT32 prec;
    OPJ_UINT32 bpp;
    OPJ_INT32 sgnd;
    OPJ_UINT32 dx;
    OPJ_UINT32 dy;
    OPJ_UINT32 w;
    OPJ_UINT32 h;
} opj_image_cmptparm_t;

typedef void *opj_codec_t;
typedef void *opj_stream_t;

typedef struct _ImageInfo {
    unsigned long signature;
    int quality;
    char *extract;
    char *sampling_factor;
    char *magick;
    int debug;
    char *filename;
} ImageInfo;

typedef struct _Image {
    unsigned long signature;
    size_t columns;
    size_t rows;
    int depth;
    int colorspace;
    int alpha_trait;
    char *filename;
    int debug;
} Image;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _RectangleInfo {
    int x;
    int y;
    int width;
    int height;
} RectangleInfo;

typedef unsigned long Quantum;
typedef unsigned long MagickSizeType;
typedef long MagickOffsetType;

#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define UndefinedPixelTrait 0
#define YUVColorspace 1
#define sRGBColorspace 2
#define WriteBinaryBlobMode 1
#define SaveImageTag "SaveImage"
#define TraceEvent 1
#define DelegateError 1
#define HeightValue 1
#define XValue 2
#define YValue 4
#define QuantumRange 65535

enum {
    OPJ_CODEC_JPT = 0,
    OPJ_CODEC_J2K = 1,
    OPJ_CODEC_JP2 = 2
};

#define OPJ_J2K_STREAM_CHUNK_SIZE 1024
#define OPJ_FALSE 0
#define OPJ_TRUE 1

extern void opj_set_default_encoder_parameters(opj_cparameters_t *parameters);
extern opj_image_t *opj_image_create(OPJ_UINT32 numcmpts, opj_image_cmptparm_t *cmptparms, OPJ_COLOR_SPACE clrspc);
extern void opj_image_destroy(opj_image_t *image);
extern opj_codec_t *opj_create_compress(OPJ_UINT32 format);
extern void opj_destroy_codec(opj_codec_t *codec);
extern void opj_set_warning_handler(opj_codec_t *codec, void (*handler)(const char *msg, void *client_data), void *client_data);
extern void opj_set_error_handler(opj_codec_t *codec, void (*handler)(const char *msg, void *client_data), void *client_data);
extern OPJ_BOOL opj_setup_encoder(opj_codec_t *codec, opj_cparameters_t *parameters, opj_image_t *image);
extern opj_stream_t *opj_stream_create(OPJ_UINT32 buffer_size, OPJ_BOOL p_is_input);
extern void opj_stream_destroy(opj_stream_t *stream);
extern void opj_stream_set_read_function(opj_stream_t *stream, OPJ_UINT32 (*p_function)(void *p_buffer, OPJ_UINT32 p_nb_bytes, void *p_user_data));
extern void opj_stream_set_write_function(opj_stream_t *stream, OPJ_UINT32 (*p_function)(void *p_buffer, OPJ_UINT32 p_nb_bytes, void *p_user_data));
extern void opj_stream_set_seek_function(opj_stream_t *stream, OPJ_BOOL (*p_function)(OPJ_UINT64 p_nb_bytes, void *p_user_data));
extern void opj_stream_set_skip_function(opj_stream_t *stream, OPJ_UINT64 (*p_function)(OPJ_UINT64 p_nb_bytes, void *p_user_data));
extern void opj_stream_set_user_data(opj_stream_t *stream, void *p_data, void (*p_function)(void *p_data));
extern OPJ_BOOL opj_start_compress(opj_codec_t *codec, opj_image_t *image, opj_stream_t *stream);
extern OPJ_BOOL opj_encode(opj_codec_t *codec, opj_stream_t *stream);
extern OPJ_BOOL opj_end_compress(opj_codec_t *codec, opj_stream_t *stream);

extern const char *GetImageOption(const ImageInfo *image_info, const char *option);
extern int StringToInteger(const char *value);
extern int ParseAbsoluteGeometry(const char *geometry, RectangleInfo *rectangle_info);
extern const char *GetImageProperty(const Image *image, const char *property, ExceptionInfo *exception);
extern MagickBooleanType IsGrayColorspace(int colorspace);
extern MagickBooleanType TransformImageColorspace(Image *image, int colorspace, ExceptionInfo *exception);
extern const Quantum *GetVirtualPixels(const Image *image, ssize_t x, ssize_t y, size_t columns, size_t rows, ExceptionInfo *exception);
extern double GetPixelGray(const Image *image, const Quantum *pixel);
extern double GetPixelRed(const Image *image, const Quantum *pixel);
extern double GetPixelGreen(const Image *image, const Quantum *pixel);
extern double GetPixelBlue(const Image *image, const Quantum *pixel);
extern double GetPixelAlpha(const Image *image, const Quantum *pixel);
extern size_t GetPixelChannels(const Image *image);
extern MagickBooleanType SetImageProgress(Image *image, const char *tag, MagickOffsetType offset, MagickSizeType span);
extern MagickBooleanType OpenBlob(const ImageInfo *image_info, Image *image, int mode, ExceptionInfo *exception);
extern MagickBooleanType CloseBlob(Image *image);
extern void *LogMagickEvent(int event, const char *module, const char *format, ...);
extern const char *GetMagickModule(void);
extern void ThrowWriterException(int severity, const char *reason);
extern int LocaleCompare(const char *p, const char *q);
extern void CinemaProfileCompliance(opj_image_t *image, opj_cparameters_t *parameters);
extern void JP2WarningHandler(const char *msg, void *client_data);
extern void JP2ErrorHandler(const char *msg, void *client_data);
extern OPJ_UINT32 JP2ReadHandler(void *p_buffer, OPJ_UINT32 p_nb_bytes, void *p_user_data);
extern OPJ_UINT32 JP2WriteHandler(void *p_buffer, OPJ_UINT32 p_nb_bytes, void *p_user_data);
extern OPJ_BOOL JP2SeekHandler(OPJ_UINT64 p_nb_bytes, void *p_user_data);
extern OPJ_UINT64 JP2SkipHandler(OPJ_UINT64 p_nb_bytes, void *p_user_data);