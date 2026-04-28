#include <stddef.h>

typedef struct Bitmap Bitmap;

typedef struct {
    int (*puts)(Bitmap *, int, int, const char *);
} Font;

struct Bitmap {
    Font *font;
};