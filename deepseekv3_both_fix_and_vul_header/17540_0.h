#include <unordered_map>
#include <string>

namespace detail {
    bool has_crlf(const char *s);
}

class Response {
protected:
    std::unordered_multimap<std::string, std::string> headers;
public:
    void set_header(const char *key, const char *val);
};