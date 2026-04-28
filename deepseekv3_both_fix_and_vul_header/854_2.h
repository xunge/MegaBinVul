#include <cstdint>
#include <string_view>
#include <utility>

class HeaderString {
public:
    std::string_view getStringView() const;
    void clear();
    HeaderString& value();
};

class HeaderMapImpl {
public:
    void addViaMove(HeaderString&& key, HeaderString&& value);
    HeaderString* getExistingInline(std::string_view key);
    uint64_t appendToHeader(HeaderString& header, std::string_view value);
    void addSize(uint64_t size);
    void insertByKey(HeaderString&& key, HeaderString&& value);
};