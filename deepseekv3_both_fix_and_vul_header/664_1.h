#include <climits>
#include <utility>

typedef unsigned char Guchar;
typedef long long Goffset;
typedef int GBool;
#define gTrue 1
#define errSyntaxError 0

enum CryptAlgorithm {
    cryptAlgorithmNone
};

class BaseStream;

class Object {
public:
    bool isInt() const;
    bool isInt64() const;
    Goffset getInt() const;
    Goffset getInt64() const;
    void dictSet(const char*, Object);
    Object dictLookup(const char*, int);
    bool isCmd(const char*) const;
    Object(Goffset);
};

class Stream {
public:
    virtual Goffset getPos();
    virtual BaseStream* getBaseStream();
    virtual Stream* addFilters(Object, int);
    virtual Object getDict();
};

class BaseStream : public Stream {
public:
    virtual Stream* makeSubStream(Goffset, GBool, Goffset, Object&&);
};

class Lexer {
public:
    enum {
        LOOK_VALUE_NOT_CACHED = -1
    };
    int lookCharLastValueCached;
    void skipToNextLine();
    Stream* getStream();
    Goffset getPos();
    void setPos(Goffset);
};

class XRef {
public:
    bool getStreamEnd(Goffset, Goffset*);
};

class Parser {
private:
    Lexer* lexer;
    XRef* xref;
    Object buf1;
    void shift();
    void shift(const char*, int);
    void error(int, Goffset, const char*);
    Goffset getPos();
public:
    Stream* makeStream(Object&&, Guchar*, CryptAlgorithm, int, int, int, int, GBool);
};

class DecryptStream : public Stream {
public:
    DecryptStream(Stream*, Guchar*, CryptAlgorithm, int, int, int);
};

#define unlikely(x) (x)