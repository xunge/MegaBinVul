#include <stddef.h>
#include <emmintrin.h>
#include <assert.h>

class SkConvolutionFilter1D {
public:
    typedef short ConvolutionFixed;
    enum { kShiftBits = 0 };
    int numValues() const;
    const ConvolutionFixed* FilterForValue(int offset, int* filter_offset, int* filter_length) const;
};

#define SkDEBUGCODE(code) code
#define SkASSERT(cond) assert(cond)