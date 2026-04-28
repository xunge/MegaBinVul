#include <cstdint>
#include <cstddef>

class ByteVector {
public:
    ByteVector mid(int pos, int length) const;
    uint32_t toUInt(bool mostSignificantByteFirst) const;
    std::size_t size() const;
};

class String {
public:
    String(const ByteVector &data, int encoding);
    String substr(std::size_t pos, std::size_t len = npos) const;
    int find(const char *str) const;
    static const std::size_t npos;
    static const int UTF8;
};

struct Ogg_XiphComment_Private {
    String vendorID;
};

class Ogg {
public:
    class XiphComment {
    public:
        void parse(const ByteVector &data);
        void addField(const String &key, const String &value, bool replace);
    private:
        Ogg_XiphComment_Private *d;
    };
};

typedef unsigned int uint;