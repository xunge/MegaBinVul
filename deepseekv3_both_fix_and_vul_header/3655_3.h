#include <algorithm>
#include <cassert>
#include <map>
#include <memory>
#include <vector>

#define CHECK(condition) assert(condition)
#define CHECK_GE(a, b) assert((a) >= (b))
#define CHECK_LE(a, b) assert((a) <= (b))
#define DCHECK_EQ(a, b) assert((a) == (b))

enum RequestPriority {
  MINIMUM_PRIORITY,
  MAXIMUM_PRIORITY
};

enum SpdyFrameType {};

template <typename T>
class scoped_ptr {
 public:
  explicit scoped_ptr(T* ptr) : ptr_(ptr) {}
  ~scoped_ptr() { delete ptr_; }
  T* release() {
    T* ptr = ptr_;
    ptr_ = nullptr;
    return ptr;
  }

 private:
  T* ptr_;
};

class SpdyBufferProducer {};
class SpdyStream {
 public:
  RequestPriority priority() const { return MINIMUM_PRIORITY; }
};

template <typename T>
class WeakPtr {
 public:
  T* get() const { return nullptr; }
  T* operator->() const { return nullptr; }
};

namespace base {
template <typename T>
using WeakPtr = ::WeakPtr<T>;
}

struct PendingWrite {
  PendingWrite(SpdyFrameType, SpdyBufferProducer*, const base::WeakPtr<SpdyStream>&) {}
};

class SpdyWriteQueue {
 public:
  void Enqueue(RequestPriority priority,
               SpdyFrameType frame_type,
               scoped_ptr<SpdyBufferProducer> frame_producer,
               const base::WeakPtr<SpdyStream>& stream);

 private:
  std::map<RequestPriority, std::vector<PendingWrite>> queue_;
  bool removing_writes_ = false;
};