#include <vector>

namespace base {
enum TerminationStatus {
    TERMINATION_STATUS_NORMAL_TERMINATION,
    TERMINATION_STATUS_ABNORMAL_TERMINATION,
    TERMINATION_STATUS_PROCESS_WAS_KILLED,
    TERMINATION_STATUS_PROCESS_CRASHED,
    TERMINATION_STATUS_STILL_RUNNING
};
}

class WebContentsImpl;

class RenderViewHost;
class WebContentsObserver {
public:
    void RenderProcessGone(base::TerminationStatus status);
};

class WebContentsDelegate {
public:
    virtual void HideValidationMessage(WebContentsImpl* contents) = 0;
};

class DialogManager {
public:
    virtual void CancelActiveAndPendingDialogs(WebContentsImpl* contents) = 0;
};

#define FOR_EACH_OBSERVER(ObserverType, observer_list, func) \
    do { \
        for (ObserverType& observer : observer_list) \
            observer.func; \
    } while (0)

class WebContentsImpl {
public:
    void RenderViewTerminated(RenderViewHost* rvh, base::TerminationStatus status, int error_code);
    RenderViewHost* GetRenderViewHost();
    bool IsFullscreenForCurrentTab();
    void ExitFullscreenMode();
    void CancelActiveAndPendingDialogs();
    void SetIsLoading(bool loading, bool to_different_document, RenderViewHost* rvh);
    void NotifyDisconnected();
    void SetIsCrashed(base::TerminationStatus status, int error_code);
    base::TerminationStatus GetCrashedStatus();
    void ResetLoadProgressState();

    WebContentsDelegate* delegate_;
    DialogManager* dialog_manager_;
    std::vector<WebContentsObserver> observers_;
};