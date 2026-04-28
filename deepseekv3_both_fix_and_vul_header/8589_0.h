#include <stdint.h>
#include <string.h>

#define THRESHOLD 0

typedef struct Imaging *Imaging;

Imaging ImagingNewBlock(const char* mode, int xsize, int ysize);
Imaging ImagingNewArray(const char* mode, int xsize, int ysize);
void ImagingError_Clear(void);