#include <stdbool.h>

#define PIPE_TEXTURE_3D 3

struct pipe_resource {
   unsigned width0;
   unsigned height0;
   unsigned depth0;
   unsigned last_level;
   unsigned array_size;
   unsigned target;
};

struct vrend_resource {
   struct pipe_resource base;
};

struct pipe_box {
   int x;
   int y;
   int z;
   int width;
   int height;
   int depth;
};

struct vrend_transfer_info {
   unsigned level;
   const struct pipe_box *box;
};

static inline unsigned u_minify(unsigned size, unsigned level) {
   return size >> level;
}