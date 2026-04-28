#include <string>
#include <vector>
#include <map>

class CString {
public:
    CString(unsigned int count, char ch);
    CString(const char* str);
    CString Replace_n(const char* from, const char* to) const;
    CString operator+(const CString& other) const;
    CString operator+(const std::string& other) const;
    CString operator+(const char* other) const;
};

class CFile {
public:
    void Write(const CString& content);
};

class CConfig;

struct SubConfigInfo {
    CConfig* m_pSubConfig;
};

class CConfig {
private:
    std::map<std::string, std::vector<CString>> m_ConfigEntries;
    std::map<std::string, std::map<std::string, SubConfigInfo>> m_SubConfigs;

public:
    void Write(CFile& File, unsigned int iIndentation);
};