#include <atomic>
#include <functional>
#include <memory>

namespace base {
namespace subtle {
typedef int32_t Atomic32;
}

template <typename T>
class Callback {};

template <typename F, typename... Args>
Callback<void()> Bind(F f, Args... args) {
    return Callback<void()>();
}
}  // namespace base

class Decoder {
public:
    void WaitForReadPixels(base::Callback<void()> callback);
};

class Manager {
public:
    Decoder* decoder();
};

class AsyncReadPixelsCompletedQuery {
public:
    bool End(base::subtle::Atomic32 submit_count);
    bool AddToPendingQueue(base::subtle::Atomic32 submit_count);
    Manager* manager();
    bool Process();
    std::weak_ptr<AsyncReadPixelsCompletedQuery> AsWeakPtr();
    static void Complete();
};