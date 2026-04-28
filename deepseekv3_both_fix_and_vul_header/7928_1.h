#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ODBC_FILENAME_MAX 256
#define INI_SUCCESS 0
#define LOG_CRITICAL 2
#define ODBC_ERROR_INVALID_PATH 1
#define ODBC_ERROR_REQUEST_FAILED 2

typedef void* HINI;
typedef const char* LPCSTR;
typedef int BOOL;
#define TRUE 1
#define FALSE 0

void _odbcinst_FileINI(char* path);
void inst_logPushMsg(const char* file1, const char* file2, int line, int level, int error, const char* msg);
int iniOpen(HINI* hIni, const char* filename, const char* comment, char openBracket, char closeBracket, char equals, bool create);
int iniObjectSeek(HINI hIni, char* section);
void iniObjectDelete(HINI hIni);
int iniPropertySeek(HINI hIni, char* section, char* key, char* value);
void iniPropertyDelete(HINI hIni);
void iniObjectInsert(HINI hIni, char* section);
void iniPropertyUpdate(HINI hIni, char* key, char* value);
void iniPropertyInsert(HINI hIni, char* key, char* value);
int iniCommit(HINI hIni);
void iniClose(HINI hIni);