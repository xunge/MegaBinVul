#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#define FX_FLOAT float
#define FX_BYTE uint8_t
#define FXSYS_Div(a, b) ((a) / (b))
#define FXSYS_ceil(x) ceil(x)
#define FXSYS_fabs(x) fabs(x)
#define FXSYS_floor(x) floor(x)
#define FXSYS_round(x) round(x)
#define FX_AllocNL(type, size) (type*)malloc(size)
#define FX_TryAlloc(type, size) (type*)malloc(size)
#define FX_Free(ptr) free(ptr)

#define FXDIB_BICUBIC_INTERPOL 0x01
#define FXDIB_NOSMOOTH 0x02
#define FXDIB_INTERPOL 0x04

struct PixelWeight {
    int m_SrcStart;
    int m_SrcEnd;
    int m_Weights[4];
};

static const int SDP_Table[768] = {0};

class CWeightTable {
public:
    void Calc(int dest_len, int dest_min, int dest_max, int src_len, int src_min, int src_max, int flags);
    
private:
    FX_BYTE* m_pWeightTables;
    int m_ItemSize;
    int m_DestMin;
    
    PixelWeight* GetPixelWeight(int dest_pixel) {
        return reinterpret_cast<PixelWeight*>(m_pWeightTables + (dest_pixel - m_DestMin) * m_ItemSize);
    }
};