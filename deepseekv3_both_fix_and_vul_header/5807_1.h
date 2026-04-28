#include <stdint.h>
#include <string.h>

typedef int FX_INT32;
typedef unsigned char FX_BYTE;
typedef unsigned int FX_DWORD;
typedef int FX_BOOL;

namespace pdfium {
namespace base {
template <typename Dst, typename Src>
Dst checked_cast(Src value) {
    return static_cast<Dst>(value);
}
}  // namespace base
}  // namespace pdfium

class FX_SAFE_DWORD {
public:
    FX_SAFE_DWORD(FX_DWORD value) : m_value(value) {}
    FX_SAFE_DWORD& operator*=(FX_DWORD value) { m_value *= value; return *this; }
    bool IsValid() const { return true; }
    FX_DWORD ValueOrDie() const { return m_value; }
private:
    FX_DWORD m_value;
};

class CJBig2_Module {
public:
    void* JBig2_Realloc(void* ptr, size_t size);
};

#define JBIG2_memset memset

class CJBig2_Image {
public:
    void expand(FX_INT32 h, FX_BOOL v);
    FX_BYTE* m_pData;
    FX_INT32 m_nHeight;
    FX_INT32 m_nStride;
    CJBig2_Module* m_pModule;
};