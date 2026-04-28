#include <stdint.h>

#define B_SIZE 8
#define INTER_1VMASK 0x01
#define PV_POSTPROC_ON
#define PV_NO_POST_PROC 0

typedef int32_t MOT;
typedef uint8_t PIXEL;
typedef uint8_t uint8;
typedef int32_t int32;

typedef struct {
    PIXEL *yChan;
    PIXEL *uChan; 
    PIXEL *vChan;
    uint8 roundingType;
} Vop;

typedef struct {
    int mbnum;
    int nMBPerRow;
    int width;
    int height;
    int mbnum_row;
    int mbnum_col;
    int nTotalMB;
    uint8 *motX;
    uint8 *motY;
    uint8 *pstprcTypCur;
    uint8 *pstprcTypPrv;
    int postFilterType;
    struct {
        uint8 *Mode;
    } headerInfo;
    struct {
        uint8 *pred_block;
    } *mblock;
    Vop *prevVop;
    Vop *currVop;
} VideoDecData;

extern int roundtab16[];
extern void (*GetPredAdvBTable[2][2])(PIXEL*, PIXEL*, int, int);
extern void GetPredOutside(int, int, PIXEL*, PIXEL*, int, int, int, int);
extern int PV_SIGN(int);
extern int PV_ABS(int);
extern uint8 pp_semaphore_luma(int, int, uint8*, uint8*, int*, int*, int, int, int, int, int);
extern void pp_semaphore_chroma_inter(int, int, uint8*, uint8*, int, int, int, int, int32, int, uint8);