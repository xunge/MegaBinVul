#include <stdint.h>

typedef unsigned char PIXEL;
typedef unsigned char uint8;
typedef int32_t int32;

typedef struct Vop {
    PIXEL *yChan;
    PIXEL *uChan;
    PIXEL *vChan;
} Vop;

typedef struct VideoDecData {
    Vop *prevVop;
    Vop *currVop;
    int width;
    int mbnum_row;
    int mbnum_col;
    int nTotalMB;
    int nMBPerRow;
    int postFilterType;
    uint8 *pstprcTypPrv;
    uint8 *pstprcTypCur;
} VideoDecData;

void PutSKIPPED_MB(PIXEL *dst, PIXEL *src, int width);
void PutSKIPPED_B(PIXEL *dst, PIXEL *src, int width);