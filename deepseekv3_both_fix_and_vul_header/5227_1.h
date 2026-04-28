#include <string>
#include <unicode/ucnv.h>
#include <unicode/utypes.h>

class CString {
public:
    const char* c_str() const;
    bool empty() const;
    char operator[](size_t pos) const;
    CString(const char* str);
};

class CZNC {
private:
    unsigned int m_uiForceEncoding;
public:
    CString FixupEncoding(const CString& sEncoding) const;
};