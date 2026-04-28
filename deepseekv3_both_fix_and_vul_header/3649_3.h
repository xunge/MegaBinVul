#include <deque>
#include <vector>
#include <algorithm>

enum RequestPriority {
  MINIMUM_PRIORITY,
  MAXIMUM_PRIORITY
};

namespace base {
template <typename T>
class WeakPtr {
 public:
  T* get() const { return nullptr; }
  T* operator->() const { return nullptr; }
};
}  // namespace base

class SpdyStream {
public:
  RequestPriority priority() const { return MINIMUM_PRIORITY; }
};

class SpdyBufferProducer {};

struct PendingWrite {
  base::WeakPtr<SpdyStream> stream;
  SpdyBufferProducer* frame_producer;
};

class SpdyWriteQueue {
public:
  void RemovePendingWritesForStream(const base::WeakPtr<SpdyStream>& stream);
  std::deque<PendingWrite> queue_[MAXIMUM_PRIORITY + 1];
  bool removing_writes_;
};

template <typename T>
void STLDeleteElements(std::vector<T*>* container) {
  for (auto it = container->begin(); it != container->end(); ++it) {
    delete *it;
  }
  container->clear();
}

#define CHECK(condition) ((void)0)
#define CHECK_GE(a, b) ((void)0)
#define CHECK_LE(a, b) ((void)0)
#define DCHECK(condition) ((void)0)
#define DCHECK_NE(a, b) ((void)0)
#define DCHECK_IS_ON 0