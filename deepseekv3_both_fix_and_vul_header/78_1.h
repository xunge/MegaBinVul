#include <stddef.h>

typedef int OFBool;
typedef int OFCondition;
#define EC_Normal 0

class DcmTagKey {};
class DcmItem {
public:
    OFCondition search(DcmTagKey t, class DcmStack &stack);
};
class DcmByteString {
public:
    unsigned long getLength();
    OFCondition getString(char* &s);
};
class DcmStack {
public:
    void* top();
};
namespace OFStandard {
    void strlcpy(char* dest, const char* src, size_t n);
};