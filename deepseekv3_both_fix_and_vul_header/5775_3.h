#include <stdlib.h>

enum { FX_BYTE = 1 };

struct CCodec_ImageDataCache {
    int m_Height;
    int m_Width;
    int m_nCachedLines;
};

class CCodec_ScanlineDecoder {
public:
    void DownScale(int dest_width, int dest_height);
    void v_DownScale(int width, int height);
    CCodec_ImageDataCache* m_pDataCache;
    int m_OutputHeight;
    int m_OutputWidth;
    int m_Pitch;
};

void* FX_AllocNL(unsigned int type, size_t size);
void* FX_TryAlloc(unsigned int type, size_t size);
void FX_Free(void* ptr);