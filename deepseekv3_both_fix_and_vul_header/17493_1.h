#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <errno.h>
#include <inttypes.h>

typedef struct png_struct_def png_struct;
typedef struct png_info_def png_info;
typedef unsigned char png_byte;

typedef enum {
  MODE_RGB = 0,
  MODE_RGBA = 1
} WEBP_CSP_MODE;

typedef struct {
  uint8_t* rgba;
  int stride;
  size_t size;
} WebPRGBABuffer;

typedef struct {
  WEBP_CSP_MODE colorspace;
  int is_external_memory;
  union {
    WebPRGBABuffer RGBA;
  } u;
} WebPDecBuffer;

typedef struct {
  int use_threads;
} WebPDecoderOptions;

typedef struct {
  uint32_t width;
  uint32_t height;
  int has_alpha;
  int has_animation;
  int format;
} WebPBitstreamFeatures;

typedef struct {
  WebPBitstreamFeatures input;
  WebPDecoderOptions options;
  WebPDecBuffer output;
} WebPDecoderConfig;

typedef enum {
  VP8_STATUS_OK = 0,
  VP8_STATUS_OUT_OF_MEMORY,
  VP8_STATUS_INVALID_PARAM,
  VP8_STATUS_BITSTREAM_ERROR,
  VP8_STATUS_UNSUPPORTED_FEATURE,
  VP8_STATUS_SUSPENDED,
  VP8_STATUS_USER_ABORT,
  VP8_STATUS_NOT_ENOUGH_DATA
} VP8StatusCode;

#define PNG_ALL_FILTERS 0x08
#define PNG_LIBPNG_VER_STRING "1.6.0"

extern FILE* openr(char*);
extern FILE* openw(char*);
extern void PF(const char*, ...);
extern void PFV(const char*, ...);
extern size_t pnglen;
extern void pngwerr(png_struct*, const char*);
extern void pngwarn(png_struct*, const char*);
extern void pngwrite(png_struct*, png_byte*, size_t);
extern void pngflush(png_struct*);
extern png_struct* png_create_write_struct(const char*, void*, void(*)(png_struct*, const char*), void(*)(png_struct*, const char*));
extern png_info* png_create_info_struct(png_struct*);
extern jmp_buf* png_jmpbuf(png_struct*);
extern void png_destroy_write_struct(png_struct**, png_info**);
extern void png_set_write_fn(png_struct*, void*, void(*)(png_struct*, png_byte*, size_t), void(*)(png_struct*));
extern void png_set_filter(png_struct*, int, int);
extern void png_set_compression_level(png_struct*, int);
extern void png_set_IHDR(png_struct*, png_info*, uint32_t, uint32_t, int, int, int, int, int);
extern void png_write_info(png_struct*, png_info*);
extern void png_write_row(png_struct*, png_byte*);
extern void png_write_end(png_struct*, png_info*);
extern VP8StatusCode WebPGetFeatures(const uint8_t*, size_t, WebPBitstreamFeatures*);
extern int WebPDecodeRGBAInto(const uint8_t*, size_t, uint8_t*, size_t, int);
extern int WebPDecodeRGBInto(const uint8_t*, size_t, uint8_t*, size_t, int);
extern VP8StatusCode WebPDecode(const uint8_t*, size_t, WebPDecoderConfig*);

#define IP ip
#define OP op