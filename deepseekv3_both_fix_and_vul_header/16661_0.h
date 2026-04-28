#include <stdio.h>
#include <stdlib.h>

typedef int l_int32;

typedef struct L_DEWARP {
    int dummy;
} L_DEWARP;

typedef struct L_DEWARPA {
    int dummy;
} L_DEWARPA;

typedef struct PIX {
    int dummy;
} PIX;

#define IFF_JFIF_JPEG 1
#define IFF_TIFF_G4 2
#define IFF_PNG 3

void setLeptDebugOK(int flag);
void lept_mkdir(const char *path);
void lept_rmdir(const char *path);
void lept_stderr(const char *msg);
PIX *pixRead(const char *filename);
PIX *pixBackgroundNormSimple(PIX *pixs, void *pixim, void *thresh);
PIX *pixConvertRGBToGray(PIX *pixs, float rwt, float gwt, float bwt);
PIX *pixThresholdToBinary(PIX *pixs, int thresh);
L_DEWARPA *dewarpaCreate(int nx, int ny, int sampling, int minlines, int maxdist);
void dewarpaUseBothArrays(L_DEWARPA *dewa, int useboth);
L_DEWARP *dewarpCreate(PIX *pixs, int pageno);
void dewarpaInsertDewarp(L_DEWARPA *dewa, L_DEWARP *dew);
void dewarpBuildPageModel(L_DEWARP *dew, const char *filename);
void dewarpaApplyDisparity(L_DEWARPA *dewa, int pageno, PIX *pixs, int grayin, int x, int y, PIX **ppixd, const char *filename);
int pixWrite(const char *filename, PIX *pix, int format);
void pixDestroy(PIX **ppix);
void dewarpaInsertRefModels(L_DEWARPA *dewa, int notests, int debug);
void dewarpaInfo(FILE *fp, L_DEWARPA *dewa);
void dewarpaDestroy(L_DEWARPA **pdewa);
void convertFilesToPdf(const char *dir, const char *substr, int res, float scalefactor, int type, int quality, const char *title, const char *fileout);