#include <string>
#include <dlfcn.h>
#include <vector>

class CString {
public:
    CString();
    CString(const char*);
    CString& operator=(const char*);
    CString operator+(const CString&) const;
    CString& operator+=(const CString&);
    CString& operator+=(const char*);
    bool empty() const;
    friend CString operator+(const char*, const CString&);
};

class CUser;
class CIRCNetwork;
class CModInfo;
class CModule;
class CZNC;
class CDir;

typedef void* ModHandle;

namespace {
    class t_f {
    public:
        t_f(const char*) {}
        CString operator()(const CString&) { return CString(); }
        CString operator()(const CString&, const CString&) { return CString(); }
    };
    class t_s {
    public:
        t_s(const char*) {}
        operator CString() { return CString(); }
    };
}

class CModInfo {
public:
    enum EModuleType { UserModule, NetworkModule };
    static CString ModuleTypeToString(EModuleType);
    void SetName(const CString&);
    void SetPath(const CString&);
    bool SupportsType(EModuleType);
    CModule* (*GetLoader())(ModHandle, CUser*, CIRCNetwork*, const CString&, const CString&, EModuleType);
    CString GetDescription();
};

class CModule {
public:
    class EModException {};
    void SetDescription(const CString&);
    void SetArgs(const CString&);
    void SetModPath(const CString&);
    bool OnLoad(const CString&, CString&);
};

class CModules {
public:
    bool LoadModule(const CString&, const CString&, CModInfo::EModuleType, CUser*, CIRCNetwork*, CString&);
    bool ValidateModuleName(const CString&, CString&);
    CModule* FindModule(const CString&);
    bool FindModPath(const CString&, CString&, CString&);
    ModHandle OpenModule(const CString&, const CString&, CModInfo&, CString&);
    void UnloadModule(const CString&, const CString&);
    void push_back(CModule*);
};

class CDir {
public:
    static CString ChangeDir(const CString&, const CString&);
};

class CZNC {
public:
    static CZNC& Get();
    CString GetCurPath();
};

inline CString operator+(const char* lhs, const CString& rhs) {
    return CString(lhs) + rhs;
}

#define _GLOBALMODULECALL(call, user, network, client, handled)