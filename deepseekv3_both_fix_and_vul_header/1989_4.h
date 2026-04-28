#include <cstdint>
#include <cstring>
#include <algorithm>

typedef std::uint32_t sal_uInt32;
typedef std::size_t sal_Size;

#define DFF_msofbtDgg 0xF000
#define SAL_WARN_IF(cond, area, message)

struct DffRecordHeader {
    sal_uInt32 nRecLen;
    sal_uInt32 GetRecEndFilePos() const;
    void SeekToContent(class SvStream&);
    friend class SvStream;
};

class SvStream {
public:
    sal_uInt32 Tell();
    sal_uInt32 Seek(sal_uInt32);
    sal_Size remainingSize();
    SvStream& operator>>(sal_uInt32&);
    SvStream& operator>>(DffRecordHeader&);
};

struct FIDCL {
    sal_uInt32 dgid;
    sal_uInt32 cspidCur;
};

class SvxMSDffManager {
public:
    void GetFidclData(sal_uInt32 nOffsDggL);
    
private:
    sal_uInt32 mnCurMaxShapeId;
    sal_uInt32 mnIdClusters;
    sal_uInt32 mnDrawingsSaved;
    FIDCL* mpFidcls;
    SvStream rStCtrl;
    
    bool SeekToRec(SvStream&, int, sal_uInt32, DffRecordHeader*);
};