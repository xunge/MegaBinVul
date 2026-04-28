#include <cassert>
#include <memory>

namespace content {
class BrowserContext;
}

class TtsController {
public:
    class GetInstance {
    public:
        GetInstance* operator->() { return this; }
        void AddVoicesChangedDelegate(void* delegate);
    };
    static GetInstance* GetInstance();
};

class BrowserMessageFilter {
public:
    explicit BrowserMessageFilter(int msg_start);
};

class BrowserThread {
public:
    static bool CurrentlyOn(int thread_id);
    static const int UI;
};

class TtsMessageFilter : public BrowserMessageFilter {
public:
    TtsMessageFilter(int render_process_id, content::BrowserContext* browser_context);
    TtsMessageFilter(int render_process_id, content::BrowserContext* browser_context, bool with_weak_ptr);
    void AddRef();
    void AddVoicesChangedDelegate(TtsMessageFilter* delegate);

private:
    int render_process_id_;
    content::BrowserContext* browser_context_;
    bool valid_;
    struct WeakPtrFactory {
        WeakPtrFactory() = default;
        WeakPtrFactory(TtsMessageFilter* ptr) {}
    } weak_ptr_factory_;
};

#define CHECK(expr) assert(expr)
const int TtsMsgStart = 0;