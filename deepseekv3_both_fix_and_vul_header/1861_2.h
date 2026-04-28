#include <map>
#include <string>
#include <vector>

class PDFObject {
public:
    enum Type { ePDFObjectStream };
    virtual Type GetType() const = 0;
    virtual void SetMetadata(const char* key, void* value) = 0;
};

class PDFStreamInput : public PDFObject {};

class XCryptionCommon {
public:
    virtual std::vector<unsigned char> GetCurrentObjectKey() const = 0;
    virtual void OnObjectEnd() = 0;
};

class ByteList : public std::vector<unsigned char> {
public:
    ByteList(const std::vector<unsigned char>& data) : std::vector<unsigned char>(data) {}
};

template<typename T>
class Deletable {
public:
    Deletable(T* ptr) : mPtr(ptr) {}
private:
    T* mPtr;
};

typedef std::map<std::string, XCryptionCommon*> StringToXCryptionCommonMap;

class DecryptionHelper {
protected:
    StringToXCryptionCommonMap mXcrypts;
    virtual bool IsDecrypting() const = 0;
    virtual XCryptionCommon* GetCryptForStream(PDFStreamInput* stream) = 0;
public:
    virtual void OnObjectEnd(PDFObject* inObject);
};

const char* scEcnryptionKeyMetadataKey = "EncryptionKey";