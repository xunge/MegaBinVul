#include <vector>
#include <string>
#include <cstdint>
#include <stdexcept>

typedef int64_t Int64;

namespace IEX_NAMESPACE {
    class ArgExc : public std::runtime_error {
    public:
        ArgExc(const std::string& msg) : std::runtime_error(msg) {}
    };
    class IoExc : public std::runtime_error {
    public:
        IoExc(const std::string& msg) : std::runtime_error(msg) {}
    };
}

struct V2i {
    int x;
    int y;
};

struct Box2i {
    V2i min;
    V2i max;
};

class Header {
public:
    bool hasType() const;
    std::string type() const;
    int compression() const;
    Box2i dataWindow() const;
};

namespace OPENEXR_IMF_INTERNAL_NAMESPACE {
    class IStream {
    public:
        Int64 tellg();
        void seekg(Int64 pos);
        void clear();
    };
    
    class StreamIO;
    namespace Xdr {
        template <typename> void read(IStream&, int&);
        template <typename> void read(IStream&, Int64&);
    }
}

class InputPartData {
public:
    Header header;
    std::vector<Int64> chunkOffsets;
};

class TileOffsets {
public:
    bool isValidTile(int, int, int, int);
    Int64& operator()(int, int, int, int);
    std::vector<std::vector<std::vector<Int64>>> getOffsets();
};

class MultiPartInputFile {
public:
    struct Data {
        int version;
        void chunkOffsetReconstruction(OPENEXR_IMF_INTERNAL_NAMESPACE::IStream& is, 
                                     const std::vector<InputPartData*>& parts);
    };
};

TileOffsets* createTileOffsets(const Header&);

bool isMultiPart(int version);
bool isNonImage(int version);
bool isSupportedType(const std::string&);
bool isTiled(const std::string&);

enum Compression {
    DWAB_COMPRESSION,
    PIZ_COMPRESSION,
    B44_COMPRESSION,
    B44A_COMPRESSION,
    DWAA_COMPRESSION,
    ZIP_COMPRESSION,
    PXR24_COMPRESSION,
    ZIPS_COMPRESSION,
    RLE_COMPRESSION,
    NO_COMPRESSION
};

const std::string DEEPTILE = "deep tile";
const std::string DEEPSCANLINE = "deep scanline";

using std::vector;