#include <ctype.h>

typedef struct Font Font;
struct Font {
    int (*width)(Font*);
};

typedef struct Bitmap {
    Font *font;
} Bitmap;