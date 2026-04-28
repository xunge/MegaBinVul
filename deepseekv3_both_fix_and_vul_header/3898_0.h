#include <stddef.h>

typedef struct tiff TIFF;
typedef void (*TIFFCloseProc)(thandle_t);
typedef int thandle_t;

struct tiff {
    TIFFCloseProc tif_closeproc;
    thandle_t tif_clientdata;
};

void TIFFCleanup(TIFF *tif);