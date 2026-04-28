#include <string>
#include <unordered_map>

namespace detail {
    bool has_crlf(const char *s);
}

class Request {
protected:
    std::unordered_map<std::string, std::string> headers;
public:
    void set_header(const char *key, const std::string &val);
};