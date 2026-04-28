#include <string>
#include <vector>

class GURL {
public:
    GURL(const std::string& url);
    bool SchemeIs(const char* scheme) const;
    bool is_empty() const;
    const std::string& spec() const;
};

class Profile {};

class DevToolsUI {
public:
    static GURL GetRemoteBaseURL();
};

namespace chrome {
    extern const char kChromeUIDevToolsURL[];
}

class DevToolsWindow {
public:
    static GURL GetDevToolsURL(Profile* profile,
                              const GURL& base_url,
                              bool shared_worker_frontend,
                              const std::string& remote_frontend,
                              bool can_dock);
    static GURL GetDevToolsURL(Profile* profile,
                              const GURL& base_url,
                              bool shared_worker_frontend,
                              const std::string& remote_frontend,
                              bool can_dock,
                              const std::string& settings);
};