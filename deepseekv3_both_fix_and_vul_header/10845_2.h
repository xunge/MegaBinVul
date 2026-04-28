#include <string>
#include <cassert>

#define kXMPFiles_OpenForUpdate 0
#define kTIFF_PrimaryIFD 0
#define kTIFF_PSIR 0
#define kTIFF_IPTC 0
#define kPSIR_Exif 0
#define kPSIR_IPTCDigest 0
#define kDigestMatches 0
#define kDigestMissing 0
#define kDigestDiffers 0
#define k2XMP_FileHadExif 0
#define k2XMP_FileHadIPTC 0
#define k2XMP_FileHadXMP 0

#define XMP_Assert(x) assert(x)

typedef unsigned char XMP_Uns8;
typedef unsigned int XMP_Uns32;
typedef unsigned int XMP_OptionBits;
typedef const char* XMP_StringPtr;
typedef size_t XMP_StringLen;

class PSIR_Manager {
public:
    struct ImgRsrcInfo {
        void* dataPtr;
        XMP_Uns32 dataLen;
    };
    virtual void ParseMemoryResources(void*, XMP_Uns32) = 0;
    virtual bool GetImgRsrc(int, ImgRsrcInfo*) = 0;
    virtual void DeleteImgRsrc(int) = 0;
    virtual ~PSIR_Manager() = default;
};

class IPTC_Manager {
public:
    virtual void ParseMemoryDataSets(void*, XMP_Uns32) = 0;
    virtual ~IPTC_Manager() = default;
};

class PSIR_MemoryReader : public PSIR_Manager {
public:
    void ParseMemoryResources(void*, XMP_Uns32) override {}
    bool GetImgRsrc(int, ImgRsrcInfo*) override { return false; }
    void DeleteImgRsrc(int) override {}
};

class PSIR_FileWriter : public PSIR_Manager {
public:
    void ParseMemoryResources(void*, XMP_Uns32) override {}
    bool GetImgRsrc(int, ImgRsrcInfo*) override { return false; }
    void DeleteImgRsrc(int) override {}
};

class IPTC_Reader : public IPTC_Manager {
public:
    void ParseMemoryDataSets(void*, XMP_Uns32) override {}
};

class IPTC_Writer : public IPTC_Manager {
public:
    void ParseMemoryDataSets(void*, XMP_Uns32) override {}
};

class TIFF_Manager {
public:
    struct TagInfo {
        void* dataPtr;
        XMP_Uns32 dataLen;
        int type;
    };
    bool GetTag(int, int, TagInfo*) { return false; }
    void IntegrateFromPShop6(void*, XMP_Uns32) {}
};

class PhotoDataUtils {
public:
    static int CheckIPTCDigest(void*, XMP_Uns32, void*) { return 0; }
};

class XMP_Obj {
public:
    void ParseFromBuffer(XMP_StringPtr, XMP_StringLen) {}
};

class TIFF_MetaHandler {
public:
    bool processedXMP;
    struct {
        int openFlags;
    } *parent;
    PSIR_Manager* psirMgr;
    IPTC_Manager* iptcMgr;
    TIFF_Manager tiffMgr;
    std::string xmpPacket;
    bool containsXMP;
    XMP_Obj xmpObj;
    void ProcessXMP();
};

extern void ImportPhotoData(TIFF_Manager&, IPTC_Manager&, PSIR_Manager&, int, XMP_Obj*, XMP_OptionBits);

extern int kTIFF_TypeSizes[];