#include <stdbool.h>
#include <dlfcn.h>

class CString {
public:
    void SetName(const CString&);
    void SetPath(const CString&);
};

typedef void* ModHandle;

class CModInfo {
public:
    void SetName(const CString&);
    void SetPath(const CString&);
};

class CModules {
public:
    static bool ValidateModuleName(const CString&, CString&);
    static ModHandle OpenModule(const CString&, const CString&, CModInfo&, CString&);
    bool GetModPathInfo(CModInfo&, const CString&, const CString&, CString&);
};