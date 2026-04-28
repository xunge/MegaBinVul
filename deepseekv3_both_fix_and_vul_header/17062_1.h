#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef uint8_t XMP_Uns8;
typedef uint16_t XMP_Uns16;
typedef uint32_t XMP_Uns32;

struct TweakedIFDEntry {
    XMP_Uns16 id;
    XMP_Uns16 type;
    XMP_Uns32 bytes;
};

struct TagInfo {
    XMP_Uns16 id;
    XMP_Uns16 type;
    XMP_Uns32 count;
    XMP_Uns32 dataLen;
    void* dataPtr;
};

enum {
    kTIFF_ByteType,
    kTIFF_LastType
};

extern const size_t kTIFF_TypeSizes[];

class TIFF_MemoryReader {
public:
    const TweakedIFDEntry* FindTagInIFD(XMP_Uns8 ifd, XMP_Uns16 id) const;
    void* GetDataPtr(const TweakedIFDEntry* tag) const;
    bool GetTag(XMP_Uns8 ifd, XMP_Uns16 id, TagInfo* info) const;
};

XMP_Uns16 GetUns16AsIs(const void* ptr);
XMP_Uns32 GetUns32AsIs(const void* ptr);