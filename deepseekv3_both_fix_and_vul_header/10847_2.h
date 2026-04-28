#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <stdexcept>

typedef unsigned char XMP_Uns8;
typedef unsigned short XMP_Uns16;
typedef unsigned int XMP_Uns32;
typedef long long XMP_Int64;

class XMP_IO {
public:
    XMP_Int64 Offset();
    void ReadAll(void* buffer, size_t count);
    void Seek(XMP_Int64 offset, int mode);
};

namespace XIO {
    bool CheckFileSpace(XMP_IO* fileRef, size_t size);
    XMP_Uns32 ReadUns32_BE(XMP_IO* fileRef);
    XMP_Uns16 ReadUns16_BE(XMP_IO* fileRef);
    XMP_Uns8 ReadUns8(XMP_IO* fileRef);
};

static const XMP_Uns32 k8BIM = 0x3842494D;
static const int kXMP_SeekFromStart = 0;
static const int kXMPErr_NoMemory = 0;
static const int kIsFileBased = 0;

#define XMP_Throw(msg, code) throw std::runtime_error(msg)

class PSIR_FileWriter {
public:
    void ParseFileResources(XMP_IO* fileRef, XMP_Uns32 length);

private:
    struct InternalRsrcInfo {
        XMP_Uns16 id;
        XMP_Uns32 dataLen;
        XMP_Uns8* rsrcName;
        void* dataPtr;
        XMP_Uns32 origOffset;
        bool changed;
        InternalRsrcInfo(XMP_Uns16 id, XMP_Uns32 dataLen, int type);
    };

    struct OtherRsrcInfo {
        XMP_Uns32 offset;
        XMP_Uns32 length;
        OtherRsrcInfo(XMP_Uns32 offset, XMP_Uns32 length);
    };

    typedef std::map<XMP_Uns16, InternalRsrcInfo> InternalRsrcMap;
    std::vector<OtherRsrcInfo> otherRsrcs;
    InternalRsrcMap imgRsrcs;
    bool fileParsed;

    void DeleteExistingInfo();
    bool IsMetadataImgRsrc(XMP_Uns16 id);
};