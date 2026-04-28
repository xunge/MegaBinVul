#include <stdint.h>
#include <stdlib.h>

#define FX_BOOL int
#define TRUE 1
#define FALSE 0
#define FX_AllocNL(type, size) (type*)malloc((size) * sizeof(type))
#define FX_Alloc(type, size) (type*)malloc((size) * sizeof(type))
#define FX_TryAlloc(type, size) (type*)malloc((size) * sizeof(type))
#define FX_DWORD uint32_t

class CStretchEngine {
public:
    int StartStretchHorz();
    int m_DestWidth;
    unsigned char* m_pDestScanline;
    struct {
        int Height();
        int Width();
        int left;
        int right;
        int top;
    } m_SrcClip;
    unsigned int m_InterPitch;
    unsigned char* m_pInterBuf;
    struct {
        unsigned char* m_pAlphaMask;
    } *m_pSource;
    int m_bHasAlpha;
    unsigned char* m_pExtraAlphaBuf;
    unsigned int m_ExtraMaskPitch;
    unsigned char* m_pDestMaskScanline;
    struct {
        int Width();
        int left;
        int right;
    } m_DestClip;
    int m_SrcWidth;
    int m_Flags;
    struct {
        void* m_pWeightTables;
        void Calc(int, int, int, int, int, int, int);
    } m_WeightTable;
    int m_CurRow;
    int m_State;
};