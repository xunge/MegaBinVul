#include <stdbool.h>
#include <assert.h>
#include <cstddef>

#define SkASSERT(x) assert(x)

typedef unsigned TypeMask;
typedef float SkScalar;

enum {
    kScale_Mask,
    kTranslate_Mask,
    kPerspective_Mask,
    kRectStaysRect_Mask
};

enum {
    kMScaleX,
    kMScaleY,
    kMSkewX,
    kMSkewY,
    kMTransX,
    kMTransY,
    kMPersp0,
    kMPersp1,
    kMPersp2
};

struct SkMatrix {
    SkScalar fMat[9];
    TypeMask fTypeMask;
    
    bool isIdentity() const;
    TypeMask getType() const;
    void setTypeMask(TypeMask mask);
    void setTranslate(SkScalar x, SkScalar y);
    bool isFinite() const;
    bool invertNonIdentity(SkMatrix* inv) const;
};

static inline SkScalar SkScalarInvert(SkScalar value) {
    return 1.0f / value;
}

static inline double sk_inv_determinant(const SkScalar mat[9], int isPersp) {
    return 0.0;
}

static inline void ComputeInv(SkScalar dst[9], const SkScalar src[9], double invDet, int isPersp) {
}

static inline SkScalar scross_dscale(SkScalar a, SkScalar b, SkScalar c, SkScalar d, double scale) {
    return 0.0f;
}

static inline SkScalar dcross_dscale(SkScalar a, SkScalar b, SkScalar c, SkScalar d, double scale) {
    return 0.0f;
}

static inline SkScalar SkDoubleToScalar(double value) {
    return (SkScalar)value;
}