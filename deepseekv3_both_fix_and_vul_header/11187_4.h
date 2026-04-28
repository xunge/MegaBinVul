#include <string>

class CString {
public:
    void Replace(const char*, const char*);
    void TrimRight(const char*);
    bool Equals(const char*) const;
    const char* c_str() const;
    operator std::string() const;
    bool empty() const;
};

class CMessage {
public:
    enum class Type {
        Action,
        CTCP,
        Join,
        Mode,
        Notice,
        Part,
        Ping,
        Pong,
        Quit,
        Text,
        Topic,
        Capability
    };
    enum FormatFlags {
        ExcludePrefix = 1,
        ExcludeTags = 2
    };
    CMessage(const CString&);
    void SetClient(class CClient*);
    CString GetCommand() const;
    CString GetParam(int) const;
    Type GetType() const;
    CString ToString(int) const;
};

class CUser {
public:
    std::string GetLanguage() const;
};

class CClient {
public:
    void ReadLine(const CString&);
    bool IsAttached() const;
    CString GetFullName() const;
    CUser* GetUser() const;
    void PutIRC(const CString&);
    void ParsePass(const CString&);
    void ParseUser(const CString&);
    void AuthUser();
    void SendRequiredPasswordNotice();
    void HandleCap(const CMessage&);
    bool OnActionMessage(const CMessage&);
    bool OnCTCPMessage(const CMessage&);
    bool OnJoinMessage(const CMessage&);
    bool OnModeMessage(const CMessage&);
    bool OnNoticeMessage(const CMessage&);
    bool OnPartMessage(const CMessage&);
    bool OnPingMessage(const CMessage&);
    bool OnPongMessage(const CMessage&);
    bool OnQuitMessage(const CMessage&);
    bool OnTextMessage(const CMessage&);
    bool OnTopicMessage(const CMessage&);
    bool OnOtherMessage(const CMessage&);
    
    CUser* m_pUser;
    class CNetwork* m_pNetwork;
    std::string m_sNick;
    std::string m_sUser;
    bool m_bGotPass;
    bool m_bGotNick;
    bool m_bGotUser;
    bool m_bInCap;
};

class CLanguageScope {
public:
    CLanguageScope(const std::string&);
};

class CDebug {
public:
    static CString Filter(const CString&);
};

#define DEBUG(x)
#define NETWORKMODULECALL(x, y, z, w, v)
#define GLOBALMODULECALL(x, y)