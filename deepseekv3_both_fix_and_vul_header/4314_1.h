#include <string>

class GURL {
public:
    GURL(const std::string& url);
    bool operator==(const GURL& other) const;
};

namespace url {
    extern const char kAboutBlankURL[];
}

class NavigationEntry {
public:
    virtual GURL GetURL() const = 0;
};

class NavigationEntryImpl : public NavigationEntry {
public:
    bool is_renderer_initiated() const;
    GURL GetURL() const override;
};

class WebContentsImpl;

class WebContentsDelegate {
public:
    virtual bool ShouldFocusLocationBarByDefault(WebContentsImpl* contents) = 0;
};

class NavigationController {
public:
    NavigationEntry* GetVisibleEntry();
    NavigationEntryImpl* GetPendingEntry();
    bool IsInitialNavigation() const;
};

class WebContentsImpl {
public:
    bool FocusLocationBarByDefault();
protected:
    NavigationController controller_;
    WebContentsDelegate* delegate_;
};