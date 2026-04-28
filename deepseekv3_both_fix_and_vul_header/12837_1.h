#include <wchar.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SFX_MODULE
#define _UNIX
#define RARX_SUCCESS 0
#define RARX_USERERROR 1
#define SCAN_SUCCESS 0
#define SILENT
#define NM 1024
#define ASIZE(x) (sizeof(x)/sizeof(x[0]))

typedef int StringList;
typedef int ScanTree;
typedef int FindData;

class CommandData {
public:
    wchar_t* Command;
    wchar_t* ArcName;
    bool GenerateArcName;
    wchar_t* GenerateMask;
    bool Recurse;
    bool SaveSymLinks;
    bool BareOutput;
    void ProcessCommand();
};

void OutHelp(int code);
wchar_t* GetExt(const wchar_t* name);
bool FileExist(const wchar_t* name);
int GetFileAttr(const wchar_t* name);
bool IsDir(int attr);
void wcsncatz(wchar_t* dest, const wchar_t* src, size_t size);
int wcsnicomp(const wchar_t* s1, const wchar_t* s2, size_t n);
bool IsDigit(wchar_t c);
void GenerateArchiveName(wchar_t* name, size_t size, const wchar_t* mask, bool append);
void AddArcName(const wchar_t* name);
void mprintf(const wchar_t* format, ...);

class CmdExtract {
public:
    CmdExtract(CommandData* cmd);
    void DoExtract();
};

void ListArchive(CommandData* cmd);