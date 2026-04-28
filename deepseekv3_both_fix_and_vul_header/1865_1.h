#include <iostream>
#include <string>

enum EStatusCode {
    eSuccess,
    eFailure
};

namespace PDFHummus {
    const EStatusCode eSuccess = ::eSuccess;
    const EStatusCode eFailure = ::eFailure;
}

#define TRACE_LOG(msg) std::cerr << msg << std::endl

class PDFObject {
public:
    enum EType {
        ePDFObjectInteger,
        ePDFObjectSymbol
    };
    virtual EType GetType() const = 0;
    virtual ~PDFObject() {}
};

class PDFInteger : public PDFObject {
public:
    EType GetType() const override { return ePDFObjectInteger; }
    long GetValue() const { return 0; }
};

class PDFSymbol : public PDFObject {
public:
    EType GetType() const override { return ePDFObjectSymbol; }
    const std::string& GetValue() const { static std::string s; return s; }
};

template<typename T>
class RefCountPtr {
    T* ptr;
public:
    RefCountPtr(T* p = nullptr) : ptr(p) {}
    operator bool() const { return ptr != nullptr; }
    T* operator->() const { return ptr; }
    T* GetPtr() const { return ptr; }
};

template<typename T>
class PDFObjectCastPtr {
    T* ptr;
public:
    PDFObjectCastPtr(PDFObject* obj) : ptr(dynamic_cast<T*>(obj)) {}
    operator bool() const { return ptr != nullptr; }
    T* operator->() const { return ptr; }
    T* GetPtr() const { return ptr; }
};

class IByteReader {
public:
    void SetPositionFromEnd(long pos) {}
    bool NotEnded() const { return false; }
};

typedef long LongFilePositionType;

class PDFParser {
private:
    IByteReader* mStream;
    LongFilePositionType mLastXrefPosition;
    struct {
        void ResetReadState() {}
        PDFObject* ParseNewObject() { return nullptr; }
    } mObjectParser;

    bool GoBackTillToken() { return false; }
    void GoBackTillLineStart() {}
    LongFilePositionType GetCurrentPositionFromEnd() { return 0; }

    static const std::string scStartxref;
public:
    EStatusCode ParseLastXrefPosition();
};

const std::string PDFParser::scStartxref = "startxref";