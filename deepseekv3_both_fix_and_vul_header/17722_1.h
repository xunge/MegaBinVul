#include <vector>
#include <string>

class CMessage {
public:
    std::string GetParam(int index) const;
    void SetNick(const std::string& nick);
};

class CNetwork {
public:
    bool IsChan(const std::string& name) const;
};

class CClient {
public:
    void EchoMessage(const CMessage& Message);
    std::string GetNickMask() const;
    bool HasEchoMessage() const;
    bool HasSelfMessage() const;
    void PutClient(const CMessage& message);
    std::vector<CClient*> GetClients() const;

private:
    CNetwork* m_pNetwork;
};