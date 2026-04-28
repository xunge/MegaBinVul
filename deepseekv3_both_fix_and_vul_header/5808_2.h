#include <stdint.h>
#include <stddef.h>
#include <string.h>

typedef int FX_INT32;
typedef unsigned int FX_DWORD;
typedef unsigned char FX_BYTE;
typedef int FX_BOOL;

struct FX_SAFE_DWORD {
    bool IsValid();
    FX_DWORD ValueOrDie();
    FX_SAFE_DWORD& operator*=(const FX_SAFE_DWORD& other);
};

namespace pdfium {
namespace base {
    template <typename T>
    FX_SAFE_DWORD checked_cast(T value);
} // namespace base
} // namespace pdfium

class CJBig2_Image {
public:
    void expand(FX_INT32 h, FX_BOOL v);
protected:
    FX_BYTE* m_pData;
    FX_INT32 m_nStride;
    FX_INT32 m_nHeight;
    struct {
        void* (*JBig2_Realloc)(void*, FX_DWORD);
    }* m_pModule;
};

#define JBIG2_memset memset