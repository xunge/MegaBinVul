#include <stddef.h>
#include <string.h>
#include <string>
#include <cassert>

typedef unsigned char XMP_Uns8;

class XMLParserAdapter {
public:
    void ParseBuffer(const char*, size_t, bool);
    void ParseBuffer(const XMP_Uns8*, size_t, bool);
};

extern const char* kReplaceLatin1[];
extern const int kTab;
extern const int kLF;
extern const int kCR;

#define XMP_Assert(x) assert(x)

int CountUTF8(const XMP_Uns8*, const XMP_Uns8*);
int CountControlEscape(const XMP_Uns8*, const XMP_Uns8*);