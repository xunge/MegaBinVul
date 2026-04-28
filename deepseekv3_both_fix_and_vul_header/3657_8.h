#include <stdint.h>
#include <cstring>
#include <vector>
#include <map>

namespace ui {
class Clipboard {
 public:
  enum ClipboardBuffer {
    CBF_SMBITMAP
  };
  typedef std::vector<char> ObjectMapParam;
  typedef std::vector<ObjectMapParam> ObjectMapParams;
  typedef std::map<ClipboardBuffer, ObjectMapParams> ObjectMap;
};
}  // namespace ui

namespace gfx {
class Size {
 public:
  Size() : width_(0), height_(0) {}
  Size(int width, int height) : width_(width), height_(height) {}
  int width() const { return width_; }
  int height() const { return height_; }

 private:
  int width_;
  int height_;
};
}  // namespace gfx

class SharedMemory {
 public:
  void* memory();
  void Unmap();
};

class ChildThread {
 public:
  static ChildThread* current();
  SharedMemory* AllocateSharedMemory(uint32_t size);
};

template <typename T>
class scoped_ptr {
 public:
  explicit scoped_ptr(T* ptr = nullptr) : ptr_(ptr) {}
  ~scoped_ptr() { delete ptr_; }
  T* get() const { return ptr_; }
  explicit operator bool() const { return ptr_ != nullptr; }
  void reset(T* ptr) {
    delete ptr_;
    ptr_ = ptr;
  }
  T* operator->() const { return ptr_; }
  T& operator*() const { return *ptr_; }

 private:
  T* ptr_;
};

namespace base {
template <typename T>
class CheckedNumeric {
 public:
  explicit CheckedNumeric(T value) : value_(value) {}
  CheckedNumeric(int value) : value_(static_cast<T>(value)) {}
  CheckedNumeric& operator=(T value) {
    value_ = value;
    return *this;
  }
  CheckedNumeric& operator*=(T rhs) {
    value_ *= rhs;
    return *this;
  }
  bool IsValid() const { return true; }
  T ValueOrDie() const { return value_; }

 private:
  T value_;
};
}  // namespace base

class RendererClipboardWriteContext {
 private:
  scoped_ptr<SharedMemory> shared_buf_;
 public:
  void WriteBitmapFromPixels(ui::Clipboard::ObjectMap* objects,
                            const void* pixels,
                            const gfx::Size& size);
};

#define DCHECK(condition) ((void)0)
typedef uint32_t uint32;