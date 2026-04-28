#include <string>

namespace content {
struct LoadCommittedDetails {};
struct FrameNavigateParams {
    struct GURL {
        std::string url;
        std::string GetOrigin() const { return url; }
        operator std::string() const { return url; }
    } url;
};
}

namespace ui_zoom {
class ZoomController {
public:
    static ZoomController* FromWebContents(void* web_contents);
    void SetZoomMode(int mode);
    static const int ZOOM_MODE_ISOLATED;
};
}

namespace bad_message {
enum BadMessageReason {
    EOG_BAD_ORIGIN
};
void ReceivedBadMessage(void* render_process_host, BadMessageReason reason);
}

namespace url {
bool IsSameOriginWith(const std::string& url1, const std::string& url2);
}

class WebContents {
public:
    void* GetRenderProcessHost();
};

class ExtensionOptionsGuest {
public:
    void DidNavigateMainFrame(const content::LoadCommittedDetails& details,
                            const content::FrameNavigateParams& params);
    bool attached() const;
    WebContents* web_contents() const;
    void SetGuestZoomLevelToMatchEmbedder();
    struct GURL {
        std::string url;
        std::string GetOrigin() const { return url; }
        operator std::string() const { return url; }
    } options_page_;
};