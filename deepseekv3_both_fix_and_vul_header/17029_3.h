#include <stdint.h>
#include <assert.h>
#include <stddef.h>

typedef int64_t tmsize_t;
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef int16_t int16;
typedef uint32_t uInt;

typedef struct {
    void *next_in;
    unsigned int avail_in;
    unsigned char *next_out;
    unsigned int avail_out;
    char *msg;
} z_stream;

#define Z_OK 0
#define Z_STREAM_END 1
#define Z_DATA_ERROR (-3)
#define Z_PARTIAL_FLUSH 1

typedef struct {
    int user_datafmt;
    int stride;
    uint16_t *tbuf;
    size_t tbuf_size;
    z_stream stream;
    float *ToLinearF;
    uint16_t *ToLinear16;
    unsigned char *ToLinear8;
} PixarLogState;

typedef struct {
    uint16_t td_bitspersample;
    uint32_t td_imagewidth;
} TIFFDirectory;

typedef struct {
    TIFFDirectory tif_dir;
    void *tif_clientdata;
    uint32_t tif_row;
    uint64_t tif_flags;
} TIFF;

#define TIFF_SWAB 0
#define TIFF_UINT64_FORMAT "lu"
#define TIFF_UINT64_T unsigned long

#define PIXARLOGDATAFMT_FLOAT 0
#define PIXARLOGDATAFMT_16BIT 1
#define PIXARLOGDATAFMT_12BITPICIO 2
#define PIXARLOGDATAFMT_11BITLOG 3
#define PIXARLOGDATAFMT_8BIT 4
#define PIXARLOGDATAFMT_8BITABGR 5

static PixarLogState* DecoderState(TIFF* tif);
static void TIFFErrorExt(void* clientdata, const char* module, const char* fmt, ...);
static void TIFFSwabArrayOfShort(uint16_t* array, tmsize_t n);
static void TIFFWarningExt(void* clientdata, const char* module, const char* fmt, ...);
static void horizontalAccumulateF(uint16_t* up, tmsize_t llen, int stride, float* op, float* ToLinearF);
static void horizontalAccumulate16(uint16_t* up, tmsize_t llen, int stride, uint16_t* op, uint16_t* ToLinear16);
static void horizontalAccumulate12(uint16_t* up, tmsize_t llen, int stride, int16_t* op, float* ToLinearF);
static void horizontalAccumulate11(uint16_t* up, tmsize_t llen, int stride, uint16_t* op);
static void horizontalAccumulate8(uint16_t* up, tmsize_t llen, int stride, unsigned char* op, unsigned char* ToLinear8);
static void horizontalAccumulate8abgr(uint16_t* up, tmsize_t llen, int stride, unsigned char* op, unsigned char* ToLinear8);
static int inflate(z_stream *strm, int flush);
static int inflateSync(z_stream *strm);