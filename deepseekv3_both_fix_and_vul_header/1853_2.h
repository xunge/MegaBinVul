#include <iostream>
#include <string>

#define TRACE_LOG(msg) std::cerr << msg << std::endl

enum EStatusCode { eSuccess, eFailure };
namespace PDFHummus { EStatusCode eSuccess = ::eSuccess; EStatusCode eFailure = ::eFailure; }

typedef long long LongFilePositionType;

class PDFObject {
public:
    enum EType { ePDFObjectInteger, ePDFObjectSymbol };
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
    std::string GetValue() const { return ""; }
};

template<typename T>
class RefCountPtr {
public:
    RefCountPtr(T* ptr = nullptr) : mPtr(ptr) {}
    T* GetPtr() const { return mPtr; }
    T* operator->() const { return mPtr; }
    operator bool() const { return mPtr != nullptr; }
private:
    T* mPtr;
};

template<typename T>
class PDFObjectCastPtr : public RefCountPtr<T> {
public:
    PDFObjectCastPtr(PDFObject* obj) : RefCountPtr<T>(dynamic_cast<T*>(obj)) {}
};

class IByteReader {
public:
    virtual void SetPositionFromEnd(long long pos) = 0;
    virtual bool NotEnded() const = 0;
    virtual ~IByteReader() {}
};

class ObjectParser {
public:
    void ResetReadState() {}
    PDFObject* ParseNewObject() { return nullptr; }
};

class PDFParser {
public:
    EStatusCode ParseLastXrefPosition();
protected:
    IByteReader* mStream;
    LongFilePositionType mLastXrefPosition;
    ObjectParser mObjectParser;
    static const std::string scStartxref;
    
    bool GoBackTillToken() { return false; }
    void GoBackTillLineStart() {}
    LongFilePositionType GetCurrentPositionFromEnd() { return 0; }
};

const std::string PDFParser::scStartxref = "startxref";