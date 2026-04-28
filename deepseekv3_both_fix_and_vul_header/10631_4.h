#include <string>

struct SHFILEOPSTRUCT {
    void* hwnd;
    unsigned int wFunc;
    const wchar_t* pFrom;
    const wchar_t* pTo;
    unsigned short fFlags;
    bool fAnyOperationsAborted;
    void* hNameMappings;
    const wchar_t* lpszProgressTitle;
};

#define FO_DELETE 3
#define FOF_NO_UI 0x00001000
#define FOF_SILENT 0x0004
#define FOF_NOCONFIRMATION 0x0010
#define FOF_NOERRORUI 0x0400

class Win32Exception {};
class Settings {
public:
    static bool ReadConfigValue(const char*, std::wstring&);
    static void DeleteConfigValue(const char*);
};

class UpdateDownloader {
public:
    static std::wstring GetUniqueTempDirectoryPrefix();
    void CleanLeftovers();
};

extern "C" int SHFileOperation(SHFILEOPSTRUCT*);