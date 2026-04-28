#include <stdbool.h>
#include <string>

class CString {
public:
    CString();
    CString(const char*);
    CString& operator()(const CString&);
};

class CModInfo {};

class CModules {
public:
    bool GetModInfo(CModInfo& ModInfo, const CString& sModule, CString& sRetMsg);
    bool ValidateModuleName(const CString& sModule, CString& sRetMsg);
    bool FindModPath(const CString& sModule, CString& sModPath, CString& sTmp);
    bool GetModPathInfo(CModInfo& ModInfo, const CString& sModule, const CString& sModPath, CString& sRetMsg);
};

#define GLOBALMODULECALL(call, handled)
#define t_f(str) CString(str)