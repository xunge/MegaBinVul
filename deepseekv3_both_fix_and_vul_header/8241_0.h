#include <stdint.h>

#define gdAlphaOpaque 0
#define gdAlphaTransparent 127
#define gdAlphaMax 127

#define gdTrueColorGetAlpha(c) (((c) >> 24) & 0xFF)
#define gdTrueColorGetRed(c) (((c) >> 16) & 0xFF)
#define gdTrueColorGetGreen(c) (((c) >> 8) & 0xFF)
#define gdTrueColorGetBlue(c) ((c) & 0xFF)