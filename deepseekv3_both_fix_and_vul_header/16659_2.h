#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int l_int32;
typedef void* PIX;
typedef void* PIXA;
typedef struct {
    int display;
} L_REGPARAMS;

#define XS 0
#define YS 0
#define WS 0
#define HS 0
#define SIZE_X 10
#define SIZE_Y 15
#define BINTHRESH 20
#define MINCOUNT 50
#define BGVAL 200
#define SMOOTH_X 2
#define SMOOTH_Y 2
#define PIX_SET 0
#define L_INSERT 1
#define L_COPY 2
#define L_FILL_WHITE 3
#define IFF_PNG 1
#define IFF_JFIF_JPEG 2

static clock_t timer_start;

int regTestSetup(int argc, char **argv, L_REGPARAMS **rp);
int lept_mkdir(const char *path);
PIX* pixRead(const char *filename);
PIXA* pixaCreate(int n);
PIX* pixConvertRGBToGray(PIX *pixs, float rwt, float gwt, float bwt);
void pixaAddPix(PIXA *pixa, PIX *pix, int copyflag);
void pixGetDimensions(PIX *pix, l_int32 *pw, l_int32 *ph, l_int32 *pd);
void startTimer(void);
PIX* pixCreate(l_int32 width, l_int32 height, l_int32 depth);
void pixRasterop(PIX *pixd, l_int32 dx, l_int32 dy, l_int32 dw, l_int32 dh, 
                 int op, PIX *pixs, l_int32 sx, l_int32 sy);
int pixGetBackgroundGrayMap(PIX *pixs, PIX *pixim, l_int32 sx, l_int32 sy,
                           l_int32 thresh, l_int32 mincount, PIX **ppixm);
float stopTimer(void);
int regTestWritePixAndCheck(L_REGPARAMS *rp, PIX *pix, int format);
PIX* pixGetInvBackgroundMap(PIX *pixs, l_int32 bgval, l_int32 smoothx, l_int32 smoothy);
PIX* pixApplyInvBackgroundGrayMap(PIX *pixs, PIX *pixm, l_int32 sx, l_int32 sy);
PIX* pixGammaTRCMasked(PIX *pixd, PIX *pixs, PIX *pixm, float gamma, 
                      l_int32 minval, l_int32 maxval);
void pixInvert(PIX *pixd, PIX *pixs);
void pixDestroy(PIX **ppix);
int pixGetBackgroundRGBMap(PIX *pixs, PIX *pixim, PIX *pixg, l_int32 sx, l_int32 sy,
                          l_int32 thresh, l_int32 mincount, PIX **ppixmr,
                          PIX **ppixmg, PIX **ppixmb);
PIX* pixApplyInvBackgroundRGBMap(PIX *pixs, PIX *pixmr, PIX *pixmg, PIX *pixmb,
                                l_int32 sx, l_int32 sy);
PIX* pixBackgroundNorm(PIX *pixs, PIX *pixim, PIX *pixg, l_int32 sx, l_int32 sy,
                       l_int32 thresh, l_int32 mincount, l_int32 bgval,
                       l_int32 smoothx, l_int32 smoothy);
PIX* pixGammaTRC(PIX *pixd, PIX *pixs, float gamma, l_int32 minval, l_int32 maxval);
int pixFillMapHoles(PIX *pix, l_int32 w, l_int32 h, int fillflag);
PIX* pixaDisplayTiledInColumns(PIXA *pixa, int ncols, float scalefactor,
                              l_int32 spacing, l_int32 border);
void pixDisplayWithTitle(PIX *pix, l_int32 x, l_int32 y, const char *title, int dispflag);
void pixaDestroy(PIXA **ppixa);
PIX* pixaDisplayTiledAndScaled(PIXA *pixa, l_int32 outdepth, l_int32 tilewidth,
                              l_int32 ncols, l_int32 background, l_int32 spacing,
                              l_int32 border);
int pixWrite(const char *filename, PIX *pix, int format);
int regTestCleanup(L_REGPARAMS *rp);