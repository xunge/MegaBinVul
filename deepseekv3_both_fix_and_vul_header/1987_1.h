#include <stdint.h>

typedef uint8_t sal_Bool;
#define sal_False 0
#define sal_True 1
typedef uint32_t sal_uInt32;
typedef intptr_t sal_IntPtr;
typedef uint64_t sal_uLong;

struct DffRecordHeader {
    uint16_t nRecVer;
    uint16_t nRecType;
    uint32_t nRecLen;
    
    sal_uLong GetRecEndFilePos() const;
    void SeekToEndOfRecord(class SvStream& rSt);
    void SeekToBegOfRecord(class SvStream& rSt);
};

class SvStream {
public:
    sal_uLong Tell();
    void Seek(sal_uLong);
    bool good();
    SvStream& operator>>(DffRecordHeader&);
    SvStream& operator>>(sal_uInt32&);
};

class SvxMSDffManager {
    struct FidclsEntry {
        sal_uInt32 dgid;
    };
    
    FidclsEntry* mpFidcls;
    sal_uInt32 mnIdClusters;
    class DgOffsetTable {
    public:
        sal_IntPtr Get(sal_uInt32 dgid) const;
    };
    DgOffsetTable maDgOffsetTable;
    
    sal_Bool SeekToRec(SvStream& rSt, uint16_t nRecType, sal_uLong nEndPos, DffRecordHeader* pHd) const;
public:
    sal_Bool SeekToShape(SvStream& rSt, void* pClientData, sal_uInt32 nId) const;
};

enum {
    DFF_msofbtSpContainer = 0xF004,
    DFF_msofbtSp = 0xF00A
};