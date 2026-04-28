#include <string>
#include <utility>
#include <map>

struct Headers : public std::multimap<std::string, std::string> {
    using std::multimap<std::string, std::string>::multimap;
};

struct Request {
    std::string method;
    std::string path;
    Headers headers;
    std::string body;

    void set_header(const std::string& key, const std::string& val) {
        headers.emplace(key, val);
    }
};

struct Result {};

class ClientImpl {
public:
    Result Delete(const std::string& path,
                 const Headers& headers,
                 const char* body,
                 size_t content_length,
                 const std::string& content_type);
    Result send_(Request&& req);
};