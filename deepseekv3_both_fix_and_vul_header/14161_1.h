#include <algorithm>
#include <cstddef>

struct Rect {
    Rect() = default;
    Rect(size_t x, size_t y, size_t xs, size_t ys) : x0_(x), y0_(y), xsize_(xs), ysize_(ys) {}
    size_t x0() const { return x0_; }
    size_t y0() const { return y0_; }
    size_t xsize() const { return xsize_; }
    size_t ysize() const { return ysize_; }
private:
    size_t x0_;
    size_t y0_;
    size_t xsize_;
    size_t ysize_;
};

struct FrameDimensions {
    size_t xsize_padded;
    size_t ysize_padded;
    size_t xsize_groups;
    size_t ysize_groups;
};

class ImageF {};

class PassesDecoderState {
public:
    static constexpr size_t kGroupDataXBorder = 1;
    static constexpr size_t kGroupDataYBorder = 1;
};

class GroupBorderAssigner {
public:
    static size_t PaddingX(size_t padding) { return padding; }
};

constexpr size_t kBlockDim = 8;
constexpr size_t kGroupDimInBlocks = 256;

size_t DivCeil(size_t a, size_t b) { return (a + b - 1) / b; }

void CopyImageTo(const Rect& src_rect, const ImageF& src, const Rect& dst_rect, ImageF* dst) {}

#define JXL_DASSERT(condition) ((void)0)