#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t Uint8;

typedef struct SDL_Color {
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
} SDL_Color;

typedef struct SDL_Palette {
    int ncolors;
    SDL_Color *colors;
} SDL_Palette;

#define SDL_malloc malloc
#define SDL_memcmp memcmp

void SDL_OutOfMemory(void);
Uint8 SDL_FindColor(SDL_Palette *dst, Uint8 r, Uint8 g, Uint8 b, Uint8 a);