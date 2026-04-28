#include <vector>
#include <string>
#include <utility>

typedef unsigned char XMP_Uns8;
typedef unsigned short XMP_Uns16;
typedef unsigned int XMP_Uns32;
typedef const char* XMP_StringPtr;

class MOOV_Manager {
public:
    struct BoxInfo {
        XMP_Uns32 boxType;
        XMP_Uns32 childCount;
        XMP_Uns32 contentSize;
        void* content;
    };
    typedef void* BoxRef;
    BoxRef GetBox(const char* path, BoxInfo* info) const;
    BoxRef GetNthChild(BoxRef parent, XMP_Uns32 childIndex, BoxInfo* info) const;
};

struct ValueInfo {
    XMP_Uns16 macLang;
    std::string xmpLang;
    std::string macValue;
    ValueInfo() {}
};

class TradQT_Manager {
public:
    struct ParsedBoxInfo {
        XMP_Uns32 boxType;
        std::vector<ValueInfo> values;
        ParsedBoxInfo(XMP_Uns32 type) : boxType(type) {}
    };
    typedef std::vector<std::pair<XMP_Uns32, ParsedBoxInfo>> InfoMap;
    typedef InfoMap::iterator InfoMapPos;
    InfoMap parsedBoxes;

    bool ParseCachedBoxes(const MOOV_Manager& moovMgr);
    static XMP_Uns16 GetUns16BE(const void* ptr);
    static bool IsMacLangKnown(XMP_Uns16 macLang);
    static std::string GetXMPLang(XMP_Uns16 macLang);
};