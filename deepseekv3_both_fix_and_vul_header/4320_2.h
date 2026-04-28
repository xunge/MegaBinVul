#include <string>
#include <memory>

class GURL {
public:
    GURL();
    GURL(const std::string&);
    bool is_valid() const;
    std::string GetOrigin() const;
    GURL Resolve(const std::string&) const;
    bool operator!=(const GURL&) const;
    bool operator==(const GURL&) const;
};

namespace url {
    extern const char kAboutBlankURL[];
    bool IsSameOriginWith(const GURL&, const GURL&);
}

namespace content {
    class WebContents {
    public:
        class RenderProcessHost {
        public:
            void FilterURL(bool, GURL*);
        };
        class NavigationController {
        public:
            void LoadURL(const GURL&, const class Referrer&, unsigned int, const std::string&);
        };
        RenderProcessHost* GetRenderProcessHost();
        NavigationController& GetController();
    };
    class Referrer {};
}

namespace ui {
    constexpr unsigned int PAGE_TRANSITION_AUTO_TOPLEVEL = 0;
}

class ExtensionViewGuest {
protected:
    GURL extension_url_;
    GURL url_;
    content::WebContents* web_contents();
    bool NavigateGuest(const std::string&, bool);
};