#include <string>

namespace url {
    template<typename CharT>
    class Replacements {
    public:
        void ClearRef();
    };
}

class WebPreferences {
public:
    bool web_security_enabled;
};

class RenderViewHost {
public:
    WebPreferences GetWebkitPreferences();
};

class RenderFrameHost {
public:
    RenderViewHost* GetRenderViewHost();
    class Process {
    public:
        void ReceivedBadMessage();
    };
    Process* GetProcess();
};

class GURL {
public:
    GURL();
    explicit GURL(const std::string& url);
    bool is_empty() const;
    std::string GetOrigin() const;
    bool has_ref() const;
    bool operator==(const GURL& other) const;
    GURL ReplaceComponents(const url::Replacements<char>& replacements) const;
};

enum NavigationType {
    NAVIGATION_TYPE_IN_PAGE
};