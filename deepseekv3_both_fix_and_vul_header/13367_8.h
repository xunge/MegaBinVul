#include <string>
#include <memory>

class ErrorHandler {
public:
    ErrorHandler();
    ErrorHandler(const ErrorHandler&);
    ErrorHandler& operator=(const ErrorHandler&);
    ErrorHandler& operator=(const char* msg);
    int ErrCode();
    void setError(const char* msg);
};

namespace zxing {
    class FormatErrorHandler {
    public:
        FormatErrorHandler(const char* msg);
        operator const char*() const;
    };
}

template<typename T>
class Ref {
public:
    Ref(T* source);
    T* operator->();
    T& operator*();
};

class BitSource {
public:
    int available();
    int readBits(int count, ErrorHandler& err_handler);
};

class DecodedBitStreamParser {
public:
    void decodeHanziSegment(Ref<BitSource> bits_, std::string& result, int count, ErrorHandler& err_handler);
};

void append(std::string& result, const char* buffer, size_t nBytes, ErrorHandler& err_handler);

using std::string;