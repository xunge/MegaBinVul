#include <vector>
#include <cassert>
#include <cstddef>

typedef enum {
  TINYEXR_PIXELTYPE_HALF = 1,
  TINYEXR_PIXELTYPE_FLOAT = 2,
  TINYEXR_PIXELTYPE_UINT = 3
} EXRPixelType;

typedef struct {
  EXRPixelType pixel_type;
} EXRChannelInfo;