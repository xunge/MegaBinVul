#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>

typedef enum {
  PROP_END,
  PROP_ACTIVE_LAYER,
  PROP_FLOATING_SELECTION,
  PROP_OPACITY,
  PROP_VISIBLE,
  PROP_LINKED,
  PROP_PRESERVE_TRANSPARENCY,
  PROP_APPLY_MASK,
  PROP_EDIT_MASK,
  PROP_SHOW_MASK,
  PROP_OFFSETS,
  PROP_MODE,
  PROP_TATTOO,
  PROP_PARASITES
} PropType;

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum {
  CorruptImageError,
  NoCompositeOp
} ExceptionType;

typedef struct _ImageInfo {
  size_t number_scenes;
  size_t scene;
} ImageInfo;

typedef struct _ExceptionInfo {
  int dummy;
} ExceptionInfo;

typedef struct _Color {
  unsigned char opacity;
} Color;

typedef struct _Image {
  char *filename;
  ExceptionInfo *exception;
  size_t width;
  size_t height;
  size_t columns;
  size_t rows;
  struct _Image *image;
  Color background_color;
  int compose;
  struct _Image *mask;
} Image;

typedef struct _XCFDocInfo {
  size_t number_layers;
} XCFDocInfo;

typedef struct _XCFLayerInfo {
  size_t width;
  size_t height;
  size_t type;
  char name[256];
  int active;
  size_t floating_offset;
  size_t alpha;
  MagickBooleanType visible;
  MagickBooleanType linked;
  MagickBooleanType preserve_trans;
  MagickBooleanType apply_mask;
  MagickBooleanType edit_mask;
  MagickBooleanType show_mask;
  ssize_t offset_x;
  ssize_t offset_y;
  size_t mode;
  Image *image;
} XCFLayerInfo;

typedef off_t MagickOffsetType;

extern void ResetMagickMemory(void *, int, size_t);
extern unsigned long ReadBlobMSBLong(Image *);
extern char *ReadBlobStringWithLongSize(Image *, char *, size_t);
extern MagickBooleanType EOFBlob(Image *);
extern void ThrowBinaryException(ExceptionType, const char *, const char *);
extern ssize_t ReadBlobMSBSignedLong(Image *);
extern MagickBooleanType DiscardBlobBytes(Image *, size_t);
extern void ThrowFileException(ExceptionInfo **, ExceptionType, const char *, const char *);
extern Image *CloneImage(Image *, size_t, size_t, MagickBooleanType, ExceptionInfo **);
extern void InitXCFImage(XCFLayerInfo *);
extern int GIMPBlendModeToCompositeOperator(size_t);
extern MagickOffsetType SeekBlob(Image *, MagickOffsetType, int);
extern void *ThrowMagickException(ExceptionInfo **, const char *, ExceptionType, const char *, const char *, const char *);
extern int load_hierarchy(Image *, XCFDocInfo *, XCFLayerInfo *);
extern size_t MagickMin(size_t, size_t);
extern ssize_t ReadBlob(Image *, size_t, unsigned char *);
extern unsigned char ScaleCharToQuantum(unsigned char);
extern void SetImageBackgroundColor(Image *);
extern const char *GetMagickModule(void);
extern void InheritException(ExceptionInfo **, ExceptionInfo **);
extern Image *DestroyImageList(Image *);
extern MagickBooleanType SetImageExtent(Image *, size_t, size_t);