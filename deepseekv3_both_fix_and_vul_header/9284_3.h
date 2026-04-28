#include <stdint.h>
#include <algorithm>
#include <cstdlib>

typedef uint32_t OPJ_UINT32;

class FX_SAFE_SIZE_T {
public:
    FX_SAFE_SIZE_T(size_t value) : value_(value) {}
    bool IsValid() const { return true; }
    size_t ValueOrDie() const { return value_; }
    FX_SAFE_SIZE_T& operator*=(size_t other) { value_ *= other; return *this; }
private:
    size_t value_;
};

template <typename T>
T* FX_Alloc(size_t size) {
    return static_cast<T*>(malloc(size * sizeof(T)));
}

template <typename T>
void FX_Free(T* ptr) {
    free(ptr);
}

struct opj_image_comp {
    int prec;
    OPJ_UINT32 w;
    OPJ_UINT32 h;
    OPJ_UINT32 dx;
    OPJ_UINT32 dy;
    int* data;
};

struct opj_image_t {
    opj_image_comp* comps;
};

void sycc_to_rgb(int offset, int upb, int y, int cb, int cr, int* r, int* g, int* b);

#define FX_Alloc(type, size) static_cast<type*>(malloc((size) * sizeof(type)))