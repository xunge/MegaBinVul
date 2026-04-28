#include <istream>
#include <exception>
#include <string>
#include <sstream>

namespace IEX_NAMESPACE {
    class BaseExc : public std::exception {
    public:
        BaseExc(const std::string&);
        const char* what() const noexcept;
    };
    
    class ArgExc : public BaseExc {
    public:
        ArgExc(const std::string&);
    };
    
    class IoExc : public BaseExc {
    public:
        IoExc(const std::string&);
    };
}

struct StreamData;

class Lock {
public:
    Lock(StreamData&);
};

class TileBuffer {
public:
    char* buffer;
};

struct StreamData {
    std::istream* is;
};

struct Data {
    StreamData* _streamData;
    TileBuffer* getTileBuffer(int);
    int tileOffsets(int, int, int, int);
    bool isMultiPart(int);
    int version();
};

class TiledInputFile {
private:
    Data* _data;
public:
    bool isValidTile(int, int, int, int);
    int version();
    bool isMultiPart(int);
    void readNextTileData(StreamData*, Data*, int&, int&, int&, int&, char*&, int&);
    std::string fileName();
    void rawTileData(int&, int&, int&, int&, const char*&, int&);
};

#define REPLACE_EXC(e, msg) \
    do { \
        std::ostringstream oss; \
        oss << msg; \
        e = IEX_NAMESPACE::BaseExc(oss.str()); \
    } while(0)