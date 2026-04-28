#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint32_t sal_uInt32;
typedef uint16_t sal_uInt16;
#define sal_False false
#define sal_True true

class LwpObjectStream {
public:
    void QuickRead(void*, size_t);
};

class LwpFileHeader {
public:
    static sal_uInt32 m_nFileRevision;
};

class LwpGlobalMgr {
public:
    static LwpGlobalMgr* GetInstance();
    class LwpObjectFactory* GetLwpObjFactory();
};

class LwpObjectFactory {
public:
    class LwpIndexManager* GetIndexManager();
};

class LwpIndexManager {
public:
    sal_uInt32 GetObjTime(sal_uInt16);
};

class LwpObjectID {
public:
    sal_uInt32 ReadIndexed(LwpObjectStream* pStrm);
    sal_uInt32 Read(LwpObjectStream* pStrm);
    sal_uInt32 DiskSizeIndexed();
    
private:
    bool m_bIsCompressed;
    sal_uInt32 m_nIndex;
    sal_uInt32 m_nLow;
    sal_uInt32 m_nHigh;
};