#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Image Image;
typedef struct ImageInfo ImageInfo;
typedef struct ExceptionInfo ExceptionInfo;
typedef struct LoadContext LoadContext;
typedef struct GeometryInfo GeometryInfo;
typedef struct ddjvu_pageinfo_t ddjvu_pageinfo_t;
typedef struct ddjvu_message_t ddjvu_message_t;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    DDJVU_PAGETYPE_BITONAL
} ddjvu_page_type_t;

struct Image {
    void *exception;
    size_t columns;
    size_t rows;
    float x_resolution;
    float y_resolution;
    int colorspace;
    int storage_class;
    unsigned long depth;
    int colors;
    int matte;
    int ping;
};

struct ImageInfo {
    char *density;
};

struct ExceptionInfo {
    int dummy;
};

struct LoadContext {
    void *context;
    void *document;
    void *page;
    Image *image;
};

struct GeometryInfo {
    float rho;
    float sigma;
};

struct ddjvu_pageinfo_t {
    int dpi;
    int width;
    int height;
};

struct ddjvu_message_t {
    int dummy;
};

#define DEBUG 0
#define CoderEvent 0
#define ResourceLimitError 0
#define MemoryAllocationFailed ""
#define SigmaValue 0
#define GRAYColorspace 0
#define RGBColorspace 1
#define PseudoClass 0
#define DirectClass 1

#define LogMagickEvent(a,b,c) 0
#define GetMagickModule() NULL
#define ThrowReaderException(a,b) NULL
#define AcquireImageColormap(a,b) MagickFalse
#define SetImageExtent(a,b,c) MagickFalse
#define InheritException(a,b)
#define DestroyImageList(a) NULL
#define SyncImage(a)
#define DestroyImage(a) NULL
#define ParseGeometry(a,b) 0
#define MagickMax(a,b) ((a)>(b)?(a):(b))

static int process_message(ddjvu_message_t *message) { return 0; }
static ddjvu_message_t *pump_data_until_message(LoadContext *lc, Image *image) { return NULL; }
static void get_page_image(LoadContext *lc, void *page, int x, int y, int width, int height, const ImageInfo *image_info) {}
static void ddjvu_page_release(void *page) {}
static ddjvu_page_type_t ddjvu_page_get_type(void *page) { return DDJVU_PAGETYPE_BITONAL; }
static void ddjvu_document_get_pageinfo(void *document, int pagenum, ddjvu_pageinfo_t *info) {}
static int ddjvu_page_decoding_done(void *page) { return 1; }
static void ddjvu_message_pop(void *context) {}
static ddjvu_message_t *ddjvu_message_peek(void *context) { return NULL; }
static void *ddjvu_page_create_by_pageno(void *document, int pagenum) { return NULL; }