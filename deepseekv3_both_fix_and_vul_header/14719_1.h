#include <string>

class WebRequestAPI {
public:
    void OnListenerRemoved(const struct EventListenerInfo& details);
};

struct EventListenerInfo {
    void* browser_context;
    std::string extension_id;
    std::string event_name;
};

namespace BrowserThread {
    enum ID {
        UI,
        IO
    };
    void PostTask(ID thread, const void* from_here, void* task);
    bool CurrentlyOn(ID thread);
};

#define DCHECK_CURRENTLY_ON(thread) (void)0
#define FROM_HERE nullptr

namespace base {
    template <typename F, typename... Args>
    void* Bind(F* func, Args... args) { return nullptr; }
}

void RemoveEventListenerOnIOThread(void* browser_context,
                                 const std::string& extension_id,
                                 const std::string& event_name,
                                 int unused1,
                                 int unused2);