#include <stdlib.h>
#include <string.h>

#define MAX_NUM_PATCHES 5
#define LPC_ORDER 2
#define LPC_SCALE_FACTOR 1
#define DFRACT_BITS 32
#define FIXP_DBL int
#define FIXP_SGL short
#define FL2FXCONST_SGL(x) ((FIXP_SGL)(x * 32768))
#define FL2FXCONST_DBL(x) ((FIXP_DBL)(x * 2147483648))
#define FX_DBL2FX_SGL(x) ((FIXP_SGL)(x >> 16))
#define MAXVAL_DBL 0x7FFFFFFF
#define MINVAL_DBL 0x80000000
#define FL2FX_DBL(x) ((FIXP_DBL)(x * 2147483648))
#define INT int
#define UCHAR unsigned char

typedef struct PATCH_PARAM {
    int targetStartBand;
    int targetBandOffs;
    int sourceStartBand;
    int sourceStopBand;
    int numBandsInPatch;
} PATCH_PARAM;

typedef struct TRANSPOSER_SETTINGS {
    int nCols;
    int overlap;
    int lbStartPatching;
    int lbStopPatching;
    int noOfPatches;
    int *bwBorders;
    PATCH_PARAM *patchParam;
} TRANSPOSER_SETTINGS;

typedef struct {
    int ov_lb_scale;
    int lb_scale;
    int hb_scale;
} QMF_SCALE_FACTOR;

typedef struct {
    FIXP_DBL **lpcFilterStatesReal;
    FIXP_DBL **lpcFilterStatesImag;
    TRANSPOSER_SETTINGS *pSettings;
    FIXP_DBL *bwVectorOld;
} *HANDLE_SBR_LPP_TRANS;

typedef enum {
    INVF_OFF = 0,
    INVF_LOW_LEVEL = 1,
    INVF_HIGH_LEVEL = 2
} INVF_MODE;

typedef struct {
    FIXP_DBL r01r;
    FIXP_DBL r01i;
    FIXP_DBL r02r;
    FIXP_DBL r02i;
    FIXP_DBL r11r;
    FIXP_DBL r12r;
    FIXP_DBL r12i;
    FIXP_DBL det;
    int det_scale;
} ACORR_COEFS;

static inline int fixMin(int a, int b) { return (a < b) ? a : b; }
static inline int fixMax(int a, int b) { return (a > b) ? a : b; }
static inline FIXP_DBL fixp_abs(FIXP_DBL x) { return (x < 0) ? -x : x; }
static inline FIXP_DBL fMult(FIXP_DBL a, FIXP_DBL b) { return (FIXP_DBL)(((long long)a * b) >> 31); }
static inline FIXP_DBL fMultDiv2(FIXP_DBL a, FIXP_DBL b) { return (FIXP_DBL)(((long long)a * b) >> 32); }
static inline FIXP_DBL fPow2(FIXP_DBL x) { return fMult(x, x); }
static inline FIXP_DBL fDivNorm(FIXP_DBL num, FIXP_DBL denom, int *scale) { *scale = 0; return num / denom; }
static inline FIXP_DBL scaleValue(FIXP_DBL val, int scale) { return (scale > 0) ? val << scale : val >> -scale; }
static inline int getScalefactor(FIXP_DBL *x, int len) { return 0; }
static inline void scaleValues(FIXP_DBL *x, int len, int scale) {}
static inline void FDKmemclear(void *dst, size_t len) { memset(dst, 0, len); }
static inline void FDK_ASSERT(int expr) {}

int autoCorr2nd_real(ACORR_COEFS *ac, FIXP_DBL *real, int len);
int autoCorr2nd_cplx(ACORR_COEFS *ac, FIXP_DBL *real, FIXP_DBL *imag, int len);
void inverseFilteringLevelEmphasis(HANDLE_SBR_LPP_TRANS hLppTrans, int nInvfBands, INVF_MODE *sbr_invf_mode, INVF_MODE *sbr_invf_mode_prev, FIXP_DBL *bwVector);