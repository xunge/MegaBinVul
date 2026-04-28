#include <cstdint>
#include <cstdlib>

class Face;

class GlyphFace {
public:
    GlyphFace();
    ~GlyphFace();
};

class GlyphBox {
public:
    GlyphBox();
    ~GlyphBox();
};

class Loader {
public:
    Loader(const Face& face);
    Loader(const Face& face, bool dumbRendering);
    ~Loader();
    operator bool() const;
    uint16_t num_glyphs() const;
    bool has_boxes() const;
    uint16_t num_attrs() const;
    uint16_t units_per_em() const;
    const GlyphFace* read_glyph(uint16_t gid, GlyphFace& glyph, int* numsubs);
    GlyphBox* read_box(uint16_t gid, GlyphBox* box, const GlyphFace& glyph);
};

enum {
    gr_face_preloadGlyphs,
    gr_face_dumbRendering
};

template <typename T>
T* grzeroalloc(size_t size) {
    return static_cast<T*>(calloc(size, sizeof(T)));
}

template <typename T>
T* gralloc(size_t size) {
    return static_cast<T*>(malloc(size));
}

class GlyphCache {
private:
    Loader* _glyph_loader;
    const GlyphFace** _glyphs;
    GlyphBox** _boxes;
    uint32_t _num_glyphs;
    uint32_t _num_attrs;
    uint32_t _upem;
public:
    GlyphCache(const Face& face, uint32_t face_options);
    GlyphCache(const Face& face, uint32_t face_options, bool dummy);
    const GlyphFace* glyph(uint16_t gid) const { return _glyphs ? _glyphs[gid] : nullptr; }
};

typedef uint32_t uint32;
typedef uint16_t uint16;