#include <stddef.h>

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef struct {
  double x;
  double y;
} PointInfo;

typedef struct _ExceptionInfo {
  int dummy;
} ExceptionInfo;

typedef struct _Image {
  ExceptionInfo exception;
  struct _Image *previous;
  struct _Image *next;
  size_t columns;
  size_t rows;
  double x_resolution;
  double y_resolution;
  int filter;
  double blur;
} Image;

typedef struct _ImageInfo {
  MagickBooleanType adjoin;
} ImageInfo;

extern Image *NewImageList(void);
extern Image *CloneImage(const Image *, size_t, size_t, MagickBooleanType, ExceptionInfo *);
extern Image *GetNextImageInList(const Image *);
extern Image *ResizeImage(const Image *, size_t, size_t, int, double, ExceptionInfo *);
extern Image *GetFirstImageInList(const Image *);
extern Image *DestroyImageList(Image *);

extern ImageInfo *CloneImageInfo(const ImageInfo *);
extern ImageInfo *DestroyImageInfo(ImageInfo *);

extern MagickBooleanType SetImageProperty(Image *, const char *, const char *);
extern MagickBooleanType WriteTIFFImage(const ImageInfo *, Image *);

extern void AppendImageToList(Image **, Image *);