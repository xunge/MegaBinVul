#include <cstddef>
#include <cstdint>
#include <limits>

class String {
public:
    String();
    String(const String&);
    String(std::size_t size, int ReserveString);
    ~String();
    const char* data() const;
    std::size_t size() const;
    char charAt(std::size_t pos) const;
    bool empty() const;
    char* mutableData();
    String setSize(std::size_t size);
    static constexpr std::size_t MaxSize = std::numeric_limits<int64_t>::max() / 4;
};

struct StringData {
    static constexpr std::size_t MaxSize = std::numeric_limits<int64_t>::max() / 4;
};

extern int ReserveString;