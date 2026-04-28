#include <stdbool.h>
#include <cstddef>

#define PFB_MARKER 0x80
#define PFB_ASCII 1
#define PFB_BINARY 2
#define PFB_DONE 3

struct CFontFileType1 {
    bool m_bFreeFileData;
    unsigned char* m_sFile;
    unsigned char* m_sFileData;
    int m_nLen;
    int m_nPos;
    bool RemovePfbMarkers();
};

extern int ReadU8(bool* bSuccess);
extern int ReadU32LE(bool* bSuccess);
extern void Read(unsigned char* buffer, int length);
extern void* MemUtilsMalloc(int size);
extern void* MemUtilsRealloc(void* ptr, int size);
extern void MemUtilsFree(void* ptr);