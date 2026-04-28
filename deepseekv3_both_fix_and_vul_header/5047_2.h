#include <vector>

typedef double number_t;
typedef std::vector<unsigned char> buffer_t;

struct transform_t {
    void transform(number_t* x, number_t* y) const;
};

class ClipBuffer {
public:
    buffer_t buffer_;
    int width_;
    int height_;
    void intersectClipRect(transform_t const& transform, number_t x, number_t y, number_t width, number_t height);
};

namespace agg {
    template <typename T> class rendering_buffer;
    template <typename T> class renderer_scanline_aa_solid;
    template <typename T> class rasterizer_scanline_aa;
    class scanline_p8;
    struct gray8;
    struct renderer_base;
    struct fill_even_odd;
    template <typename T1, typename T2> void render_scanlines_aa_solid(T1&, T2&, renderer_base&, gray8);
    template <typename T> class pixfmt;
}

typedef agg::renderer_base renderer_base_t;
typedef agg::pixfmt<agg::gray8> pixfmt_t;