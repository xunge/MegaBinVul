#include <stdbool.h>
#include <stdint.h>
#include <cstddef>

typedef uint16_t sal_uInt16;
typedef uint32_t sal_uLong;
#define sal_False false
#define sal_True true

struct DffRecordHeader {
    sal_uInt16 nRecType;
    bool SeekToBegOfRecord(struct SvStream&);
    bool SeekToEndOfRecord(struct SvStream&);
};

struct SvStream {
    sal_uLong Tell();
    void Seek(sal_uLong);
    bool good();
    int GetError();
    SvStream& operator>>(DffRecordHeader&);
};

class SvxMSDffManager {
public:
    bool SeekToRec(SvStream&, sal_uInt16, sal_uLong, DffRecordHeader*, sal_uLong) const;
};