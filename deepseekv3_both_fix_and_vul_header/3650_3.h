#include <deque>
#include <cassert>

#define CHECK assert

const int MINIMUM_PRIORITY = 0;
const int MAXIMUM_PRIORITY = 7;

struct FrameProducer {
  virtual ~FrameProducer() {}
};

struct PendingWrite {
  FrameProducer* frame_producer;
};

class SpdyWriteQueue {
public:
  void Clear();
  std::deque<PendingWrite> queue_[MAXIMUM_PRIORITY + 1];
  bool removing_writes_ = false;
};