#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>

typedef struct _pdfio_stream_s pdfio_stream_t;
typedef struct _pdfio_file_s _pdfio_file_t;

typedef enum
{
  PDFIO_FILTER_NONE,
  PDFIO_FILTER_FLATE
} pdfio_filter_t;

typedef enum
{
  _PDFIO_PREDICTOR_NONE,
  _PDFIO_PREDICTOR_TIFF2
} _pdfio_predictor_t;

typedef size_t (*pdfio_crypto_cb_t)(void *ctx, uint8_t *dst, const uint8_t *src, size_t bytes);

typedef unsigned char Bytef;
typedef unsigned int uInt;

#define Z_OK 0
#define Z_STREAM_END 1
#define Z_NO_FLUSH 0

struct z_stream_s {
    Bytef *next_in;
    uInt avail_in;
    Bytef *next_out;
    uInt avail_out;
    int data_type;
};

struct _pdfio_stream_s
{
  pdfio_filter_t filter;
  size_t remaining;
  _pdfio_file_t *pdf;
  pdfio_crypto_cb_t crypto_cb;
  void *crypto_ctx;
  _pdfio_predictor_t predictor;
  size_t pbpixel;
  size_t pbsize;
  struct z_stream_s flate;
  char cbuffer[4096];
  unsigned char psbuffer[4096];
  unsigned char prbuffer[4096];
};

extern ssize_t _pdfioFileRead(_pdfio_file_t *pdf, char *buffer, size_t bytes);
extern void _pdfioFileError(_pdfio_file_t *pdf, const char *message, ...);
extern const char *zstrerror(int error);
extern unsigned char stream_paeth(unsigned char a, unsigned char b, unsigned char c);
extern void PDFIO_DEBUG(const char *format, ...);
extern int inflate(struct z_stream_s *strm, int flush);