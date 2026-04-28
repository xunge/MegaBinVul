#include <vector>

struct LoadCommittedDetails {
    bool is_in_page;
};

struct FrameHostMsg_DidCommitProvisionalLoad_Params {
};

class RenderFrameHostImpl;
class WebContentsImpl;

class WebContentsObserver {
public:
    virtual void DidNavigateAnyFrame(RenderFrameHostImpl*, const LoadCommittedDetails&, const FrameHostMsg_DidCommitProvisionalLoad_Params&) = 0;
};

class DialogManager {
public:
    void CancelActiveAndPendingDialogs(WebContentsImpl*);
};

#define FOR_EACH_OBSERVER(observer_type, observer_list, func) \
    for (auto* observer : observer_list) \
        observer->func

class WebContentsImpl {
public:
    void DidNavigateAnyFramePostCommit(
        RenderFrameHostImpl* render_frame_host,
        const LoadCommittedDetails& details,
        const FrameHostMsg_DidCommitProvisionalLoad_Params& params);
    void CancelActiveAndPendingDialogs();

protected:
    std::vector<WebContentsObserver*> observers_;
    bool has_accessed_initial_document_;
    DialogManager* dialog_manager_;
};