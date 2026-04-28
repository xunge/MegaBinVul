#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class GURL {
public:
    explicit GURL(const GURL& other);
    std::string possibly_invalid_spec() const;
};

class RenderProcessHost {};

class RenderViewHost {
public:
    RenderProcessHost* GetProcess();
    static void FilterURL(RenderProcessHost* process, bool empty_allowed, GURL* url);
};

class WebContentsObserver {
public:
    void DidFailProvisionalLoad(int frame_id, bool is_main_frame, const GURL& url,
                               int error_code, const std::string& error_description,
                               RenderViewHost* render_view_host);
};

class NavigationController {
public:
    void* GetPendingEntry();
    void* GetVisibleEntry();
    void DiscardPendingEntry();
};

struct ViewHostMsg_DidFailProvisionalLoadWithError_Params {
    GURL url;
    int error_code;
    std::string error_description;
    bool is_main_frame;
    bool showing_repost_interstitial;
    int frame_id;
};

class WebContentsImpl {
public:
    void DidFailProvisionalLoadWithError(RenderViewHost* render_view_host,
                                       const ViewHostMsg_DidFailProvisionalLoadWithError_Params& params);
    NavigationController controller_;
    std::vector<WebContentsObserver*> observers_;
    bool ShowingInterstitialPage();
    
    class RenderManager {
    public:
        void RendererAbortedProvisionalLoad(RenderViewHost* render_view_host);
    } render_manager_;
};

namespace net {
    const int ERR_ABORTED = -3;
}

#define VLOG(level) std::cout
#define LOG(level) std::cout
#define WARNING 1
#define FOR_EACH_OBSERVER(ObserverType, observer_list, func) \
    std::for_each(observer_list.begin(), observer_list.end(), \
        [&](ObserverType* observer) { observer->func; })