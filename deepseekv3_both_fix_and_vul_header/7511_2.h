#include <stdlib.h>
#include <stdint.h>

typedef uint8_t Uint8;
typedef uint16_t Uint16;
typedef uint32_t Uint32;

typedef struct {
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
} SDL_Color;

typedef struct {
    int ncolors;
    SDL_Color *colors;
} SDL_Palette;

typedef struct SDL_PixelFormat {
    Uint32 format;
    SDL_Palette *palette;
    Uint8 BytesPerPixel;
    Uint8 Rloss;
    Uint8 Gloss;
    Uint8 Bloss;
    Uint8 Aloss;
    Uint8 Rshift;
    Uint8 Gshift;
    Uint8 Bshift;
    Uint8 Ashift;
} SDL_PixelFormat;

#define SDL_malloc malloc
#define SDL_OutOfMemory() exit(1)

#define ASSEMBLE_RGBA(pixel, bpp, fmt, R, G, B, A) \
    do { \
        Uint32 _pixel = ((R >> fmt->Rloss) << fmt->Rshift) | \
                        ((G >> fmt->Gloss) << fmt->Gshift) | \
                        ((B >> fmt->Bloss) << fmt->Bshift) | \
                        ((A >> fmt->Aloss) << fmt->Ashift); \
        switch (bpp) { \
            case 1: \
                *(Uint8 *)(pixel) = (Uint8)_pixel; \
                break; \
            case 2: \
                *(Uint16 *)(pixel) = (Uint16)_pixel; \
                break; \
            case 3: \
                ((Uint8 *)(pixel))[0] = (Uint8)_pixel; \
                ((Uint8 *)(pixel))[1] = (Uint8)(_pixel >> 8); \
                ((Uint8 *)(pixel))[2] = (Uint8)(_pixel >> 16); \
                break; \
            case 4: \
                *(Uint32 *)(pixel) = _pixel; \
                break; \
        } \
    } while (0)