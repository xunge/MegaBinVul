#include <string.h>
#include <vector>

typedef float SkScalar;
typedef void SkColorFilter;

enum ColorMatrixType {
    FECOLORMATRIX_TYPE_UNKNOWN,
    FECOLORMATRIX_TYPE_MATRIX,
    FECOLORMATRIX_TYPE_SATURATE,
    FECOLORMATRIX_TYPE_HUEROTATE,
    FECOLORMATRIX_TYPE_LUMINANCETOALPHA
};

const unsigned kColorMatrixSize = 20;

template<typename T> class Vector {
public:
    size_t size() const;
    T operator[](size_t) const;
};

void saturateMatrix(float, SkScalar*);
void hueRotateMatrix(float, SkScalar*);
void luminanceToAlphaMatrix(SkScalar*);

class SkColorMatrixFilter {
public:
    static SkColorFilter* Create(const SkScalar[]);
};