#include <cstring>
#include <map>
#include <sstream>
#include <string>

namespace OPENEXR_IMF_INTERNAL_NAMESPACE {
    class IStream;
    class StreamIO;
    namespace Xdr {
        template <typename T> void read(IStream&, int, char*);
        template <typename T> void read(IStream&, int&);
    }
}

namespace IEX_NAMESPACE {
    class InputExc {
    public:
        InputExc(const std::string&);
    };
}

#define THROW(exc, msg) do { \
    std::ostringstream oss; \
    oss << msg; \
    throw exc(oss.str()); \
} while(false)

class Name {
public:
    static const int SIZE = 256;
    static const int MAX_LENGTH = SIZE - 1;
};

class Attribute {
public:
    static bool knownType(const char*);
    static Attribute* newAttribute(const char*);
    const char* typeName() const;
    void readValueFrom(OPENEXR_IMF_INTERNAL_NAMESPACE::IStream&, int, int&);
    virtual ~Attribute();
};

class OpaqueAttribute : public Attribute {
public:
    OpaqueAttribute(const char*);
    ~OpaqueAttribute() override;
};

class Header {
public:
    void readFrom(OPENEXR_IMF_INTERNAL_NAMESPACE::IStream&, int&);
    ~Header();
private:
    bool _readsNothing;
    typedef std::map<std::string, Attribute*> AttributeMap;
    AttributeMap _map;
    void checkIsNullTerminated(const char*, const char*);
};