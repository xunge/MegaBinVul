#include <string.h>

struct Response {
    void set_redirect(const char* url);
    void set_header(const char*, const char*);
    int status;
};

namespace detail {
    bool has_crlf(const char* url) {
        return strstr(url, "\r") || strstr(url, "\n");
    }
}