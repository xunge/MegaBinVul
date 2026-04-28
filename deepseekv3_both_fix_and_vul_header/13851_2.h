#include <assert.h>
#include <string.h>
#include <sys/types.h>

typedef enum {
    MagickFalse = 0,
    MagickTrue = 1
} MagickBooleanType;

typedef struct _Image {
    int scene;
    size_t extent;
    struct _Image *next;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    const char *filename;
    unsigned int number_scenes;
    unsigned int scene;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _LoadContext {
    Image *image;
    int pages;
    void *context;
    void *document;
    int streamid;
} LoadContext;

typedef struct _ddjvu_message_t {
    union {
        struct {
            int tag;
        } m_any;
        struct {
            int streamid;
        } m_newstream;
    };
} ddjvu_message_t;

#define MagickSignature 0x1234
#define TraceEvent 0
#define CoderEvent 0
#define FileOpenError 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define ReadBinaryBlobMode 0
#define DDJVU_NEWSTREAM 0

Image *AcquireImage(const ImageInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
void ThrowReaderException(int, const char *);
void *AcquireMagickMemory(size_t);
void ResetMagickMemory(void *, int, size_t);
void RelinquishMagickMemory(void *);
void *ddjvu_context_create(const char *);
void ddjvu_cache_set_size(void *, int);
void *ddjvu_document_create(void *, const char *, int);
void ddjvu_document_set_user_data(void *, void *);
ddjvu_message_t *ddjvu_message_wait(void *);
void ddjvu_message_pop(void *);
ddjvu_message_t *ddjvu_message_peek(void *);
void ddjvu_document_release(void *);
void ddjvu_context_release(void *);
Image *NewImageList(void);
Image *ReadOneDJVUImage(LoadContext *, ssize_t, const ImageInfo *, ExceptionInfo *);
void AppendImageToList(Image **, Image *);
Image *CloneImageList(Image *, ExceptionInfo *);
size_t GetBlobSize(Image *);
void djvu_close_lc(LoadContext *);
MagickBooleanType CloseBlob(Image *);
Image *DestroyImageList(Image *);
Image *GetFirstImageInList(Image *);
int LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);
ddjvu_message_t *pump_data_until_message(LoadContext *, Image *);
void process_message(ddjvu_message_t *);