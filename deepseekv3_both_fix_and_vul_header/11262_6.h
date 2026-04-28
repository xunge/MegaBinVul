#include <cstdio>
#include <cstdint>
#include <utility>

#define unlikely(x) __builtin_expect(!!(x), 0)
#define gFalse false
#define EOF (-1)
#define objError 0
#define objNull 1

typedef int GBool;
typedef unsigned char Guchar;
typedef int CryptAlgorithm;

extern void gfree(void *p);

class Object {
public:
    Object();
    Object(int num);
    Object(int num, int gen);
    Object(class Array *array);
    Object(class Dict *dict);
    Object(class Stream *stream);
    Object(class GooString *str);
    Object(const Object &other) = delete;
    Object& operator=(const Object &other) = delete;
    Object(Object &&other);
    Object& operator=(Object &&other);
    ~Object();
    bool isError() const;
    bool isCmd(const char *cmd) const;
    bool isInt() const;
    bool isString() const;
    bool isName() const;
    bool isEOF() const;
    const char *getName() const;
    const class GooString *getString() const;
    int getInt() const;
    void arrayAdd(Object &&obj);
    void dictAdd(char *key, Object &&obj);
};

class GooString {
public:
    GooString();
    ~GooString();
    void append(char c);
    const char *getCString() const;
    int getLength() const;
};

class Stream {
public:
    virtual ~Stream();
    virtual int getChar() = 0;
    virtual void reset();
};

class MemStream : public Stream {
public:
    MemStream(const char *buf, int start, int length, Object dict);
    ~MemStream();
    int getChar() override;
};

class DecryptStream : public Stream {
public:
    DecryptStream(Stream *str, Guchar *fileKey, CryptAlgorithm encAlgorithm,
                  int keyLength, int objNum, int objGen);
    ~DecryptStream();
    int getChar() override;
    void reset() override;
};

class Array {
public:
    Array(class XRef *xref);
    ~Array();
};

class Dict {
public:
    Dict(class XRef *xref);
    ~Dict();
};

class XRef {
public:
    XRef();
};

class Parser {
public:
    Object getObj(GBool simpleOnly, Guchar *fileKey, CryptAlgorithm encAlgorithm,
                  int keyLength, int objNum, int objGen, int recursion, GBool strict);
    Object getObj(GBool simpleOnly, Guchar *fileKey, CryptAlgorithm encAlgorithm,
                  int keyLength, int objNum, int objGen, int recursion);
private:
    class Lexer *lexer;
    Object buf1, buf2;
    int inlineImg;
    int recursionLimit;
    GBool allowStreams;
    XRef *xref;
    void shift();
    void shift(int objNum);
    Stream *makeStream(Object &&obj, Guchar *fileKey, CryptAlgorithm encAlgorithm,
                       int keyLength, int objNum, int objGen, int recursion,
                       GBool strict);
    long getPos();
    void error(int errCode, long pos, const char *msg);
    char *copyString(const char *s);
};

class Lexer {
public:
    Object getObj();
};

extern int errSyntaxError;