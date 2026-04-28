#include <vector>

#define DCHECK(condition) ((void)0)

class InterstitialPageImpl;

class WebContentsObserver {
public:
    void DidAttachInterstitialPage() {}
};

template<typename T>
class ObserverList {
public:
    T* begin() { return nullptr; }
    T* end() { return nullptr; }
};

class RenderManager {
public:
    void set_interstitial_page(InterstitialPageImpl* page) {}
};

class WebContentsImpl;

class DialogManager {
public:
    void CancelActiveAndPendingDialogs(WebContentsImpl* contents) {}
};

class WebContentsImpl {
public:
    void AttachInterstitialPage(InterstitialPageImpl* interstitial_page);
    RenderManager* GetRenderManager() { return render_manager_; }
    void CancelActiveAndPendingDialogs() {}

    RenderManager* render_manager_;
    DialogManager* dialog_manager_;
    ObserverList<WebContentsObserver> observers_;
};

#define FOR_EACH_OBSERVER(ObserverType, observer_list, method) \
    do { \
        ObserverType* observer; \
        for (observer = (observer_list).begin(); observer != (observer_list).end(); ++observer) \
            observer->method; \
    } while (0)