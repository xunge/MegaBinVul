#include <iostream>
#include <string>
#include <memory>

typedef long LongFilePositionType;

enum EStatusCode { eSuccess, eFailure };
namespace PDFHummus { const EStatusCode eSuccess = ::eSuccess; const EStatusCode eFailure = ::eFailure; }

class PDFObject;
class PDFInteger;
class PDFSymbol;
class IByteReader;

class PDFObjectParser {
public:
    void ResetReadState();
    PDFObject* ParseNewObject();
};

class IByteReader {
public:
    virtual void SetPositionFromEnd(LongFilePositionType pos) = 0;
    virtual bool NotEnded() const = 0;
    virtual ~IByteReader() {}
};

class PDFObject {
public:
    enum EType { ePDFObjectInteger, ePDFObjectSymbol };
    virtual ~PDFObject() {}
    virtual EType GetType() const = 0;
};

class PDFInteger : public PDFObject {
public:
    long GetValue() const { return mValue; }
    EType GetType() const override { return ePDFObjectInteger; }
private:
    long mValue;
};

class PDFSymbol : public PDFObject {
public:
    const std::string& GetValue() const { return mValue; }
    EType GetType() const override { return ePDFObjectSymbol; }
private:
    std::string mValue;
};

template<typename T>
class RefCountPtr {
public:
    RefCountPtr(T* obj = nullptr) : mPtr(obj) {}
    T* GetPtr() const { return mPtr.get(); }
    T* operator->() const { return mPtr.get(); }
    explicit operator bool() const { return mPtr != nullptr; }
private:
    std::shared_ptr<T> mPtr;
};

template<typename T>
class PDFObjectCastPtr {
public:
    PDFObjectCastPtr(PDFObject* obj = nullptr) : mPtr(dynamic_cast<T*>(obj)) {}
    T* GetPtr() const { return mPtr; }
    T* operator->() const { return mPtr; }
    explicit operator bool() const { return mPtr != nullptr; }
private:
    T* mPtr;
};

class PDFParser {
public:
    EStatusCode ParseLastXrefPosition();
    bool GoBackTillToken();
    void GoBackTillLineStart();
    LongFilePositionType GetCurrentPositionFromEnd();
    
    IByteReader* mStream;
    PDFObjectParser mObjectParser;
    LongFilePositionType mLastXrefPosition;
};

static const std::string scStartxref = "startxref";

#define TRACE_LOG(msg) std::cerr << msg << std::endl