#include <string>

class XmpValue {
public:
    enum XmpArrayType { xaAlt, xaBag, xaSeq };
};

class XmpTextValue {
public:
    int read(const std::string& buf);
    void setXmpArrayType(XmpValue::XmpArrayType type);
    void setXmpStruct();
    std::string value_;
};

class Error {
public:
    Error(int code, const std::string& arg);
};

namespace {
    const int kerInvalidXmpText = 0;
}