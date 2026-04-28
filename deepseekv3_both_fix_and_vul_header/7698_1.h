#include <memory>
#include <string>
#include <mutex>

enum PacketType {
    PrePreparePacket,
    PreparePacket,
    CommitPacket,
    ViewChangePacket,
    NewViewPacket,
    CheckPoint,
    RecoverRequest,
    RecoverResponse
};

class PBFTBaseMessageInterface {
public:
    virtual int view() const = 0;
    virtual PacketType packetType() const = 0;
    virtual int generatedFrom() const = 0;
};

class PBFTMessageInterface : public PBFTBaseMessageInterface {};
class ViewChangeMsgInterface : public PBFTBaseMessageInterface {};
class NewViewMsgInterface : public PBFTBaseMessageInterface {};

class RecursiveGuard {
public:
    RecursiveGuard(std::mutex& m) : m_mutex(m) {}
private:
    std::mutex& m_mutex;
};

class PBFTEngine {
public:
    void handleMsg(std::shared_ptr<PBFTBaseMessageInterface> _msg);
private:
    std::mutex m_mutex;
    int MaxView;
    void handlePrePrepareMsg(std::shared_ptr<PBFTMessageInterface>, bool);
    void handlePrepareMsg(std::shared_ptr<PBFTMessageInterface>);
    void handleCommitMsg(std::shared_ptr<PBFTMessageInterface>);
    void handleViewChangeMsg(std::shared_ptr<ViewChangeMsgInterface>);
    void handleNewViewMsg(std::shared_ptr<NewViewMsgInterface>);
    void handleCheckPointMsg(std::shared_ptr<PBFTMessageInterface>);
    void handleRecoverRequest(std::shared_ptr<PBFTMessageInterface>);
    void handleRecoverResponse(std::shared_ptr<PBFTMessageInterface>);
    std::string printPBFTMsgInfo(std::shared_ptr<PBFTBaseMessageInterface>);
    struct Config {
        struct NodeID {
            std::string hex();
        };
        NodeID* nodeID();
    };
    Config* m_config;
};

class PBFTLog {
public:
    template<typename T>
    PBFTLog& operator<<(const T&) { return *this; }
};

#define WARNING 0
#define LOG_DESC(desc) desc
#define LOG_KV(key, value) key << value
#define PBFT_LOG(level) PBFTLog()