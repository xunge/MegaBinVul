#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#define MagickPathExtent 4096
#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define MagickEpsilon 1.0e-10
#define MagickMaxBufferExtent 8192
#define DefaultSVGDensity 90.0
#define SVGDensityGeometry "90x90"
#define MaxTextExtent 4096
#define SigmaValue 0x01
#define XML_PARSE_HUGE (1<<19)

typedef unsigned char Quantum;
typedef unsigned char xmlChar;
typedef void* xmlParserInputPtr;
typedef void* xmlEntityPtr;
typedef void* xmlElementContentPtr;
typedef void* xmlEnumerationPtr;
typedef void* xmlSAXLocatorPtr;

typedef struct _Image {
    unsigned long signature;
    struct {
        double x;
        double y;
    } resolution;
    size_t columns;
    size_t rows;
    char filename[MagickPathExtent];
    char magick[MaxTextExtent];
    int debug;
    int alpha_trait;
    int ping;
    struct _Image *previous;
    struct _Image *next;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    const char *filename;
    const char *magick;
    const char *size;
    int debug;
    int ping;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
    int severity;
} ExceptionInfo;

typedef struct _SVGInfo {
    FILE *file;
    ExceptionInfo *exception;
    Image *image;
    const ImageInfo *image_info;
    struct {
        int width;
        int height;
    } bounds;
    int svgDepth;
    char *size;
    char *title;
    char *comment;
    struct {
        void *myDoc;
    } *parser;
    int width;
    int height;
} SVGInfo;

typedef struct _MemoryInfo {
    void *blob;
} MemoryInfo;

typedef struct _PixelInfo {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;
} PixelInfo;

typedef struct _GeometryInfo {
    double rho;
    double sigma;
} GeometryInfo;

typedef int MagickBooleanType;
typedef long ssize_t;
typedef long MagickOffsetType;
typedef unsigned long size_t;

enum BlendPixelTrait {
    UndefinedPixelTrait,
    BlendPixelTrait
};

enum ErrorException {
    UndefinedException,
    WarningException = 300,
    ErrorException = 400
};

enum FileOpenError {
    FileOpenError
};

enum ResourceLimitError {
    ResourceLimitError
};

enum MissingDelegateError {
    MissingDelegateError
};

enum TraceEvent {
    TraceEvent
};

enum CoderEvent {
    CoderEvent
};

enum ReadBinaryBlobMode {
    ReadBinaryBlobMode
};

struct _xmlSAXHandler {
    void *internalSubset;
    void *isStandalone;
    void *hasInternalSubset;
    void *hasExternalSubset;
    void *resolveEntity;
    void *getEntity;
    void *entityDecl;
    void *notationDecl;
    void *attributeDecl;
    void *elementDecl;
    void *unparsedEntityDecl;
    void *setDocumentLocator;
    void *startDocument;
    void *endDocument;
    void *startElement;
    void *endElement;
    void *reference;
    void *characters;
    void *ignorableWhitespace;
    void *processingInstruction;
    void *comment;
    void *warning;
    void *error;
    void *fatalError;
    void *getParameterEntity;
    void *cdataBlock;
    void *externalSubset;
};

typedef struct _xmlSAXHandler xmlSAXHandler;
typedef struct _xmlSAXHandler *xmlSAXHandlerPtr;
typedef struct _xmlParserCtxt xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;
typedef struct _xmlDoc xmlDoc;
typedef xmlDoc *xmlDocPtr;

static void SVGInternalSubset(void *ctx, const xmlChar *name, const xmlChar *ExternalID, const xmlChar *SystemID) {}
static int SVGIsStandalone(void *ctx) { return 0; }
static int SVGHasInternalSubset(void *ctx) { return 0; }
static int SVGHasExternalSubset(void *ctx) { return 0; }
static xmlParserInputPtr SVGResolveEntity(void *ctx, const xmlChar *publicId, const xmlChar *systemId) { return NULL; }
static xmlEntityPtr SVGGetEntity(void *ctx, const xmlChar *name) { return NULL; }
static void SVGEntityDeclaration(void *ctx, const xmlChar *name, int type, const xmlChar *publicId, const xmlChar *systemId, xmlChar *content) {}
static void SVGNotationDeclaration(void *ctx, const xmlChar *name, const xmlChar *publicId, const xmlChar *systemId) {}
static void SVGAttributeDeclaration(void *ctx, const xmlChar *elem, const xmlChar *name, int type, int def, const xmlChar *defaultValue, xmlEnumerationPtr tree) {}
static void SVGElementDeclaration(void *ctx, const xmlChar *name, int type, xmlElementContentPtr content) {}
static void SVGUnparsedEntityDeclaration(void *ctx, const xmlChar *name, const xmlChar *publicId, const xmlChar *systemId, const xmlChar *notationName) {}
static void SVGSetDocumentLocator(void *ctx, xmlSAXLocatorPtr loc) {}
static void SVGStartDocument(void *ctx) {}
static void SVGEndDocument(void *ctx) {}
static void SVGStartElement(void *ctx, const xmlChar *name, const xmlChar **atts) {}
static void SVGEndElement(void *ctx, const xmlChar *name) {}
static void SVGReference(void *ctx, const xmlChar *name) {}
static void SVGCharacters(void *ctx, const xmlChar *ch, int len) {}
static void SVGIgnorableWhitespace(void *ctx, const xmlChar *ch, int len) {}
static void SVGProcessingInstructions(void *ctx, const xmlChar *target, const xmlChar *data) {}
static void SVGComment(void *ctx, const xmlChar *value) {}
static void SVGWarning(void *ctx, const char *msg, ...) {}
static void SVGError(void *ctx, const char *msg, ...) {}
static xmlEntityPtr SVGGetParameterEntity(void *ctx, const xmlChar *name) { return NULL; }
static void SVGCDataBlock(void *ctx, const xmlChar *value, int len) {}
static void SVGExternalSubset(void *ctx, const xmlChar *name, const xmlChar *ExternalID, const xmlChar *SystemID) {}

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
int OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
Image *DestroyImage(Image *);
int ParseGeometry(const char *, GeometryInfo *);
int LocaleCompare(const char *, const char *);
Image *RenderSVGImage(const ImageInfo *, Image *, ExceptionInfo *);
void ThrowReaderException(int, const char *);
void *AcquireQuantumMemory(size_t, size_t);
void *RelinquishMagickMemory(void *);
char *GetImageOption(const ImageInfo *, const char *);
int IsStringTrue(const char *);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
int SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
void SetImageBackgroundColor(Image *, ExceptionInfo *);
void GetPixelInfo(Image *, PixelInfo *);
unsigned char *GetAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
int SyncAuthenticPixels(Image *, ExceptionInfo *);
int SetImageProgress(Image *, const char *, MagickOffsetType, size_t);
void CloseBlob(Image *);
Image *GetFirstImageInList(Image *);
Image *GetNextImageInList(Image *);
void CopyMagickString(char *, const char *, size_t);
void SetImageProperty(Image *, const char *, const char *, ExceptionInfo *);
SVGInfo *AcquireSVGInfo(void);
SVGInfo *DestroySVGInfo(SVGInfo *);
int AcquireUniqueFileResource(char *);
void RelinquishUniqueFileResource(const char *);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
ImageInfo *CloneImageInfo(const ImageInfo *);
void SetImageInfoBlob(ImageInfo *, void *, size_t);
void FormatLocaleString(char *, size_t, const char *, ...);
Image *ReadImage(ImageInfo *, ExceptionInfo *);
ImageInfo *DestroyImageInfo(ImageInfo *);
void LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);
void xmlInitParser(void);
void xmlSubstituteEntitiesDefault(int);
void *xmlCreatePushParserCtxt(xmlSAXHandlerPtr, void *, const char *, int, const char *);
void xmlCtxtUseOptions(void *, int);
int xmlParseChunk(void *, const char *, int, int);
void xmlFreeDoc(void *);
void xmlFreeParserCtxt(void *);
char *CloneString(char **, const char *);