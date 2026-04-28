#include <vector>
#include <string>

class CString;
class CTextMessage;
class CMessage;

typedef std::vector<CString> VCString;

#define CALLMOD(x, y, z, w, f)
#define NETWORKMODULECALL(x, y, z, w, f)
#define t_f(x) CString(x)

class CString {
public:
    void Split(const char*, VCString&, bool);
    bool TrimPrefix(const CString&);
    bool Equals(const CString&) const;
    bool Equals(const char*) const;
    CString(const char*);
    CString operator()(const CString&) const;
};

class CTextMessage {
public:
    CString GetTarget() const;
    void SetTarget(const CString&);
    void SetChan(void*);
    CString GetText() const;
    CString ToString(int) const;
};

class CUser {
public:
    CString GetStatusPrefix() const;
};

class CNetwork {
public:
    void* FindChan(const CString&);
};

class CClient {
protected:
    CUser* m_pUser;
    CNetwork* m_pNetwork;
    CString m_sNick;
    
    void UserCommand(const CString&);
    void PutStatus(const CString&);
    bool GetIRCSock() const;
    void AddBuffer(const CTextMessage&);
    void EchoMessage(const CTextMessage&);
    void PutIRC(const CString&);
public:
    bool OnTextMessage(CTextMessage&);
};

class CMessage {
public:
    static const int ExcludePrefix;
    static const int ExcludeTags;
};

const int CMessage::ExcludePrefix = 0;
const int CMessage::ExcludeTags = 0;