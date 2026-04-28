#include <stdlib.h>
#include <wchar.h>

#define CP_UTF8 65001
#define LOCAL static
typedef wchar_t* LPWSTR;

int MultiByteToWideChar(unsigned int CodePage, unsigned long dwFlags,
                       const char* lpMultiByteStr, int cbMultiByte,
                       wchar_t* lpWideCharStr, int cchWideChar);