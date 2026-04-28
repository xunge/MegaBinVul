#include <vector>
#include <memory>
#include <cstdio>

class Stream;
class Object;

class BaseStream {
public:
    virtual Stream* makeSubStream(unsigned int offset, bool limited, unsigned int length, Object obj) = 0;
};

class Linearization {
public:
    virtual unsigned int getHintsOffset() = 0;
    virtual unsigned int getHintsLength() = 0;
    virtual unsigned int getHintsOffset2() = 0;
    virtual unsigned int getHintsLength2() = 0;
};

class XRef;
class SecurityHandler {
public:
    virtual unsigned char* getFileKey() = 0;
    virtual int getEncAlgorithm() = 0;
    virtual int getFileKeyLength() = 0;
};

class Stream {
public:
    virtual ~Stream() {}
    virtual void reset() = 0;
    virtual int getChar() = 0;
};

class Object {
public:
    enum Type {
        objNull,
        objInt,
        objCmd,
        objStream
    };
    
    Object(Type type = objNull) : type(type) {}
    bool isInt() const { return type == objInt; }
    bool isCmd(const char* cmd) const { return type == objCmd; }
    bool isStream() const { return type == objStream; }
    int getInt() const { return 0; }
    Stream* getStream() { return nullptr; }
    class Dict* streamGetDict() { return nullptr; }
    
    static const Type Null = objNull;
    
private:
    Type type;
};

class Dict {
public:
    bool lookupInt(const char* key, int* value, int* offset) { return false; }
};

class MemStream : public Stream {
public:
    MemStream(char* buf, unsigned int start, unsigned int length, Object obj) {}
    void reset() override {}
    int getChar() override { return 0; }
};

class Parser {
public:
    Parser(XRef* xref, Stream* stream, bool allowStreams) {}
    ~Parser() {}
    Object getObj(bool recursive = true, unsigned char* fileKey = nullptr, 
                 int encAlgorithm = 0, int keyLength = 0, 
                 int objNum = 0, int objGen = 0, 
                 int recursion = 0, bool strict = false) { return Object(); }
};

enum CryptAlgorithm {
    cryptRC4
};

enum ErrorType {
    errSyntaxWarning
};

class Hints {
public:
    unsigned int hintsOffset;
    unsigned int hintsLength;
    unsigned int hintsOffset2;
    unsigned int hintsLength2;
    bool ok;

    void readTables(BaseStream* str, Linearization* linearization, XRef* xref, SecurityHandler* secHdlr);
    bool readPageOffsetTable(Stream* stream) { return false; }
    bool readSharedObjectsTable(Stream* stream) { return false; }
};

inline bool unlikely(int condition) { return condition; }
inline void error(ErrorType type, int code, const char* msg) {}

const Object::Type objNull = Object::Null;