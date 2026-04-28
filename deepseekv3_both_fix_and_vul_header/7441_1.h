#include <memory>

class ViewChangeMsgInterface {
public:
    using Ptr = std::shared_ptr<ViewChangeMsgInterface>;
    virtual int from() const = 0;
    virtual int index() const = 0;
    virtual int view() const = 0;
    virtual int generatedFrom() const = 0;
};

class CacheProcessor {
public:
    void addViewChangeReq(ViewChangeMsgInterface::Ptr _viewChangeMsg);
    int getViewChangeWeight(int view);
    int tryToTriggerFastViewChange();
    ViewChangeMsgInterface::Ptr checkAndTryIntoNewView();
};

class Config {
public:
    int leaderIndexInNewViewPeriod(int a, int b);
    int maxFaultyQuorum();
};

class PBFTEngine {
protected:
    std::shared_ptr<CacheProcessor> m_cacheProcessor;
    std::shared_ptr<Config> m_config;

    bool isValidViewChangeMsg(int from, ViewChangeMsgInterface::Ptr _viewChangeMsg);
    void triggerTimeout(bool flag = false);
    void reHandlePrePrepareProposals(ViewChangeMsgInterface::Ptr newViewMsg);
public:
    bool handleViewChangeMsg(ViewChangeMsgInterface::Ptr _viewChangeMsg);
};