#include <string>
#include <utility>
#include <cstdint>
#include <cassert>

class HeaderString;

class LowerCaseString {
public:
    const std::string& get() const;
};

class HeaderString {
public:
    void setCopy(const char* data, size_t size);
    bool empty() const;
};

class HeaderMapImpl {
public:
    void addCopy(const LowerCaseString& key, const std::string& value);
protected:
    struct HeaderEntryImpl {
        const std::string& value() const;
    };
    HeaderEntryImpl* getExistingInline(const std::string& key);
    uint64_t appendToHeader(const std::string& existing_value, const std::string& new_value);
    void addSize(uint64_t size);
    void insertByKey(HeaderString&& key, HeaderString&& value);
};

#define ASSERT(x) assert(x)