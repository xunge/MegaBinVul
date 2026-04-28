#include <memory>
#include <string>

class base {
public:
    class Value {};
};

namespace wap {
namespace GetActiveSink {
struct Params {
    static std::unique_ptr<Params> Create(const base::Value& args);
    std::string request;
};
}  // namespace GetActiveSink
}  // namespace wap

class BrowserThread {
public:
    static const int UI = 0;
    static bool CurrentlyOn(int thread_id);
};

#define DCHECK_CURRENTLY_ON(thread) \
    if (!BrowserThread::CurrentlyOn(thread)) return false;

#define EXTENSION_FUNCTION_VALIDATE(condition) \
    if (!(condition)) return false;

template<typename T>
using scoped_ptr = std::unique_ptr<T>;

class WebrtcAudioPrivateGetActiveSinkFunction {
protected:
    base::Value* args_;
    void InitDeviceIDSalt();
    void InitResourceContext();
    bool GetControllerList(const std::string& request);
public:
    bool RunAsync();
};