#include <stddef.h>

typedef struct Font Font;
typedef struct Bitmap {
    Font *font;
} Bitmap;

struct Font {
    int (*height)(Font *);
};