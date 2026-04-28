#include <string>

namespace WebUI {
  typedef void* TypeID;
  static const TypeID kNoWebUI = nullptr;
}

class BrowserContext;
class GURL {
public:
  bool SchemeIs(const std::string& scheme) const;
  std::string host() const;
};

extern const std::string kChromeUIScheme;
extern const std::string kChromeUIWebRTCInternalsHost;
extern const std::string kChromeUITracingHost;
extern const std::string kChromeUIGpuHost;
extern const std::string kChromeUIIndexedDBInternalsHost;
extern const std::string kChromeUIMediaInternalsHost;
extern const std::string kChromeUIServiceWorkerInternalsHost;
extern const std::string kChromeUIAccessibilityHost;

class ContentWebUIControllerFactory {
public:
  WebUI::TypeID GetWebUIType(BrowserContext* browser_context, const GURL& url) const;
};