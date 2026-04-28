#include <map>

class UnderlyingPageType;

class CPDFSDK_PageView {
public:
    bool IsLocked();
    void KillFocusAnnotIfNeeded();
    ~CPDFSDK_PageView();
};

class CPDFSDK_Document {
public:
    void RemovePageView(UnderlyingPageType* pUnderlyingPage);
protected:
    std::map<UnderlyingPageType*, CPDFSDK_PageView*> m_pageMap;
};