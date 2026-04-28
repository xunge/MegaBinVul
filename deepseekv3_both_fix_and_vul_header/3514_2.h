#include <string>
#include <functional>
#include <memory>

class CommandLine {
public:
    static CommandLine* ForCurrentProcess();
    bool HasSwitch(const std::string& switch_string) const;
};

class BrowserThread {
public:
    enum {
        FILE
    };
    static void PostTask(int thread_id, const void* from_here, std::function<void()> task);
};

#define FROM_HERE nullptr

namespace base {
template <typename T>
T* Unretained(T* ptr) { return ptr; }

template <typename T, typename U>
std::function<void()> Bind(T func, U obj) {
    return [=]() { (obj->*func)(); };
}
}

namespace switches {
extern const std::string kEnableSpeechDispatcher;
}

class TtsPlatformImplLinux {
public:
    TtsPlatformImplLinux();
    void Initialize();

private:
    int utterance_id_;
};