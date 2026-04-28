#include <memory>
#include <string>

namespace content {
class BrowserContext;
}

class PrefService;

struct Profile {
  static Profile* FromBrowserContext(content::BrowserContext* browser_context);
  PrefService* GetPrefs();
};

class PrefProxyConfigTracker {
public:
  void DetachFromPrefService();
};

namespace net {
struct ProxyConfig {
  struct ProxyRules {
    enum class Type {
      PROXY_LIST,
      PROXY_LIST_PER_SCHEME
    };
    Type type;
    struct ProxyList {
      bool IsEmpty() const;
    };
    ProxyList fallback_proxies;
  };
  ProxyRules proxy_rules() const;
};

struct ProxyConfigWithAnnotation {
  ProxyConfig value() const;
};

class ProxyConfigService {
public:
  enum class ConfigAvailability {
    CONFIG_VALID
  };
  virtual ConfigAvailability GetLatestProxyConfig(ProxyConfigWithAnnotation* config) = 0;
};
}

namespace ProxyServiceFactory {
std::unique_ptr<PrefProxyConfigTracker> CreatePrefProxyConfigTrackerOfProfile(
    PrefService* prefs, 
    PrefProxyConfigTracker* tracker);
std::unique_ptr<net::ProxyConfigService> CreateProxyConfigService(
    PrefProxyConfigTracker* tracker);
}

#define DCHECK(condition) ((void)0)