#include <string>

namespace net {
enum UnescapeRule {
    SPOOFING_AND_CONTROL_CHARS,
    CONTROL_CHARS,
    SPACES,
    URL_SPECIAL_CHARS
};

std::string UnescapeURLComponent(const std::string& url, int flags);
}