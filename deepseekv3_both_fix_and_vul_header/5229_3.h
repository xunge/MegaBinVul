#include <string>
#include <vector>
#include <map>
#include <sstream>

class CString {
public:
    static const size_t npos = static_cast<size_t>(-1);
    
    CString();
    CString(const char* str);
    CString(const std::string& str);
    CString(bool b);
    CString(int i);
    CString(unsigned int i);
    CString operator()(const CString& arg) const;
    CString Token(unsigned int n, bool rest = false) const;
    CString AsLower() const;
    bool empty() const;
    bool Equals(const CString& str) const;
    bool ToBool() const;
    unsigned int ToUInt() const;
    size_t find_first_of(const char* chars) const;
    bool operator==(const char* str) const;
    CString operator+(const CString& str) const;
    friend CString operator+(const char* lhs, const CString& rhs);
};

typedef std::vector<CString> VCString;

class CUser {
public:
    enum { HASH_DEFAULT };
    
    void SetNick(const CString& nick);
    void SetAltNick(const CString& altnick);
    void SetIdent(const CString& ident);
    void SetRealName(const CString& realname);
    void SetBindHost(const CString& bindhost);
    bool DenySetBindHost() const;
    CString GetBindHost() const;
    void SetMultiClients(bool multi);
    void SetDenyLoadMod(bool deny);
    void SetDenySetBindHost(bool deny);
    void SetDefaultChanModes(const CString& modes);
    void SetQuitMsg(const CString& msg);
    bool SetChanBufferSize(unsigned int size, bool admin);
    bool SetQueryBufferSize(unsigned int size, bool admin);
    void SetAutoClearChanBuffer(bool clear);
    void SetAutoClearQueryBuffer(bool clear);
    static CString SaltedHash(const CString& pass, const CString& salt);
    void SetPass(const CString& hash, int type, const CString& salt);
    void SetMaxJoins(unsigned int max);
    unsigned int MaxJoins() const;
    void SetNoTrafficTimeout(unsigned int timeout);
    unsigned int GetNoTrafficTimeout() const;
    void SetMaxNetworks(unsigned int max);
    void SetMaxQueryBuffers(unsigned int max);
    void SetJoinTries(unsigned int tries);
    unsigned int JoinTries() const;
    void SetTimezone(const CString& tz);
    CString GetTimezone() const;
    void SetAdmin(bool admin);
    bool IsAdmin() const;
    void SetTimestampPrepend(bool prepend);
    void SetTimestampAppend(bool append);
    void SetAuthOnlyViaModule(bool auth);
    void SetTimestampFormat(const CString& format);
    void SetDCCBindHost(const CString& host);
    void SetStatusPrefix(const CString& prefix);
    void SetLanguage(const CString& lang);
    void SetClientEncoding(const CString& encoding);
    CString GetClientEncoding() const;
};

class CUtils {
public:
    static CString GetSalt();
};

class CTranslationInfo {
public:
    static std::map<CString, CString> GetTranslations();
};

class CZNC {
public:
    static CZNC& Get();
    unsigned int GetMaxBufferSize() const;
};

CUser* FindUser(const CString& name);
CUser* GetUser();
void PutModule(const CString& message);
CString t_s(const char* msg);
CString t_f(const char* msg);

inline CString operator+(const char* lhs, const CString& rhs) {
    return CString(lhs) + rhs;
}