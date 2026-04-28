#include <wchar.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define USE_QOPEN
#define USE_ARCMEM
#define ASIZE(arr) (sizeof(arr)/sizeof(arr[0]))

typedef unsigned int uint;
typedef wchar_t wchar;

class File {
public:
    bool Open(const wchar *Name, uint Mode);
};

class Archive : public File {
public:
    bool Open(const wchar *Name, uint Mode);
};

class QOpenClass {
public:
    void Unload();
} QOpen;

class ArcMemClass {
public:
    void Load(void *data, size_t size);
} ArcMem;

class CmdClass {
public:
    bool ArcInMem;
    void *ArcMemData;
    size_t ArcMemSize;
    
    void SetArcInMem(void *data, size_t size);
} *Cmd;

wchar FileName[260];

inline void wcsncpyz(wchar *dest, const wchar *src, size_t n) {
    wcsncpy(dest, src, n);
    dest[n-1] = L'\0';
}