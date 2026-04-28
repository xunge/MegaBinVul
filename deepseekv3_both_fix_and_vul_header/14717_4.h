#include <string>
#include <set>
#include <map>
#include <cstdint>

using uint64 = uint64_t;

struct EventListener {
    std::string extension_id;
    std::string sub_event_name;
    mutable std::set<uint64_t> blocked_requests;

    bool operator<(const EventListener& other) const {
        return extension_id < other.extension_id ||
               (extension_id == other.extension_id && sub_event_name < other.sub_event_name);
    }
};

struct EventResponse {};

class ExtensionWebRequestEventRouter {
public:
    void OnEventHandled(void* browser_context,
                       const std::string& extension_id,
                       const std::string& event_name,
                       const std::string& sub_event_name,
                       uint64 request_id,
                       EventResponse* response);

private:
    std::map<void*, std::map<std::string, std::set<EventListener>>> listeners_;

    void DecrementBlockCount(void* browser_context,
                            const std::string& extension_id,
                            const std::string& event_name,
                            uint64_t request_id,
                            EventResponse* response);
};