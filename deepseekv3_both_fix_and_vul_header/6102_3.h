#include <memory>
#include <cstdlib>
#include <new>
#include <stdexcept>
#include <cassert>

using FreeFunction = void (*)(void* buf, void* userData);
using std::unique_ptr;

#define DCHECK assert

enum class TakeOwnershipOption {
  STORE_SIZE
};

struct HeapPrefix {
  uintptr_t magic;
  size_t size;
  HeapPrefix(uintptr_t m, size_t s) : magic(m), size(s) {}
};

struct SharedInfo {
  FreeFunction freeFn;
  void* userData;
  bool useHeapFullStorage;
  SharedInfo(FreeFunction fn, void* data, bool use) 
    : freeFn(fn), userData(data), useHeapFullStorage(use) {}
};

struct HeapStorage {
  HeapPrefix prefix;
  uint8_t buf[1];
};

struct HeapFullStorage {
  HeapStorage hs;
  SharedInfo shared;
};

class IOBuf {
public:
  enum Flags : uintptr_t {
    kFlagMask = 0x7,
    kIOBufInUse = 0x1,
    kSharedInfoInUse = 0x2
  };

  struct InternalConstructor {};

  static constexpr size_t kMaxIOBufSize = (size_t(1) << 31) - 1;

  IOBuf(InternalConstructor, uintptr_t flagsAndSharedInfo,
        uint8_t* buf, size_t capacity, uint8_t* data, size_t length);

  static unique_ptr<IOBuf> takeOwnership(
      void* buf,
      size_t capacity,
      size_t offset,
      size_t length,
      FreeFunction freeFn,
      void* userData,
      bool freeOnError,
      TakeOwnershipOption option);

  static void (*io_buf_alloc_cb)(void* ptr, size_t size);
  static void (*io_buf_free_cb)(void* ptr, size_t size);

  static void takeOwnershipError(bool freeOnError, void* buf, 
                               FreeFunction freeFn, void* userData);
  static uintptr_t packFlagsAndSharedInfo(uintptr_t flags, SharedInfo* info);
};

template <typename T>
void throw_exception() {
  throw T();
}

template <typename F>
class ScopeGuard {
public:
  explicit ScopeGuard(F&& f) : f_(std::forward<F>(f)) {}
  ~ScopeGuard() { if (!dismissed_) f_(); }
  void dismiss() { dismissed_ = true; }
private:
  F f_;
  bool dismissed_ = false;
};

template <typename F>
ScopeGuard<F> makeGuard(F&& f) {
  return ScopeGuard<F>(std::forward<F>(f));
}

size_t goodMallocSize(size_t minSize);
void* checkedMalloc(size_t size);