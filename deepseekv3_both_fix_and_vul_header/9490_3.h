#include <string>

class GURL {
public:
    std::string GetURL() const;
};

class RenderFrameHost;
class NavigationEntry {
public:
    const GURL& GetURL() const;
};

enum class NavigationType;

class NavigationControllerImpl {
public:
    NavigationEntry* GetLastCommittedEntry() const;
    bool AreURLsInPageNavigation(const GURL&, const GURL&, bool, RenderFrameHost*) const;
    bool AreURLsInPageNavigation(const GURL&, const GURL&, bool, NavigationType) const;
    
    bool IsURLInPageNavigation(const GURL&, bool, RenderFrameHost*) const;
    bool IsURLInPageNavigation(const GURL&, bool, NavigationType) const;
};