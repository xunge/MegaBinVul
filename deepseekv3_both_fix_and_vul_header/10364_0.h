#include <stddef.h>

typedef struct Image Image;
typedef struct Image {
    size_t depth;
    size_t columns;
} Image;

static inline size_t GetPSDPacketSize(Image *image);