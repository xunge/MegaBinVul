#include <wchar.h>
#include <stdbool.h>

#define ASIZE(x) (sizeof(x)/sizeof(x[0]))
#define RCLM_REJECT_LISTS 0
#define RCLM_ACCEPT_LISTS 1

typedef wchar_t wchar;

struct FindData {
    bool IsDir;
};

class StringList {
public:
    void AddString(wchar* arg);
};

class FindFile {
public:
    static bool FastFind(const wchar* name, FindData* data);
};

class CommandData {
private:
    wchar* Command;
    wchar* ArcName;
    wchar* ExtrPath;
    bool NoMoreSwitches;
    int ListMode;
    bool FileLists;
    int FilelistCharset;
    StringList FileArgs;
public:
    void ParseArg(wchar *Arg);
    bool IsSwitch(wchar c);
    void ProcessSwitch(wchar* arg);
};

bool IsDriveDiv(wchar c);
bool IsPathDiv(wchar c);
bool IsWildcard(const wchar* str);
wchar toupperw(wchar c);
void wcsupper(wchar* str);
void wcsncpyz(wchar* dest, const wchar* src, size_t size);
void AddEndSlash(wchar* path, size_t size);
void ReadTextFile(const wchar* name, StringList* fileArgs, bool b1, bool b2, int charset, bool b3, bool b4, bool b5);