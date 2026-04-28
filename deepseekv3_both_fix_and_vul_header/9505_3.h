#include <stdint.h>
#include <stdbool.h>

struct SPS {
    uint32_t uiTotalMbCount;
};

struct PPS {
    uint32_t uiNumSliceGroups;
};

struct NalHeaderExt {
    uint32_t uiQualityId;
};

struct SliceHeader {
    int32_t iFirstMbInSlice;
    int32_t iSpsId;
    int32_t iPpsId;
    struct SPS* pSps;
    struct PPS* pPps;
    uint32_t uiDisableDeblockingFilterIdc;
};

struct SliceHeaderExt {
    struct SliceHeader sSliceHeader;
};

struct Slice {
    struct SliceHeaderExt sSliceHeaderExt;
    int32_t iTotalMbInCurSlice;
    int32_t eSliceType;
};

struct LayerInfo {
    struct NalHeaderExt sNalHeaderExt;
    struct Slice sSliceInLayer;
};

struct Dec {
    int32_t iSpsId;
    int32_t iPpsId;
    uint32_t uiQualityId;
    int32_t iWidthInPixel;
    int32_t iHeightInPixel;
};

struct DqLayer {
    int32_t iMbWidth;
    int32_t iMbHeight;
    int32_t iMbX;
    int32_t iMbY;
    int32_t iMbXyIndex;
    bool* pMbCorrectlyDecodedFlag;
    struct LayerInfo sLayerInfo;
    struct Dec* pDec;
};

struct Fmo {
    int32_t (*FmoNextMb)(struct Fmo*, int32_t);
};

struct WelsDecoderContext {
    struct Dec* pDec;
    int32_t iTotalNumMbRec;
    int32_t iCurSeqIntervalMaxPicWidth;
    bool bAvcBasedFlag;
    struct Fmo* pFmo;
    struct DqLayer* pCurDqLayer;
    void* sLogCtx;
};

enum {
    I_SLICE,
    P_SLICE,
    WELS_LOG_WARNING
};

typedef struct WelsDecoderContext* PWelsDecoderContext;
typedef struct DqLayer* PDqLayer;
typedef struct Slice* PSlice;
typedef struct SliceHeader* PSliceHeader;
typedef struct Fmo* PFmo;
typedef void (*PDeblockingFilterMbFunc)(PWelsDecoderContext, int32_t);

int32_t WelsTargetMbConstruction(PWelsDecoderContext);
void WelsLog(void*, int, const char*, ...);
int32_t FmoNextMb(PFmo, int32_t);
void WelsDeblockingFilterSlice(PWelsDecoderContext, PDeblockingFilterMbFunc);
void WelsDeblockingMb(PWelsDecoderContext, int32_t);