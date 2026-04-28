#include <dlfcn.h>
#include <cstring>
#include <string>

typedef void* ModHandle;

class CString {
public:
    void clear();
    unsigned int length() const;
    char operator[](unsigned int) const;
    const char* c_str() const;
    CString(const char*);
    CString(const std::string&);
    CString operator+(const char*) const;
    CString operator+(const CString&) const;
    friend CString operator+(const char*, const CString&);
};

class CModInfo {};
class CTranslationDomainRefHolder {
public:
    CTranslationDomainRefHolder(const CString&);
};
class CModuleEntry {
public:
    const char* pcVersion;
    const char* pcVersionExtra;
    const char* pcCompileOptions;
    void (*fpFillModInfo)(CModInfo&);
};

class CModules {
public:
    bool ValidateModuleName(const CString&, CString&);
    ModHandle OpenModule(const CString&, const CString&, CModInfo&, CString&);
};

class TFunction {
public:
    TFunction(const char*);
    CString operator()(const CString&) const;
    CString operator()(const CString&, const CString&) const;
    CString operator()(const CString&, const char*, const CString&) const;
    CString operator()(const CString&, const char*, const char*) const;
    operator CString() const;
};

TFunction t_f(const char*);
TFunction t_s(const char*);

#define VERSION_STR ""
#define VERSION_EXTRA ""
#define ZNC_COMPILE_OPTIONS_STRING ""