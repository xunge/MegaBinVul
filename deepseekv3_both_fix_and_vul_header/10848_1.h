#include <vector>
#include <cstdint>

#define WEBP_CHUNK_IMAGE 0
#define kChunk_VP8X 0

typedef uint8_t XMP_Uns8;
typedef uint32_t XMP_Uns32;

class Container;

class Chunk {
public:
    Chunk(Container* parent, int type);
    std::vector<uint8_t> data;
    size_t size;
    bool needsRewrite;
};

class VP8XChunk : public Chunk {
public:
    VP8XChunk(Container* parent);
    void width(XMP_Uns32 w);
    void height(XMP_Uns32 h);
};

class Container {
public:
    std::vector<Chunk*> chunks[1];
    VP8XChunk* vp8x;
};