#include <string>

class CString {
public:
    void Replace(const std::string& from, const std::string& to);
    void TrimRight(const std::string& chars);
};

class CNetwork;
class CUser;

class CMessage {
public:
    enum class Type {
        Account,
        Action,
        Away,
        Capability,
        CTCP,
        Error,
        Invite,
        Join,
        Kick,
        Mode,
        Nick,
        Notice,
        Numeric,
        Part,
        Ping,
        Pong,
        Quit,
        Text,
        Topic,
        Wallops
    };
    CMessage(const CString& sLine);
    Type GetType() const;
    void SetNetwork(CNetwork* pNetwork);
};

class CNetwork {
public:
    CString GetName() const;
    CUser* GetUser() const;
    void PutUser(const CMessage& Message);
};

class CUser {
public:
    CString GetUserName() const;
};

class CIRCSock {
public:
    void ReadLine(const CString& sData);
    bool OnAccountMessage(const CMessage& Message);
    bool OnActionMessage(const CMessage& Message);
    bool OnAwayMessage(const CMessage& Message);
    bool OnCapabilityMessage(const CMessage& Message);
    bool OnCTCPMessage(const CMessage& Message);
    bool OnErrorMessage(const CMessage& Message);
    bool OnInviteMessage(const CMessage& Message);
    bool OnJoinMessage(const CMessage& Message);
    bool OnKickMessage(const CMessage& Message);
    bool OnModeMessage(const CMessage& Message);
    bool OnNickMessage(const CMessage& Message);
    bool OnNoticeMessage(const CMessage& Message);
    bool OnNumericMessage(const CMessage& Message);
    bool OnPartMessage(const CMessage& Message);
    bool OnPingMessage(const CMessage& Message);
    bool OnPongMessage(const CMessage& Message);
    bool OnQuitMessage(const CMessage& Message);
    bool OnTextMessage(const CMessage& Message);
    bool OnTopicMessage(const CMessage& Message);
    bool OnWallopsMessage(const CMessage& Message);
    bool OnRaw(const CString& sLine);
    bool OnRawMessage(const CMessage& Message);
    CNetwork* m_pNetwork;
};

#define DEBUG(x)
#define IRCSOCKMODULECALL(x, y)