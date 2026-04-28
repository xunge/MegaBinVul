#include <string>

class CString {
public:
    CString();
    CString(const CString& other);
    CString& operator=(const CString& other);
    ~CString();
};

class CZNC {
public:
    static CZNC& Get();
    CString FixupEncoding(const CString& s);
};

class CIRCSock {
public:
    void SetEncoding(const CString& s);
};

class CIRCNetwork {
private:
    CString m_sEncoding;
public:
    CIRCSock* GetIRCSock();
    void SetEncoding(const CString& s);
};