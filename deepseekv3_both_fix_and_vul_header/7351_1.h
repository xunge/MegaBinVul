#include <algorithm>
#include <vector>
#include <stdexcept>
#include <cstdint>
#include <string>

using std::min;

typedef int64_t Int64;

enum LineOrder {
    INCREASING_Y,
    DECREASING_Y
};

struct Compressor {
    enum Format { XDR };
    virtual ~Compressor() {}
    virtual Format format() const = 0;
    virtual int uncompress(char* buffer, int packedSize, int minY, char*& uncompressedData) = 0;
};

struct Header {
    int compression() const { return 0; }
};

struct InSliceInfo {
    int ySampling;
    bool skip;
    int typeInFile;
    char* base;
    int sampleStride;
    int xPointerStride;
    int yPointerStride;
    bool fill;
    float fillValue;
    int typeInFrameBuffer;
};

struct LineBuffer {
    char* uncompressedData;
    int maxY;
    int minY;
    Compressor* compressor;
    int packedDataSize;
    char* buffer;
    Compressor::Format format;
    bool hasException;
    std::string exception;
};

struct IFD {
    int maxY;
    int minY;
    std::vector<int> bytesPerLine;
    Header header;
    LineOrder lineOrder;
    std::vector<int> offsetInLineBuffer;
    std::vector<InSliceInfo*> slices;
    std::vector<std::vector<unsigned int>> sampleCount;
    int maxX;
    int minX;
    std::vector<int> lineSampleCount;
};

class LineBufferTask {
    LineBuffer* _lineBuffer;
    IFD* _ifd;
    int _scanLineMin;
    int _scanLineMax;

    Compressor* newCompressor(int compression, Int64 maxBytesPerLine, const Header& header);
    int modp(int y, int sampling);
    void skipChannel(const char*& readPtr, int typeInFile, int lineSampleCount);
    void copyIntoDeepFrameBuffer(const char* readPtr, char* base, char* sampleCountBase,
                                size_t sampleCountXStride, size_t sampleCountYStride,
                                int y, int minX, int maxX, int xOffsetForSampleCount,
                                int yOffsetForSampleCount, int xPointerStride,
                                int yPointerStride, int sampleStride, int xStride,
                                int yStride, bool fill, float fillValue,
                                Compressor::Format format, int typeInFrameBuffer,
                                int typeInFile);
public:
    void execute();
};