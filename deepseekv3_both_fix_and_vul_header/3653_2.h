#include <algorithm>
#include <deque>
#include <memory>
#include <cassert>

enum SpdyFrameType {};

class SpdyBufferProducer {};
class SpdyStream {};

template <typename T>
class scoped_ptr {
 public:
  void reset(T* ptr) {}
  T* get() const { return nullptr; }
};

template <typename T>
class WeakPtr {
 public:
  T* get() const { return nullptr; }
};

namespace base {
template <typename T>
using WeakPtr = WeakPtr<T>;
}  // namespace base

struct PendingWrite {
  SpdyFrameType frame_type;
  SpdyBufferProducer* frame_producer;
  base::WeakPtr<SpdyStream> stream;
  bool has_stream;
};

const int MAXIMUM_PRIORITY = 7;
const int MINIMUM_PRIORITY = 0;

#define CHECK(condition) assert(condition)
#define DCHECK(condition) assert(condition)

class SpdyWriteQueue {
public:
  bool Dequeue(SpdyFrameType* frame_type,
               scoped_ptr<SpdyBufferProducer>* frame_producer,
               base::WeakPtr<SpdyStream>* stream);
  
  std::deque<PendingWrite> queue_[8];
  bool removing_writes_;
};