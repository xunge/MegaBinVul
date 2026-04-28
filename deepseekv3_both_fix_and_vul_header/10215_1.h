#include <exception>

class Exception : public std::exception {
public:
    Exception(const char* msg) : message(msg) {}
    const char* what() const noexcept override { return message; }
private:
    const char* message;
};

class CharArray {
public:
    CharArray(int len) : buf(new char[len]) {}
    ~CharArray() { delete[] buf; }
    char* buf;
};

class InputStream {
public:
    virtual void skip(int bytes) = 0;
    virtual unsigned int readU32() = 0;
    virtual void readBytes(char* buf, int len) = 0;
};

class Handler {
public:
    virtual void clientCutText(char* buf, int len) = 0;
};

class Logger {
public:
    void error(const char* format, ...);
};

class SMsgReader {
public:
    InputStream* is;
    Handler* handler;
    void readClientCutText();
};

extern Logger vlog;
extern int maxCutText;