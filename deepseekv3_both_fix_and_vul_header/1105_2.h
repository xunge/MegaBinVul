#include <memory>

class ViewChangeMsgInterface {
public:
    class Ptr;
    virtual int from() = 0;
    virtual int index() = 0;
    virtual int generatedFrom() = 0;
};

class ViewChangeMsgInterface::Ptr : public std::shared_ptr<ViewChangeMsgInterface> {
public:
    using std::shared_ptr<ViewChangeMsgInterface>::shared_ptr;
};

class CacheProcessor {
public:
    void addViewChangeReq(ViewChangeMsgInterface::Ptr);
    int tryToTriggerFastViewChange();
    ViewChangeMsgInterface::Ptr checkAndTryIntoNewView();
};

class Config {
public:
    int leaderIndexInNewViewPeriod(int, int);
    int getLeader();
};

class PBFTEngine {
public:
    bool handleViewChangeMsg(ViewChangeMsgInterface::Ptr _viewChangeMsg);
private:
    CacheProcessor* m_cacheProcessor;
    Config* m_config;
    bool isValidViewChangeMsg(int, ViewChangeMsgInterface::Ptr);
    void triggerTimeout();
    void reHandlePrePrepareProposals(ViewChangeMsgInterface::Ptr);
};