#include <stdbool.h>
#include <vector>

#define FECOLORMATRIX_TYPE_MATRIX 0
#define kColorMatrixSize 20

class FEColorMatrix {
public:
    int m_type;
    std::vector<float> m_values;
    bool affectsTransparentPixels();
};