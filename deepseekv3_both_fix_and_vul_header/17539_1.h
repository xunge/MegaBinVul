#include <map>
#include <string>

class Request {
public:
    void set_header(const char *key, const char *val);
protected:
    std::multimap<std::string, std::string> headers;
};

namespace detail {
    bool has_crlf(const char *s);
}