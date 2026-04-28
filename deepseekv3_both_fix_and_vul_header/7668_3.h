#include <string>
#include <memory>
#include <utility>

class GURL {
public:
    GURL();
    GURL(const GURL&);
    GURL(GURL&&);
    ~GURL();
    bool SchemeIsHTTPOrHTTPS() const;
    bool DomainIs(const char*) const;
    GURL& operator=(GURL&&);
};

class OnionLocationTabHelper {
public:
    static void SetOnionLocation(void* web_contents, const GURL& url);
};

class PrefService {
public:
    bool GetBoolean(const char* pref) const;
};

namespace content {
class WebContents;

class NavigationHandle {
public:
    GURL GetURL() const;
    WebContents* GetWebContents() const;
};

class NavigationThrottle {
public:
    enum ThrottleCheckResult {
        PROCEED,
        BLOCK_REQUEST
    };
};
}  // namespace content

class OnionLocationNavigationThrottle {
public:
    bool is_tor_profile_;
    bool block_onion_requests_outside_tor_for_testing_;
    PrefService* pref_service_;
    
    class Delegate {
    public:
        void OpenInTorWindow(content::WebContents* web_contents, GURL&& url);
    };
    Delegate* delegate_;
    
    content::NavigationHandle* navigation_handle();
    content::NavigationThrottle::ThrottleCheckResult WillStartRequest();
};

namespace prefs {
extern const char kAutoOnionRedirect[];
}  // namespace prefs