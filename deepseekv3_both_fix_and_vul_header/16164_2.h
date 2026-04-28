#include <string>

namespace WindowOpenDisposition {
enum Disposition {
    CURRENT_TAB
};
}  // namespace WindowOpenDisposition

namespace content {
class WebContents;

struct Referrer {
};

struct OpenURLParams {
    WindowOpenDisposition::Disposition disposition;
    std::string url;
    Referrer referrer;
    std::string post_data;
};
}  // namespace content

class CommonWebContentsDelegate {
public:
    static content::WebContents* OpenURLFromTab(content::WebContents* source,
                                              const content::OpenURLParams& params);
};

class WebContents {
public:
    content::WebContents* OpenURLFromTab(content::WebContents* source,
                                       const content::OpenURLParams& params);
    bool IsDestroyed();
    bool Emit(const std::string& event, const std::string& url = "",
             const std::string& frame_name = "",
             WindowOpenDisposition::Disposition disposition = WindowOpenDisposition::CURRENT_TAB,
             const std::string& features = "", const content::Referrer& referrer = content::Referrer(),
             const std::string& post_data = "");
};