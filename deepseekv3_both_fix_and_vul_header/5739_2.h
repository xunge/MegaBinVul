#include <string>

class WebUI {
public:
    virtual ~WebUI() {}
};

class GURL {
public:
    std::string host() const { return ""; }
    bool SchemeIs(const char* scheme) const { return false; }
};

class WebUIController {
public:
    explicit WebUIController(WebUI* web_ui) {}
    virtual ~WebUIController() {}
};

class GpuInternalsUI : public WebUIController {
public:
    explicit GpuInternalsUI(WebUI* web_ui) : WebUIController(web_ui) {}
};

class IndexedDBInternalsUI : public WebUIController {
public:
    explicit IndexedDBInternalsUI(WebUI* web_ui) : WebUIController(web_ui) {}
};

class MediaInternalsUI : public WebUIController {
public:
    explicit MediaInternalsUI(WebUI* web_ui) : WebUIController(web_ui) {}
};

class AccessibilityUI : public WebUIController {
public:
    explicit AccessibilityUI(WebUI* web_ui) : WebUIController(web_ui) {}
};

class ServiceWorkerInternalsUI : public WebUIController {
public:
    explicit ServiceWorkerInternalsUI(WebUI* web_ui) : WebUIController(web_ui) {}
};

class TracingUI : public WebUIController {
public:
    explicit TracingUI(WebUI* web_ui) : WebUIController(web_ui) {}
};

class WebRTCInternalsUI : public WebUIController {
public:
    explicit WebRTCInternalsUI(WebUI* web_ui) : WebUIController(web_ui) {}
};

class ContentWebUIControllerFactory {
public:
    virtual WebUIController* CreateWebUIControllerForURL(WebUI* web_ui, const GURL& url) const;
};

const char kChromeUIScheme[] = "chrome";
const char kChromeUIGpuHost[] = "gpu";
const char kChromeUIIndexedDBInternalsHost[] = "indexeddb-internals";
const char kChromeUIMediaInternalsHost[] = "media-internals";
const char kChromeUIAccessibilityHost[] = "accessibility";
const char kChromeUIServiceWorkerInternalsHost[] = "serviceworker-internals";
const char kChromeUITracingHost[] = "tracing";
const char kChromeUIWebRTCInternalsHost[] = "webrtc-internals";