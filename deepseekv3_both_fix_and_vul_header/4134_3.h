#include <stdbool.h>
#include <memory>
#include <string>
#include <functional>

namespace wap {
namespace GetAssociatedSink {
class Params {
 public:
  static std::unique_ptr<Params> Create(const std::string& args);
};
}  // namespace GetAssociatedSink
}  // namespace wap

class BrowserThread {
 public:
  static void UI();
};

#define DCHECK_CURRENTLY_ON(thread)
#define EXTENSION_FUNCTION_VALIDATE(expr)
#define FROM_HERE ""

class AudioManager {
 public:
  static AudioManager* Get();
  class WorkerTaskRunner {
   public:
    void PostTask(const char* from_here, std::function<void()> task);
  };
  WorkerTaskRunner* GetWorkerTaskRunner();
};

class WebrtcAudioPrivateGetAssociatedSinkFunction {
 public:
  bool RunAsync();
  void InitDeviceIDSalt();
  void InitResourceContext();
  void GetDevicesOnDeviceThread();
  std::unique_ptr<wap::GetAssociatedSink::Params> params_;
  std::string* args_;
};

namespace base {
template <typename T, typename U>
std::function<void()> Bind(T (U::*func)(), U* obj) {
  return std::bind(func, obj);
}
}