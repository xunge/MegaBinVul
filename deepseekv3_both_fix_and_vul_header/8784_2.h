#include <string>

namespace base {
using string16 = std::u16string;
}  // namespace base

class GURL {
public:
    bool has_username() const;
};

namespace url_formatter {
enum FormatUrlTypes {
    kFormatUrlOmitAll = 1,
    kFormatUrlOmitUsernamePassword = 2,
    kFormatUrlOmitHTTP = 4
};
inline FormatUrlTypes operator&(FormatUrlTypes a, FormatUrlTypes b) {
    return static_cast<FormatUrlTypes>(static_cast<int>(a) & static_cast<int>(b));
}
inline FormatUrlTypes operator~(FormatUrlTypes a) {
    return static_cast<FormatUrlTypes>(~static_cast<int>(a));
}
inline FormatUrlTypes& operator&=(FormatUrlTypes& a, FormatUrlTypes b) {
    a = a & b;
    return a;
}
base::string16 FormatUrl(const GURL& url, FormatUrlTypes format_types, int unescape_rules, void*, void*, void*);
}  // namespace url_formatter

namespace net {
enum UnescapeRule {
    SPACES
};
}  // namespace net