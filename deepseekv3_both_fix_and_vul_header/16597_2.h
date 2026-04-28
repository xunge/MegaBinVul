#include <assert.h>
#include <math.h>
#include <stddef.h>

typedef struct _ResizeFilter ResizeFilter;

struct _ResizeFilter {
  unsigned long signature;
  double blur;
  double window_support;
  double scale;
  double (*window)(double, const ResizeFilter *);
  double (*filter)(double, const ResizeFilter *);
  int window_type;
};

#define MagickCoreSignature 0xabacadabUL
#define MagickEpsilon 1.0e-10

enum {
  Box
};

#define MagickPrivate