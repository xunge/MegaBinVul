#include <string>
#include <memory>
#include <map>
#include <vector>

class CWebSock;
class CTemplate;
class CIRCNetwork;
class CModule;

class CString {
public:
    CString();
    CString(const char*);
    CString(const std::string&);
    CString(unsigned int);
    CString operator+(const char*) const;
    CString operator+(const CString&) const;
    friend CString operator+(const char*, const CString&);
    unsigned int ToUInt() const;
    bool ToBool() const;
    CString Trim_n() const;
    CString Escape_n(int) const;
    CString Token(int) const;
    bool empty() const;
    operator std::string() const;
    static const int EURL;
};

class CWebSession {
public:
    bool IsAdmin() const;
};

template<typename T>
class CSmartPtr {
public:
    CSmartPtr(T*);
    T* operator->() const;
};

class CUser {
public:
    CString GetUserName() const;
    unsigned int GetBufferCount() const;
    CString GetDefaultChanModes() const;
    bool AutoClearChanBuffer() const;
};

class CChan {
public:
    CChan(const CString&, CIRCNetwork*, bool);
    CString GetName() const;
    unsigned int GetBufferCount() const;
    CString GetDefaultModes() const;
    CString GetKey() const;
    bool InConfig() const;
    bool AutoClearChanBuffer() const;
    bool IsDetached() const;
    bool IsDisabled() const;
    void SetBufferCount(unsigned int, bool);
    void SetDefaultModes(const CString&);
    void SetInConfig(bool);
    void SetAutoClearChanBuffer(bool);
    void SetKey(const CString&);
    void DetachUser();
    void AttachUser();
    void Disable();
    void Enable();
};

class CIRCNetwork {
public:
    CUser* GetUser() const;
    CString GetName() const;
    bool FindChan(const CString&) const;
    bool AddChan(CChan*);
    std::vector<CModule*> GetModules() const;
};

class CModule {
public:
    bool OnEmbeddedWebRequest(CWebSock&, const std::string&, CTemplate&);
    CString GetModName() const;
};

class CTemplate {
public:
    void SetFile(const std::string&);
    CTemplate& AddRow(const std::string&);
    std::map<std::string, std::string>::iterator begin();
    std::map<std::string, std::string>::iterator end();
    void insert(std::map<std::string, std::string>::iterator, std::map<std::string, std::string>::iterator);
    std::string& operator[](const std::string&);
};

class CWebSock {
public:
    CSmartPtr<CWebSession> GetSession();
    CString GetParam(const std::string&) const;
    void PrintErrorPage(const CString&);
    CString FindTmpl(CModule*, const std::string&);
    void Redirect(const CString&);
    CString GetWebPath() const;
};

class CZNC {
public:
    static CZNC& Get();
    bool WriteConfig();
};

#define FOR_EACH_MODULE(iter, network) \
    for (auto iter = (network)->GetModules().begin(); iter != (network)->GetModules().end(); ++iter)

inline CString operator+(const char* lhs, const CString& rhs) {
    return CString(lhs) + rhs;
}

inline CString GetWebPath() {
    return CString("/znc/");
}