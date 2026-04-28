#include <string.h>
#include <stdlib.h>

typedef struct _jpeg_compress_struct *j_compress_ptr;
typedef struct _Image Image;
typedef struct _StringInfo StringInfo;
typedef enum { MagickFalse, MagickTrue } MagickBooleanType;
typedef long ssize_t;
typedef size_t size_t;

#define XML_MARKER 0x1
#define ICC_MARKER 0x2
#define IPTC_MARKER 0x4
#define CoderWarning 1
#define CoderEvent 2
#define ICC_PROFILE "ICC_PROFILE"

struct _StringInfo {
    unsigned char *datum;
    size_t length;
};

struct _Image {
    struct _ExceptionInfo *exception;
    char *filename;
};

struct _ExceptionInfo {
    int severity;
    char *reason;
    char *description;
};

const char *GetNextImageProfile(Image *);
const StringInfo *GetImageProfile(Image *, const char *);
int LocaleCompare(const char *, const char *);
int LocaleNCompare(const char *, const char *, size_t);
void jpeg_write_marker(j_compress_ptr, int, const unsigned char *, unsigned int);
StringInfo *AcquireStringInfo(size_t);
void ResetImageProfileIterator(Image *);
void *CopyMagickMemory(void *, const void *, size_t);
void *memcpy(void *, const void *, size_t);
StringInfo *StringToStringInfo(const char *);
void ConcatenateStringInfo(StringInfo *, const StringInfo *);
void *DestroyStringInfo(StringInfo *);
void ThrowMagickException(struct _ExceptionInfo **, const char *, int, const char *, const char *);
void LogMagickEvent(int, const char *, const char *, ...);
unsigned char *GetStringInfoDatum(const StringInfo *);
size_t GetStringInfoLength(const StringInfo *);
const char *GetMagickModule(void);

#define MagickMin(a, b) ((a) < (b) ? (a) : (b))