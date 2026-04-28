#include <string>
#include <vector>
#include <memory>

struct LowerCaseString {
    const std::string& get() const;
};

struct HeaderEntry {
    const char* key() const;
};

struct HeaderEntryImpl : public HeaderEntry {};

struct HeaderMapImpl {
    std::vector<HeaderEntryImpl> headers_;
    std::unique_ptr<size_t> cached_byte_size_;
    HeaderEntry* get(const LowerCaseString& key);
};