#include <cstddef>
#include <cstring>
#include <algorithm>
#include <vector>

using Status = bool;
using pixel_type = int;

struct Rect {
    size_t x0() const { return 0; }
    size_t y0() const { return 0; }
    size_t xsize() const { return 0; }
    size_t ysize() const { return 0; }
    pixel_type* Row(std::vector<pixel_type>*, size_t) const { return nullptr; }
    Rect(size_t x0, size_t y0, size_t xs, size_t ys, size_t w, size_t h) {}
    Rect(size_t xs, size_t ys) : Rect(0, 0, xs, ys, xs, ys) {}
    Rect(size_t x0, size_t y0, size_t xs, size_t ys) : Rect(x0, y0, xs, ys, xs, ys) {}
    Rect Crop(size_t) const { return Rect(0,0,0,0,0,0); }
};

struct BitReader {};

struct FrameDimensions {
    size_t group_dim;
    operator size_t() const { return 0; }
};

struct ModularStreamId {
    enum Kind {
        kModularDC,
        kModularAC
    };
    Kind kind;
    size_t ID(size_t) const { return 0; }
};

struct PassesDecoderState {
    size_t decoded;
};

struct ImageBundle {};

struct Channel {
    Channel(size_t w, size_t h) : w(w), h(h) {}
    size_t w;
    size_t h;
    int hshift = 0;
    int vshift = 0;
    std::vector<pixel_type> plane;
};

struct Image {
    Image(size_t, size_t, int, int) {}
    size_t bitdepth;
    size_t nb_meta_channels;
    std::vector<Channel> channel;
};

struct ModularOptions {};

struct Transform {
    Status Inverse(Image&, int) { return true; }
};

struct ModularFrameDecoder {
    Image full_image;
    FrameDimensions frame_dim;
    bool use_full_image;
    std::vector<int> tree;
    std::vector<int> code;
    std::vector<int> context_map;
    std::vector<Transform> global_transform;
    struct {
        struct {
            int wp_header;
        } global_header;
    };
    Status DecodeGroup(const Rect&, BitReader*, int, int, const ModularStreamId&, bool, PassesDecoderState*, ImageBundle*);
};

template <typename T>
void CopyImageTo(const Rect&, const std::vector<T>&, const Rect&, std::vector<T>*) {}
template <typename T>
void ZeroFillImage(std::vector<T>*) {}
bool ModularGenericDecompress(BitReader*, Image&, void*, size_t, ModularOptions*, int, std::vector<int>*, std::vector<int>*, std::vector<int>*) { return true; }
bool ModularImageToDecodedRect(Image&, PassesDecoderState*, void*, ImageBundle*, const Rect&) { return true; }

#define JXL_DASSERT(expr)
#define JXL_FAILURE(msg) false
#define JXL_RETURN_IF_ERROR(expr) if (!(expr)) return false
#define JXL_ASSERT(expr)
#define JXL_RESTRICT