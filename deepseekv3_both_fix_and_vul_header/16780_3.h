#include <string>

#define Q_UNUSED(x) (void)(x)

class QUrl;
class QWebEnginePage {
public:
    enum NavigationType {
        NavigationTypeLinkClicked,
        NavigationTypeTyped,
        NavigationTypeFormSubmitted,
        NavigationTypeBackForward,
        NavigationTypeReload,
        NavigationTypeOther
    };
};

namespace QDesktopServices {
    bool openUrl(const QUrl &url);
}

namespace Utility {
    void openBrowser(const QUrl &url);
}

class ExternalWebEnginePage {
public:
    bool acceptNavigationRequest(const QUrl &url, QWebEnginePage::NavigationType type, bool isMainFrame);
};