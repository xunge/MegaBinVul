#include <mutex>
#include <functional>

namespace base {
class AutoLock {
 public:
  explicit AutoLock(std::mutex& mutex) {}
};

template <typename T, typename U>
std::function<void()> Bind(T func, U* arg) {
  return std::bind(func, arg);
}
}  // namespace base

class BrowserThread {
 public:
  enum ID {
    UI
  };
  template <typename T>
  static void PostTask(ID id, const char* from_here, T task) {}
};

#define FROM_HERE ""

class TtsMessageFilter {
 public:
  void OnChannelClosing();
  void OnChannelClosingInUIThread();
 private:
  std::mutex mutex_;
  bool valid_;
};