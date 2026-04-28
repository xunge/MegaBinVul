#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <string>

typedef uint8_t Uns8;
typedef uint32_t XMP_Uns32;
typedef int64_t XMP_Int64;
typedef size_t std_size_t;

struct XMP_IO {
    virtual void Rewind() = 0;
    virtual ~XMP_IO() {}
};

typedef bool (*XMP_AbortProc)(void*);

struct IOBuffer {
    Uns8* ptr;
    Uns8* data;
    Uns8* limit;
    XMP_Int64 filePos;
};

enum {
    kPS_EndPostScript,
    kPS_EndComments,
    kPS_BeginProlog,
    kPS_BeginSetup,
    kPS_BeginPageSetup,
    kPS_EndProlog,
    kPS_EndSetup,
    kPS_EndPageSetup,
    kPS_EndPageComments,
    kPS_Page,
    kPS_Trailer,
    kPS_EOF,
    kPS_dscFor,
    kPS_dscCreator,
    kPS_dscCreateDate,
    kPS_dscTitle,
    kXMPErr_UserAbort
};

enum {
    kPS_Creator,
    kPS_CreatorTool,
    kPS_CreateDate,
    kPS_Title
};

struct PostScript_MetaHandler {
    struct {
        XMP_IO* ioRef;
        XMP_AbortProc abortProc;
        void* abortArg;
    }* parent;
    int fileformat;
    unsigned int dscFlags;
    void ParsePSFile();
};

class PostScript_Support {
public:
    static bool IsValidPSFile(XMP_IO* fileRef, int fileformat);
    static bool SkipUntilNewline(XMP_IO* fileRef, IOBuffer& ioBuf);
};

XMP_Uns32 GetUns32BE(const void* ptr);
XMP_Uns32 GetUns32LE(const void* ptr);
bool CheckFileSpace(XMP_IO* fileRef, IOBuffer* ioBuf, std_size_t length);
bool CheckBytes(const void* ptr1, const void* ptr2, std_size_t length);
bool IsWhitespace(char c);
bool IsNewline(char c);
void MoveToOffset(XMP_IO* fileRef, XMP_Uns32 offset, IOBuffer* ioBuf);
void setTokenInfo(int token, XMP_Int64 pos, std_size_t length);
bool ExtractDSCCommentValue(IOBuffer& ioBuf, int type);
void ExtractDocInfoDict(IOBuffer& ioBuf);
void ExtractContainsXMPHint(IOBuffer& ioBuf, XMP_Int64 startPos);
void XMP_Throw(const char* msg, int code);

inline Uns8* Uns8Ptr(const char* str) { return reinterpret_cast<Uns8*>(const_cast<char*>(str)); }

extern const std::string kPSContainsForString;
extern const std::string kPSEndCommentString;
extern const std::string kPSContainsDocInfoString;
extern const std::string kPSContainsCreatorString;
extern const std::string kPSContainsCreateDateString;
extern const std::string kPSContainsTitleString;
extern const std::string kPSContainsXMPString;