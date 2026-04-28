#include <memory>
#include <string>

namespace wap {
namespace SetActiveSink {

struct Request {
  std::unique_ptr<int> guest_process_id;
  std::unique_ptr<int> tab_id;
};

struct Params {
  Request request;
  std::string sink_id;
  static Params* Create(const std::string& args);
};

}  // namespace SetActiveSink
}  // namespace wap

struct RequestInfo {
  std::unique_ptr<int> guest_process_id;
  std::unique_ptr<int> tab_id;
};

class BrowserThread {
public:
  static void UI();
};

#define DCHECK_CURRENTLY_ON(thread) 
#define EXTENSION_FUNCTION_VALIDATE(expr) 

template<typename T>
class scoped_ptr {
public:
  explicit scoped_ptr(T* ptr) : ptr_(ptr) {}
  ~scoped_ptr() { delete ptr_; }
  T* get() const { return ptr_; }
  T* operator->() const { return ptr_; }
  T& operator*() const { return *ptr_; }

private:
  T* ptr_;
};

class WebrtcAudioPrivateSetActiveSinkFunction {
protected:
  std::string* args_;
  RequestInfo request_info_;
  std::string sink_id_;

  void InitDeviceIDSalt();
  void InitResourceContext();
  bool GetControllerList(const RequestInfo& request_info);
  bool RunAsync();
};