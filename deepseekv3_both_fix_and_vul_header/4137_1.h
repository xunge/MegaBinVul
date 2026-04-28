#include <string>
#include <functional>

class GURL {
public:
    GURL();
    GURL(const GURL&);
    ~GURL();
};

namespace content {
class WebContents {
public:
    void* GetBrowserContext();
};
class RenderFrameHost {};
class WebContentsObserver {
public:
    WebContentsObserver(content::WebContents*);
};
}

class Profile {
public:
    static Profile* FromBrowserContext(void*);
};

class WebstoreStandaloneInstaller {
public:
    WebstoreStandaloneInstaller(const std::string&, Profile*, std::function<void(bool, const std::string&)>);
};

class WebstoreInlineInstaller : public WebstoreStandaloneInstaller, public content::WebContentsObserver {
public:
    using Callback = std::function<void(bool, const std::string&)>;
    WebstoreInlineInstaller(content::WebContents*, content::RenderFrameHost*, const std::string&, const GURL&, const Callback&);
    WebstoreInlineInstaller(content::WebContents*, const std::string&, const GURL&, const Callback&);
private:
    content::RenderFrameHost* host_;
    GURL requestor_url_;
};