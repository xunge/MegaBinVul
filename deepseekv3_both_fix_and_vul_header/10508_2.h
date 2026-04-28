#include <list>
#include <cassert>

#define ALOGV(x)
#define CHECK(x) assert(x)

struct BufferInfo;
template<typename T> using List = std::list<T>;

class SoftMPEG4Encoder {
public:
    ~SoftMPEG4Encoder();
    void onReset();
    void releaseEncoder();
    List<BufferInfo*>& getPortQueue(int port);
};