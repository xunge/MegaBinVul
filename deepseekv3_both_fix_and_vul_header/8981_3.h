#include <string>

class GURL {
public:
    GURL(const std::string& url);
};

class url {
public:
    class Origin {
    public:
        Origin(const GURL& url);
    };
};

namespace content {
    class RenderProcessHost {
    public:
        int GetID();
    };
    class RenderViewHost {
    public:
        RenderProcessHost* GetProcess();
    };
    class ChildProcessSecurityPolicy {
    public:
        static ChildProcessSecurityPolicy* GetInstance();
        void GrantOrigin(int process_id, const url::Origin& origin);
    };
    extern const char kChromeUIResourcesURL[];
}

namespace chrome {
    extern const char kChromeUIFaviconURL[];
    extern const char kChromeUIExtensionIconURL[];
}

class Extension {
public:
    bool is_extension() const;
    bool is_platform_app() const;
    bool is_legacy_packaged_app() const;
    int location() const;
};

class Manifest {
public:
    static bool IsComponentLocation(int location);
};

class ExtensionWebContentsObserver {
public:
    void RenderViewCreated(content::RenderViewHost* render_view_host);
};

class ChromeExtensionWebContentsObserver : public ExtensionWebContentsObserver {
protected:
    const Extension* GetExtension(content::RenderViewHost* render_view_host);
    void ReloadIfTerminated(content::RenderViewHost* render_view_host);
public:
    void RenderViewCreated(content::RenderViewHost* render_view_host);
};