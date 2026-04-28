#include <stdbool.h>
#include <assert.h>

#define DCHECK assert

struct FrameHostMsg_DidCommitProvisionalLoad_Params {
    const char* url;
    bool was_within_same_page;
};

enum NavigationType {
    NAVIGATION_TYPE_UNKNOWN
};

class RenderViewHost {
public:
    void ExitFullscreen();
};

class NavigationController {
public:
    bool IsURLInPageNavigation(const char* url, bool was_within_same_page, NavigationType type);
};

class WebContentsImpl {
public:
    bool IsFullscreenForCurrentTab();
    RenderViewHost* GetRenderViewHost();
    void DidNavigateMainFramePreCommit(bool navigation_is_within_page);
    void DidNavigateMainFramePreCommit(const FrameHostMsg_DidCommitProvisionalLoad_Params& params);
    NavigationController controller_;
};