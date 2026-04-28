#include <string>
#include <functional>
#include <cstdio>

class GURL {
 public:
  GURL(const std::string& url);
  std::string spec() const;
};

namespace net {
std::string EscapeUrlEncodedData(const std::string& input, bool use_plus);
}  // namespace net

namespace base {
std::string StringPrintf(const char* format, ...);
}  // namespace base

namespace content {
class WebContents;
class ResourceRequestInfo {
 public:
  using WebContentsGetter = std::function<WebContents*()>;
};
class NavigationController {
 public:
  struct LoadURLParams {
    LoadURLParams(const GURL& url);
  };
  void LoadURLWithParams(const LoadURLParams& params);
};
class DownloadUrlParameters {
 public:
  static DownloadUrlParameters* CreateForWebContentsMainFrame(WebContents* web_contents, const GURL& url);
};
class BrowserContext {
 public:
  static class DownloadManager* GetDownloadManager(BrowserContext* context);
};
class DownloadManager {
 public:
  void DownloadUrl(DownloadUrlParameters* params);
};
class WebContents {
 public:
  BrowserContext* GetBrowserContext();
  NavigationController& GetController();
};
}  // namespace content

class WebContentsPreferences {
 public:
  static bool IsPluginsEnabled(content::WebContents* web_contents);
};

extern const char kPdfViewerUIOrigin[];
extern const char kPdfPluginSrc[];

// 修改为使用 operator() 调用
#define Run() operator()()