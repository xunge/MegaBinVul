#include <string>

class RequestContext {
public:
    void SetApiKeyHeader();
private:
    class Request {
    public:
        void AddHeaderToBackend(const std::string&, const std::string&, bool);
        void AddHeaderToBackend(const std::string&, const std::string&);
    } *request_;
    std::string api_key_;
};

extern std::string kDefaultApiKeyHeaderName;