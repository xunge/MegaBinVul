#include <stddef.h>
#include <string.h>

typedef unsigned short XMP_Uns16;
typedef int XMP_Int32;

struct TweakedIFDEntry {
    XMP_Uns16 id;
};

struct TweakedIFDInfo {
    XMP_Uns16 count;
    TweakedIFDEntry* entries;
};

class TIFF_MemoryReader {
public:
    void SortIFD(TweakedIFDInfo* thisIFD);
};

static XMP_Uns16 GetUns16AsIs(const XMP_Uns16* ptr) {
    return *ptr;
}