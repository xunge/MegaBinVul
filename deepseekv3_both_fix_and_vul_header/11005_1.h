#include <stdio.h>
#include <string.h>

typedef struct _ImageInfo ImageInfo;
struct _ImageInfo {
    int verbose;
    int compression;
};

typedef unsigned long png_uint_32;
typedef long png_size_t;
typedef long png_alloc_size_t;
typedef char *png_charp;
typedef void *png_struct;
typedef void *png_info;
typedef struct {
    png_charp key;
    png_charp text;
    png_size_t text_length;
    int compression;
} png_text;
typedef png_text *png_textp;

#define MagickPathExtent 4096
#define NoCompression 0
#define UndefinedCompression 1
#define PNG_LIBPNG_VER 0

int LocaleNCompare(const char *, const char *, size_t);
void ConcatenateMagickString(char *, const char *, size_t);
void CopyMagickString(char *, const char *, size_t);
int FormatLocaleString(char *, size_t, const char *, ...);
void *png_malloc(png_struct *, png_alloc_size_t);
void png_free(png_struct *, void *);
void png_set_text(png_struct *, png_info *, png_textp, int);