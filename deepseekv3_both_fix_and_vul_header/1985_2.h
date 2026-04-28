#include <stdbool.h>
#include <stdint.h>

typedef uint16_t sal_uInt16;
typedef uint32_t sal_uLong;

struct DffRecordHeader {
    sal_uInt16 nRecType;
    sal_uLong nRecLen;
    void SeekToBegOfRecord(struct SvStream&);
    bool SeekToEndOfRecord(struct SvStream&);
};

struct SvStream {
    bool good();
    sal_uLong Tell();
    void Seek(sal_uLong);
    SvStream& operator>>(DffRecordHeader&);
};

struct SvxMSDffManager {
    bool SeekToRec(SvStream&, sal_uInt16, sal_uLong, DffRecordHeader*, sal_uLong) const;
};

#define sal_False false
#define sal_True true
#define NULL 0
#define nMaxLegalDffRecordLength 0xFFFFFFFF