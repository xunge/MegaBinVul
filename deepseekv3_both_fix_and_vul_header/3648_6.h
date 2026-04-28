#include <deque>
#include <vector>
#include <memory>
#include <cassert>

typedef int SpdyStreamId;

class SpdyBufferProducer {
public:
    virtual ~SpdyBufferProducer() = default;
};

class SpdyStream {
public:
    virtual SpdyStreamId stream_id() const = 0;
    virtual ~SpdyStream() = default;
    virtual SpdyStream* Clone() const = 0;
};

struct PendingWrite {
    std::unique_ptr<SpdyStream> stream;
    SpdyBufferProducer* frame_producer;
    
    PendingWrite() = default;
    PendingWrite(const PendingWrite& other) 
        : stream(other.stream ? other.stream->Clone() : nullptr),
          frame_producer(other.frame_producer) {}
    PendingWrite& operator=(const PendingWrite& other) {
        if (this != &other) {
            stream.reset(other.stream ? other.stream->Clone() : nullptr);
            frame_producer = other.frame_producer;
        }
        return *this;
    }
};

class SpdyWriteQueue {
public:
    void RemovePendingWritesForStreamsAfter(SpdyStreamId last_good_stream_id);

protected:
    bool removing_writes_;
    std::deque<PendingWrite> queue_[8];
};

const int MINIMUM_PRIORITY = 0;
const int MAXIMUM_PRIORITY = 7;

#define CHECK(expr) assert(expr)

template <typename T>
void STLDeleteElements(std::vector<T*>* container) {
    for (typename std::vector<T*>::const_iterator it = container->begin();
         it != container->end(); ++it) {
        delete *it;
    }
    container->clear();
}