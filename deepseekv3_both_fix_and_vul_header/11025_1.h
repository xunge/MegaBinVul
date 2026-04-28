#include <stdbool.h>

struct PixelFormat {
    bool trueColour;
    unsigned int bpp;
    unsigned int depth;
    unsigned int redMax;
    unsigned int greenMax;
    unsigned int blueMax;
    unsigned int redShift;
    unsigned int greenShift;
    unsigned int blueShift;
    bool is888() const;
};