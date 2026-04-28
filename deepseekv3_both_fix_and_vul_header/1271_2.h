#include <cassert>
#include <cstddef>

struct Box2i {
    struct {
        int x;
        int y;
    } min, max;
};

enum PixelType { HALF };
enum DataFormat { XDR, NATIVE };

struct Channel {
    PixelType type;
    int ySampling;
    bool pLinear;
};

class ChannelList {
public:
    class ConstIterator {
    public:
        const Channel& channel() const;
        ConstIterator& operator++();
        bool operator!=(const ConstIterator& other) const;
    };
    ConstIterator begin() const;
    ConstIterator end() const;
};

struct Header {
    const ChannelList& channels() const;
    const Box2i& dataWindow() const;
};

class Compressor {
public:
    Compressor(const Header& hdr);
    const Header& header() const;
};

struct ChannelData {
    int ys;
    PixelType type;
    bool pLinear;
    size_t size;
};

class B44Compressor : public Compressor {
public:
    B44Compressor(const Header& hdr, size_t maxScanLineSize, size_t numScanLines, bool optFlatFields);
private:
    size_t _maxScanLineSize;
    bool _optFlatFields;
    DataFormat _format;
    size_t _numScanLines;
    unsigned short* _tmpBuffer;
    char* _outBuffer;
    int _numChans;
    const ChannelList& _channels;
    ChannelData* _channelData;
    int _minX;
    int _maxX;
    int _maxY;
};

size_t pixelTypeSize(PixelType type);
size_t uiMult(size_t a, size_t b);
size_t uiAdd(size_t a, size_t b);
size_t checkArraySize(size_t size, size_t typeSize);