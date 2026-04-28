#include <string.h>

#define NUMBER_OF_CIDSETS 256
#define CIDSET_UNKNOWN -1

extern const char* g_CharsetNames[NUMBER_OF_CIDSETS];

class CFX_ByteString {
public:
    CFX_ByteString(const char* str);
    bool operator==(const CFX_ByteString& other) const;
    bool operator!=(const CFX_ByteString& other) const;
};

class CFX_ByteStringC {
public:
    CFX_ByteStringC(const char* str);
    operator CFX_ByteString() const;
};