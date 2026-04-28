#include <deque>
#include <memory>
#include <cassert>

#define CHECK(expr) assert(expr)

typedef int SpdyStreamId;

struct FrameProducer {
    virtual ~FrameProducer() = default;
};

struct PendingWrite {
    std::shared_ptr<class SpdyStream> stream;
    FrameProducer* frame_producer;
};

class SpdyStream {
public:
    SpdyStreamId stream_id() const { return 0; }
};

const int MINIMUM_PRIORITY = 0;
const int MAXIMUM_PRIORITY = 7;

class SpdyWriteQueue {
private:
    bool removing_writes_;
    std::deque<PendingWrite> queue_[MAXIMUM_PRIORITY + 1];
public:
    void RemovePendingWritesForStreamsAfter(SpdyStreamId last_good_stream_id);
};