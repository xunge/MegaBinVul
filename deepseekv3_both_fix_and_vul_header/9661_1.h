#include <string.h>

typedef struct FT_Span_ {
    int x;
    int len;
    unsigned char coverage;
} FT_Span;

typedef struct FT_Bitmap_ {
    unsigned char* buffer;
    int rows;
    int pitch;
} FT_Bitmap;

typedef struct PWorker_ {
    FT_Bitmap target;
} *PWorker;

#define FT_MEM_SET(dest, val, count) memset((dest), (val), (count))