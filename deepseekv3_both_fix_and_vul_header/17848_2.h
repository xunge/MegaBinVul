#include <istream>
#include <vector>
#include <string>
#include <exception>

namespace OPENEXR_IMF_INTERNAL_NAMESPACE {
    class IStream {
    public:
        virtual ~IStream() {}
        virtual bool isMemoryMapped() const = 0;
        virtual std::streampos tellg() = 0;
        virtual std::string fileName() const = 0;
    };
}

namespace IEX_NAMESPACE {
    class BaseExc : public std::exception {
    public:
        virtual const char* what() const noexcept = 0;
    };
}

#define REPLACE_EXC(e, msg) (e)

struct InputStreamMutex {
    OPENEXR_IMF_INTERNAL_NAMESPACE::IStream* is;
    std::streampos currentPosition;
};

struct TileBuffer {
    char* buffer;
};

class Header {
public:
    void readFrom(OPENEXR_IMF_INTERNAL_NAMESPACE::IStream&, int);
};

class TileOffsets {
public:
    void readFrom(OPENEXR_IMF_INTERNAL_NAMESPACE::IStream&, bool, bool, bool);
};

struct Data {
    int version;
    bool _deleteStream;
    InputStreamMutex* _streamData;
    bool fileIsComplete;
    bool memoryMapped;
    std::vector<TileBuffer*> tileBuffers;
    Header header;
    TileOffsets tileOffsets;
    
    Data(int numThreads) {}
    void initialize() {}
};

class TiledInputFile {
    Data* _data;
public:
    TiledInputFile(OPENEXR_IMF_INTERNAL_NAMESPACE::IStream &is, int numThreads);
    void readMagicNumberAndVersionField(OPENEXR_IMF_INTERNAL_NAMESPACE::IStream &is, int &version);
    bool isMultiPart(int version);
    void compatibilityInitialize(OPENEXR_IMF_INTERNAL_NAMESPACE::IStream &is);
    void initialize() { _data->initialize(); }
};