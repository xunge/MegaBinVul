#include <stdint.h>
#include <stdlib.h>
#include <algorithm>

typedef uint32_t OPJ_UINT32;

typedef struct {
    int* data;
    OPJ_UINT32 w;
    OPJ_UINT32 h;
    int dx;
    int dy;
    int prec;
} opj_image_comp_t;

typedef struct {
    opj_image_comp_t* comps;
    int numcomps;
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

#define FX_Alloc(type, size) ((type*)malloc((size)*sizeof(type)))
#define FX_Free(ptr) free(ptr)

bool sycc422_size_is_valid(opj_image_t* img);
void sycc_to_rgb(int offset, int upb, int y, int cb, int cr, int* r, int* g, int* b);