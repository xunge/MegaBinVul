#include <vector>
#include <string>
#include <memory>

class GURL {
public:
    GURL();
};

class RenderViewHost {};

class RenderFrameHostImpl {
public:
    RenderViewHost* GetRenderViewHost();
};

class RenderWidgetHostViewBase {
public:
    void OnDidNavigateMainFrameToNewPage();
};

struct LoadCommittedDetails {
    bool is_navigation_to_different_page() const;
    bool is_in_page;
};

struct FrameHostMsg_DidCommitProvisionalLoad_Params {};

class WebContentsImpl;

class WebContentsObserver {
public:
    void DidNavigateMainFrame(const LoadCommittedDetails& details, 
                            const FrameHostMsg_DidCommitProvisionalLoad_Params& params);
};

class WebContentsDelegate {
public:
    void DidNavigateMainFramePostCommit(WebContentsImpl* contents);
};

class SSLManager {
public:
    static void NotifySSLInternalStateChanged(void* context);
};

template <typename T>
class ObserverList {
public:
    typedef T Observer;
    typedef typename std::vector<T*>::iterator iterator;
    iterator begin();
    iterator end();
};

#define FOR_EACH_OBSERVER(ObserverType, observer_list, func) \
    do { \
        for (ObserverType* observer : observer_list) \
            observer->func; \
    } while (0)

class WebContentsView;

class WebContentsImpl {
public:
    void DidNavigateMainFramePostCommit(
        RenderFrameHostImpl* render_frame_host,
        const LoadCommittedDetails& details,
        const FrameHostMsg_DidCommitProvisionalLoad_Params& params);
    void UpdateTargetURL(RenderViewHost* render_view_host, const GURL& url);
    RenderWidgetHostViewBase* GetRenderWidgetHostView();
    bool CanOverscrollContent() const;
    
    class Controller {
    public:
        void* GetBrowserContext() const;
    };
    Controller& GetController();

    ObserverList<WebContentsObserver> observers_;
    WebContentsDelegate* delegate_;
    bool displayed_insecure_content_;
    WebContentsView* view_;
};

class WebContentsView {
public:
    void SetOverscrollControllerEnabled(bool enabled);
};