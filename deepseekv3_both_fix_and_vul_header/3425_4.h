#include <stdint.h>
#include <string>
#include <map>
#include <vector>

namespace ppapi {
namespace host {
class HostMessageContext {
 public:
  struct ReplyMessageContext MakeReplyMessageContext();
};
struct ReplyMessageContext {};
}  // namespace host

struct URLRequestInfoData {
  std::string headers;
};

namespace proxy {
class HostDispatcher {
 public:
  static HostDispatcher* GetForInstance(int32_t instance);
  void set_allow_plugin_reentrancy();
};
}  // namespace proxy
}  // namespace ppapi

namespace content {
class PepperPluginInstance {
 public:
  content::PepperPluginInstance* GetPluginInstance(int32_t instance);
  void Navigate(const ppapi::URLRequestInfoData& data, 
               const char* target, 
               bool from_user_action);
};
}  // namespace content

namespace net {
namespace HttpUtil {
class HeadersIterator {
 public:
  HeadersIterator(std::string::const_iterator begin,
                 std::string::const_iterator end,
                 const char* delimiters);
  bool GetNext();
  std::string name();
  std::string values();
};
}  // namespace HttpUtil
}  // namespace net

enum FlashNavigateUsage {
  REJECT_OTHER_HEADERS,
  TOTAL_NAVIGATE_REQUESTS,
  TOTAL_REJECTED_NAVIGATE_REQUESTS
};

namespace base {
template <typename T>
class WeakPtr {
 public:
  T* get() const;
};

template <typename T>
class WeakPtrFactory {
 public:
  WeakPtr<T> GetWeakPtr();
};

template <typename T>
class LazyInstance {
 public:
  T& Get();
};
}  // namespace base

namespace IPC {
class Message {};
}  // namespace IPC

class PepperFlashRendererHost {
 public:
  int32_t OnNavigate(ppapi::host::HostMessageContext* host_context,
                    const ppapi::URLRequestInfoData& data,
                    const std::string& target,
                    bool from_user_action);
  int32_t pp_instance();
 private:
  content::PepperPluginInstance* host_;
  base::WeakPtr<PepperFlashRendererHost> GetWeakPtr();
  void SendReply(const ppapi::host::ReplyMessageContext& context,
                const IPC::Message& msg);
  std::vector<ppapi::host::ReplyMessageContext> navigate_replies_;
  base::WeakPtrFactory<PepperFlashRendererHost> weak_factory_;
};

const char* kRejectedHttpRequestHeaders[] = {""};
base::LazyInstance<std::map<std::string, FlashNavigateUsage>> g_rejected_headers;

std::string StringToLowerASCII(const std::string& str);
bool IsSimpleHeader(const std::string& name, const std::string& value);
void RecordFlashNavigateUsage(FlashNavigateUsage usage);

#define PP_ERROR_FAILED -1
#define PP_ERROR_NOACCESS -2
#define PP_OK_COMPLETIONPENDING 1

template <typename T, size_t N>
constexpr size_t arraysize(T (&array)[N]) {
  return N;
}