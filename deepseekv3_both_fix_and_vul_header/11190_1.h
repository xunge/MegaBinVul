#include <string>

#define _SKINDIR_ "skindir"

class CString {
public:
    CString(const char* str);
    CString(const std::string& str);
    CString Replace_n(const char* from, const char* to) const;
    CString operator+(const CString& other) const;
    const char* c_str() const;
};

class CFile {
public:
    static bool IsDir(const CString& path);
};

class CZNC {
public:
    static CZNC& Get();
    CString GetZNCPath() const;
    CString GetCurPath() const;
};

class CWebSock {
public:
    CString GetSkinPath(const CString& sSkinName);
};