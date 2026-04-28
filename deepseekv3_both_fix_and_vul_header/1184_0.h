#include <string>
#include <functional>

struct Url {
    static std::string DecodeUnsafe(const std::string& path);
    std::string path() const;
};

class Request {
public:
    std::string method() const;
    Url url() const;
};

class RequestParser {
private:
    Request* request_;
    std::function<bool(const std::string&, const std::string&, void*)> view_matcher_;
    void* stream_;
public:
    bool OnHeadersEnd();
};

#define LOG_WARN(fmt, ...)