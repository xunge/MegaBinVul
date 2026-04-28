#include <string>
#include <functional>

class GURL;

struct content {
    class WebContents;
    class RenderFrameHost;
};

class WebstoreStandaloneInstaller {
public:
    using Callback = std::function<void(bool, const std::string&)>;
};

class WebstoreInlineInstaller {
public:
    WebstoreInlineInstaller(content::WebContents* contents,
                          content::RenderFrameHost* host,
                          const std::string& webstore_item_id,
                          const GURL& requestor_url,
                          const WebstoreStandaloneInstaller::Callback& callback);
    
    WebstoreInlineInstaller(content::WebContents* contents,
                          const std::string& webstore_item_id,
                          const GURL& requestor_url,
                          const WebstoreStandaloneInstaller::Callback& callback);
};

class WebstoreInlineInstallerFactory {
public:
    static WebstoreInlineInstaller* CreateInstaller(
        content::WebContents* contents,
        content::RenderFrameHost* host,
        const std::string& webstore_item_id,
        const GURL& requestor_url,
        const WebstoreStandaloneInstaller::Callback& callback);

    static WebstoreInlineInstaller* CreateInstaller(
        content::WebContents* contents,
        const std::string& webstore_item_id,
        const GURL& requestor_url,
        const WebstoreStandaloneInstaller::Callback& callback);
};