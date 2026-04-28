#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>

typedef struct WelsDecoderContext WelsDecoderContext;
typedef struct NalUnit NalUnit;
typedef struct DqLayer DqLayer;
typedef struct Fmo Fmo;
typedef struct Slice Slice;
typedef struct SliceHeaderExt SliceHeaderExt;
typedef struct SliceHeader SliceHeader;
typedef struct BitStringAux BitStringAux;
typedef struct SPS SPS;
typedef struct PPS PPS;
typedef struct LayerInfo LayerInfo;

typedef int32_t (*PWelsDecMbCavlcFunc)(WelsDecoderContext*, NalUnit*);
typedef void (*PWelsFillCacheFunc)(WelsDecoderContext*);
typedef void (*PWelsParseModeFunc)(WelsDecoderContext*);

struct SPS {
    uint32_t uiTotalMbCount;
};

struct PPS {
    bool bConstainedIntraPredFlag;
    uint32_t uiNumSliceGroups;
    bool bEntropyCodingModeFlag;
};

struct SliceHeader {
    int32_t eSliceType;
    SPS* pSps;
    PPS* pPps;
    int32_t iFirstMbInSlice;
};

struct SliceHeaderExt {
    SliceHeader sSliceHeader;
    bool bSliceSkipFlag;
    uint32_t uiNumMbsInSlice;
};

struct Slice {
    int32_t iTotalMbInCurSlice;
    int32_t iMbSkipRun;
    SliceHeaderExt sSliceHeaderExt;
};

struct LayerInfo {
    Slice sSliceInLayer;
    PPS* pPps;
};

struct BitStringAux {
    uint8_t* pCurBuf;
    uint8_t* pStartBuf;
    int32_t iLeftBits;
    int32_t iBits;
};

struct Fmo {
    int32_t (*NextMb)(Fmo*, int32_t);
};

struct DqLayer {
    LayerInfo sLayerInfo;
    BitStringAux* pBitStringAux;
    int32_t iMbWidth;
    int32_t iMbHeight;
    int32_t iMbX;
    int32_t iMbY;
    int32_t iMbXyIndex;
    int32_t* pSliceIdc;
    bool* pResidualPredFlag;
    uint32_t uiLayerDqId;
};

struct WelsDecoderContext {
    DqLayer* pCurDqLayer;
    Fmo* pFmo;
    PWelsFillCacheFunc pFillInfoCacheIntra4x4Func;
    PWelsParseModeFunc pParseIntra4x4ModeFunc;
    PWelsParseModeFunc pParseIntra16x16ModeFunc;
    int32_t eSliceType;
    struct {
        void* sLogCtx;
    } sLogCtx;
};

#define ERR_NONE 0
#define P_SLICE 0
#define I_SLICE 1
#define WELS_LOG_WARNING 1

typedef WelsDecoderContext* PWelsDecoderContext;
typedef NalUnit* PNalUnit;
typedef DqLayer* PDqLayer;
typedef Fmo* PFmo;
typedef Slice* PSlice;
typedef SliceHeaderExt* PSliceHeaderExt;
typedef SliceHeader* PSliceHeader;
typedef BitStringAux* PBitStringAux;
typedef SPS* PSPS;
typedef PPS* PPPS;

typedef int64_t intX_t;

int32_t FmoNextMb(Fmo* pFmo, int32_t iNextMbXyIndex);
void WelsLog(void* pLogCtx, int32_t level, const char* fmt, ...);
int32_t WelsDecodeMbCavlcPSlice(WelsDecoderContext* pCtx, NalUnit* pNalCur);
int32_t WelsDecodeMbCavlcISlice(WelsDecoderContext* pCtx, NalUnit* pNalCur);
void WelsFillCacheConstrain1Intra4x4(WelsDecoderContext* pCtx);
void ParseIntra4x4ModeConstrain1(WelsDecoderContext* pCtx);
void ParseIntra16x16ModeConstrain1(WelsDecoderContext* pCtx);
void WelsFillCacheConstrain0Intra4x4(WelsDecoderContext* pCtx);
void ParseIntra4x4ModeConstrain0(WelsDecoderContext* pCtx);
void ParseIntra16x16ModeConstrain0(WelsDecoderContext* pCtx);