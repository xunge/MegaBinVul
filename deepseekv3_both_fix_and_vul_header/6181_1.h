#include <string>
#include <cstring>
#include <cctype>

struct XmpKey {
    std::string groupName() const;
    std::string tagName() const;
    std::string key() const;
};

struct XmpPropertyInfo {
    const char* name_;
};

class XmpProperties {
public:
    static const XmpPropertyInfo* propertyInfo(const XmpKey& key);
    static const XmpPropertyInfo* propertyList(const std::string& prefix);
};