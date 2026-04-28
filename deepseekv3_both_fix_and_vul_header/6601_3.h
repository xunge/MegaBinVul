#include <string>

class GURL {
public:
    GURL(const std::string& url);
    std::string spec() const;
};

namespace net {
    std::string EscapeUrlEncodedData(const std::string& data, bool escape_plus);
}

namespace base {
    std::string StringPrintf(const char* format, ...);
}

namespace content {
    class LoadURLParams {
    public:
        LoadURLParams(const GURL& url);
    };

    class Controller {
    public:
        void LoadURLWithParams(const LoadURLParams& params);
    };

    class WebContents {
    public:
        class BrowserContext* GetBrowserContext();
        Controller& GetController();
    };

    class ResourceRequestInfo {
    public:
        class WebContentsGetter {
        public:
            WebContents* Run() const;
        };
    };

    class BrowserContext {
    public:
        static class DownloadManager* GetDownloadManager(BrowserContext* context);
    };

    class DownloadManager {
    public:
        void DownloadUrl(class DownloadUrlParameters* params);
    };

    class DownloadUrlParameters {
    public:
        static DownloadUrlParameters* CreateForWebContentsMainFrame(WebContents* contents, const GURL& url);
    };

    class NavigationController {
    public:
        typedef LoadURLParams LoadURLParams;
    };
}

class WebContentsPreferences {
public:
    static bool IsPluginsEnabled(content::WebContents* web_contents);
};

extern const char kPdfViewerUIOrigin[];
extern const char kPdfPluginSrc[];