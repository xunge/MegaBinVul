#include <string>
#include <utility>
#include <vector>

namespace content {
class WebContents {
public:
    class BrowserContext* GetBrowserContext();
};
class BrowserContext;
class WebUIController {
public:
    virtual ~WebUIController();
};
class WebUI {
public:
    WebContents* GetWebContents();
};
}  // namespace content

namespace net {
struct UnescapeRule {
    enum Type {
        NORMAL = 1 << 0,
        SPACES = 1 << 1,
        PATH_SEPARATORS = 1 << 2,
        URL_SPECIAL_CHARS_EXCEPT_PATH_SEPARATORS = 1 << 3,
        REPLACE_PLUS_WITH_SPACE = 1 << 4,
        SPOOFING_AND_CONTROL_CHARS = 1 << 5
    };
};
inline UnescapeRule::Type operator|(UnescapeRule::Type a, UnescapeRule::Type b) {
    return static_cast<UnescapeRule::Type>(static_cast<int>(a) | static_cast<int>(b));
}
std::string UnescapeURLComponent(const std::string& component, net::UnescapeRule::Type rules);
}  // namespace net

class GURL {
public:
    std::string host() const;
    std::string query() const;
    bool has_ref() const;
    std::string ref() const;
};

namespace base {
using StringPairs = std::vector<std::pair<std::string, std::string>>;
void SplitStringIntoKeyValuePairs(const std::string& input, char key_value_delimiter, char key_value_pair_delimiter, StringPairs* key_value_pairs);
}  // namespace base

class AtomWebUIControllerFactory {
public:
    content::WebUIController* CreateWebUIControllerForURL(content::WebUI* web_ui, const GURL& url) const;
};

class PdfViewerUI : public content::WebUIController {
public:
    PdfViewerUI(content::BrowserContext* browser_context, content::WebUI* web_ui, const std::string& src);
};

extern const char kPdfViewerUIHost[];
extern const char kPdfPluginSrc[];