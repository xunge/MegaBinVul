#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>

using std::string;

#define THROW(ex, msg) do { \
    std::ostringstream oss; \
    oss << msg; \
    throw ex(oss.str()); \
} while(0)

class FrameBuffer
{
public:
    class ConstIterator
    {
    public:
        ConstIterator() {}
        bool operator!=(const ConstIterator&) const { return false; }
        ConstIterator& operator++() { return *this; }
        ConstIterator operator++(int) { return *this; }
        class Slice
        {
        public:
            int xSampling;
            int ySampling;
        };
        Slice slice() const { return Slice(); }
        std::string name() const { return ""; }
    };
    
    ConstIterator begin() const { return ConstIterator(); }
    ConstIterator end() const { return ConstIterator(); }
};

namespace IEX_NAMESPACE
{
    class ArgExc : public std::runtime_error
    {
    public:
        ArgExc(const std::string& what) : std::runtime_error(what) {}
    };
};

struct CompositeDeepScanLineData
{
    std::vector<std::string> _channels;
    std::vector<int> _bufferMap;
    bool _zback;
    FrameBuffer _outputFrameBuffer;
};

class CompositeDeepScanLine
{
private:
    CompositeDeepScanLineData* _Data;
public:
    void setFrameBuffer(const FrameBuffer& fr);
};