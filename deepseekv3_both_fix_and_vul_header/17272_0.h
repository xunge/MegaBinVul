#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct {
    int width;
    int height;
    int planes;
    unsigned char* bits;
} bitmap_type;

#define BITMAP_WIDTH(b) ((b).width)
#define BITMAP_HEIGHT(b) ((b).height)
#define BITMAP_PLANES(b) ((b).planes)
#define BITMAP_BITS(b) ((b).bits)

typedef int slen_t;

namespace Image {
    class Sampled {};
    class Gray : public Sampled {
    public:
        Gray(int, int, int) {}
        unsigned char* getRowbeg() { return nullptr; }
    };
    class RGB : public Sampled {
    public:
        RGB(int, int, int) {}
        unsigned char* getRowbeg() { return nullptr; }
    };
    namespace Loader {
        class UFD {};
    }
}

namespace Filter {
    class UngetFILED {
    public:
        FILE* getFILE(bool) { return nullptr; }
    };
}

namespace SimBuffer {
    class Flat {};
}

bitmap_type tga_load_image(FILE*) {
    return {0, 0, 0, nullptr};
}