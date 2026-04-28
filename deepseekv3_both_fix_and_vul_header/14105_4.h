#include <vector>
#include <string>
#include <cstdint>
#include <stdexcept>

#define CV_8U  0
#define CV_8S  1
#define CV_16U 2
#define CV_16S 3
#define CV_32S 4
#define CV_32F 5
#define CV_64F 6

#define CV_ELEM_SIZE1(depth) ((depth) == CV_8U || (depth) == CV_8S ? 1 : \
                             (depth) == CV_16U || (depth) == CV_16S ? 2 : \
                             (depth) == CV_32S || (depth) == CV_32F ? 4 : \
                             (depth) == CV_64F ? 8 : 0)

typedef uint8_t uchar;
typedef uint16_t half;

struct Mat {
    int cols;
    int rows;
    int depth() const;
    int channels() const;
    int step;
    const uchar* ptr(int i = 0) const;
    template<typename T> const T* ptr(int i = 0) const;
};

namespace Imf {
    enum PixelType { UINT, HALF, FLOAT };
    class Channel {
    public:
        Channel(PixelType type);
    };
    class Slice {
    public:
        Slice(PixelType type, char* base, size_t xStride, size_t yStride);
    };
    class Header {
    public:
        Header(int width, int height);
        class ChannelList {
        public:
            void insert(const char* name, const Channel& channel);
        };
        ChannelList& channels();
    };
    class FrameBuffer {
    public:
        void insert(const char* name, const Slice& slice);
    };
    class OutputFile {
    public:
        OutputFile(const char* filename, const Header& header);
        void setFrameBuffer(const FrameBuffer& frame);
        void writePixels(int numScanLines);
    };
}

class ExrEncoder {
    std::string m_filename;
public:
    bool write(const Mat& img, const std::vector<int>&);
};

using namespace Imf;