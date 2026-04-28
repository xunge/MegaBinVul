#include <wchar.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>
#include <string.h>

#define NM 1024

typedef unsigned int uint;
typedef wchar_t wchar;

struct FileHeader {
    wchar* FileName;
    bool Dir;
    time_t mtime;
    unsigned int FileAttr;
    uint64_t UnpSize;
};

class CommandData {
private:
    bool ExclCheck(wchar* FileName, bool Dir, bool b1, bool b2);
    bool TimeCheck(time_t mtime);
    bool SizeCheck(uint64_t UnpSize);
    bool CmpName(wchar* ArgName, wchar* FileName, int MatchType);
    int wcsicompc(wchar* s1, wchar* s2);
    void wcsncpyz(wchar* dest, const wchar* src, size_t n);

public:
    class FileArgs {
    public:
        void Rewind();
        wchar* GetString();
    } FileArgs;

    unsigned int ExclFileAttr;
    bool InclAttrSet;
    unsigned int InclFileAttr;

    int IsProcessFile(FileHeader &FileHead, bool *ExactMatch, int MatchType, wchar *MatchedArg, uint MatchedArgSize);
};