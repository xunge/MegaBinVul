#include <cassert>
#include <cstring>
#include <cstddef>

#define assertx assert

namespace folly {
struct StringPiece {
    const char* data() const;
    size_t size() const;
    int compare(folly::StringPiece other) const;
};
}

struct StringData {
    bool isStatic() const;
    folly::StringPiece slice() const;
};

class VariableUnserializer {
public:
    enum class Type { APCSerialize };
    Type type() const;
    const char* m_buf;
    const char* m_end;
    bool matchString(folly::StringPiece str);
};