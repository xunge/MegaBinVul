#include <climits>
#include <vector>
#include <stdexcept>

namespace IEX_NAMESPACE {
    class ArgExc : public std::runtime_error {
    public:
        explicit ArgExc(const std::string& what_arg) : std::runtime_error(what_arg) {}
    };
}

struct Box2i {
    struct {
        int x, y;
    } min, max;
};

struct TileDescription {
    int xSize, ySize;
    int mode;
};

class TileOffsets {
public:
    TileOffsets(int mode, int numXLevels, int numYLevels, int numXTiles, int numYTiles);
};

struct Header {
    bool hasType() const;
    void setType(int type);
    int type() const;
    const TileDescription& tileDescription() const;
    int lineOrder() const;
    const Box2i& dataWindow() const;
    int compression() const;
    void sanityCheck(bool);
};

struct StreamData {
    struct {
        bool isMemoryMapped() const;
    } *is;
};

struct TileBuffer {
    TileBuffer(void*);
    char* buffer;
};

struct Data {
    int version;
    int partNumber;
    Header header;
    TileDescription tileDesc;
    int lineOrder;
    int minX, maxX, minY, maxY;
    int numXTiles, numYTiles;
    int numXLevels, numYLevels;
    int bytesPerPixel;
    int maxBytesPerTileLine;
    size_t tileBufferSize;
    std::vector<TileBuffer*> tileBuffers;
    StreamData* _streamData;
    TileOffsets tileOffsets;
};

class TiledInputFile {
    Data* _data;
public:
    void initialize();
};

void* newTileCompressor(int, int, int, const Header&);
void precalculateTileInfo(const TileDescription&, int, int, int, int, int&, int&, int&, int&);
int calculateBytesPerPixel(const Header&);
bool isMultiPart(int version);
bool isNonImage(int version);
bool isTiled(int version);

const int TILEDIMAGE = 0;