#include <string>

namespace content {
class BrowserContext;
}

class GURL {
public:
    GURL(const std::string& url);
    bool SchemeIsHTTPOrHTTPS() const;
    bool is_empty() const;
};

class ExtensionPrefs {
public:
    static ExtensionPrefs* Get(content::BrowserContext* context);
    std::string GetUninstallURL(const std::string& extension_id);
};

class RuntimeAPI {
public:
    static RuntimeAPI* GetFactoryInstance();
    class RuntimeEventRouter* Get(content::BrowserContext* context);
};

enum UninstallReason {
    UNINSTALL_REASON_USER_INITIATED,
    UNINSTALL_REASON_MANAGEMENT_API
};

class RuntimeEventRouter {
public:
    void OnExtensionUninstalled(content::BrowserContext* context,
                              const std::string& extension_id,
                              UninstallReason reason);
    void OpenURL(const GURL& url);
    static std::string GetUninstallURL(ExtensionPrefs* prefs, const std::string& extension_id);
};