#include <deque>
#include <memory>
#include <cassert>

#define CHECK(cond) assert(cond)
#define CHECK_GE(a, b) assert((a) >= (b))
#define CHECK_LE(a, b) assert((a) <= (b))
#define DCHECK(cond) assert(cond)
#define DCHECK_NE(a, b) assert((a) != (b))
#define DCHECK_IS_ON 1

enum RequestPriority {
  MINIMUM_PRIORITY,
  MAXIMUM_PRIORITY
};

struct FrameProducer {
  virtual ~FrameProducer() = default;
};

struct PendingWrite {
  std::shared_ptr<void> stream;
  FrameProducer* frame_producer;
};

template<typename T>
class WeakPtr {
public:
  T* get() const { return nullptr; }
  T* operator->() const { return nullptr; }
};

class SpdyStream {
public:
  RequestPriority priority() const { return MINIMUM_PRIORITY; }
};

namespace base {
template<typename T>
using WeakPtr = ::WeakPtr<T>;
}

class SpdyWriteQueue {
public:
  void RemovePendingWritesForStream(const base::WeakPtr<SpdyStream>& stream);
protected:
  std::deque<PendingWrite> queue_[MAXIMUM_PRIORITY + 1];
  bool removing_writes_ = false;
};