#include <stdint.h>
#include <algorithm>
#include <stdlib.h>

typedef uint32_t OPJ_UINT32;

typedef struct {
    int prec;
    int w;
    int h;
    int* data;
} opj_image_comp_t;

typedef struct {
    opj_image_comp_t* comps;
} opj_image_t;

class FX_SAFE_SIZE_T {
public:
    FX_SAFE_SIZE_T(size_t value) : value_(value) {}
    bool IsValid() const { return true; }
    size_t ValueOrDie() const { return value_; }
    FX_SAFE_SIZE_T& operator*=(size_t rhs) { value_ *= rhs; return *this; }
private:
    size_t value_;
};

template<typename T>
T* FX_Alloc(size_t count) {
    return static_cast<T*>(malloc(count * sizeof(T)));
}

void FX_Free(void* ptr) {
    free(ptr);
}

void sycc_to_rgb(int offset, int upb, int y, int cb, int cr, int* r, int* g, int* b);

#define FX_Alloc(type, size) FX_Alloc<type>(size)