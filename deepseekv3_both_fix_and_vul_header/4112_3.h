#include <stdint.h>

#define PP_ERROR_FAILED -1

class RunFromHostProxyCallback {
public:
    bool is_null() const;
    void Run(int32_t error) const;
};

template <typename T>
class scoped_refptr {
public:
    explicit scoped_refptr(T* ptr);
    T* operator->() const;
};

class PPB_Flash_MessageLoop_Impl {
public:
    class State {
    public:
        bool run_called();
        void set_run_called();
        void set_run_callback(const RunFromHostProxyCallback& callback);
        int32_t result();
    };

    int32_t InternalRun(const RunFromHostProxyCallback& callback);
private:
    scoped_refptr<State> state_;
};

namespace base {
    class MessageLoop {
    public:
        class ScopedNestableTaskAllower {
        public:
            explicit ScopedNestableTaskAllower(MessageLoop* loop);
        };

        static MessageLoop* current();
        void Run();
    };
}

namespace blink {
    class WebView {
    public:
        static void willEnterModalLoop();
        static void didExitModalLoop();
    };
}