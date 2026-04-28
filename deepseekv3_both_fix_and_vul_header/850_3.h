#include <cstdint>
#include <utility>
#include <cassert>
#include <string>

class LowerCaseString {
public:
    const std::string& get() const { return data_; }
private:
    std::string data_;
};

class HeaderString {
public:
    void setCopy(const char* str, size_t size);
    void setInteger(uint64_t value);
    bool empty() const;
    std::string value_;
};

class StringUtil {
public:
    static void itoa(char* buf, size_t size, uint64_t value);
};

struct Entry {
    HeaderString* value();
};

struct HeaderMapImpl {
    void addCopy(const LowerCaseString& key, uint64_t value);
    Entry* getExistingInline(const std::string& key);
    uint64_t appendToHeader(HeaderString* entry, const char* value);
    void addSize(uint64_t size);
    void insertByKey(HeaderString&& key, HeaderString&& value);
};

#define ASSERT(x) assert(x)