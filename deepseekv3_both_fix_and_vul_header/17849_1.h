#include <istream>
#include <vector>

namespace OPENEXR_IMF_INTERNAL_NAMESPACE {
    class IStream {
    public:
        virtual bool isMemoryMapped() const = 0;
        virtual std::streampos tellg() = 0;
        virtual ~IStream() {}
    };
}

struct Header {};

struct InputStreamMutex {
    OPENEXR_IMF_INTERNAL_NAMESPACE::IStream* is;
    std::streampos currentPosition;
};

struct TileOffsets {
    void readFrom(OPENEXR_IMF_INTERNAL_NAMESPACE::IStream&, bool, bool, bool);
};

struct TileBuffer {
    char* buffer;
};

struct Data {
    bool _deleteStream;
    InputStreamMutex* _streamData;
    Header header;
    int version;
    bool fileIsComplete;
    bool memoryMapped;
    std::vector<TileBuffer*> tileBuffers;
    TileOffsets tileOffsets;
    Data(int numThreads) {}
};

class TiledInputFile {
    Data* _data;
    void initialize();
public:
    TiledInputFile(const Header& header, OPENEXR_IMF_INTERNAL_NAMESPACE::IStream* is, int version, int numThreads);
};