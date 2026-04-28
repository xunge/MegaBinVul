#include <string>
#include <vector>
#include <memory>

class LowerCaseString {
public:
    const std::string& get() const;
    const char* c_str() const;
};

template<typename T>
class ConstSingleton {
public:
    static T& get();
};

struct StaticLookupResponse {
    void* entry_;
};

class HeaderMapImpl;

typedef StaticLookupResponse (*EntryCb)(HeaderMapImpl&);

class StaticLookupTable {
public:
    EntryCb find(const std::string& key);
};

class HeaderMapImpl {
public:
    void remove(const LowerCaseString& key);
    operator void*();
private:
    struct HeaderEntry {
        const std::string& key() const;
        const std::string& value() const;
    };
    std::vector<HeaderEntry> headers_;
    void subtractSize(size_t size);
    void removeInline(void* entry);
};