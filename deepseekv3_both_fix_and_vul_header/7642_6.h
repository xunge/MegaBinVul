#include <string>
#include <filesystem>
#include <functional>

namespace Rest {
    struct Request {
        const std::string& resource() const { static std::string s; return s; }
    };
    
    class Router;
}

namespace Http {
    namespace Code {
        enum Enum {
            Moved_Permanently,
            Ok,
            Not_Found
        };
    }
    namespace Header {
        struct Location {};
    }
    
    class ResponseWriter {
    public:
        struct Headers {
            template<typename T>
            Headers& add(const std::string& value) { return *this; }
        };
        
        Headers& headers() { static Headers h; return h; }
        
        void send(Code::Enum code) {}
        void send(Code::Enum code, const std::string& body, const std::string& contentType) {}
    };
    
    void serveFile(ResponseWriter&, const std::string&) {}
}

namespace Route {
    enum class Result {
        Ok,
        Failure
    };
    using Handler = std::function<Result(const Rest::Request&, Http::ResponseWriter)>;
}

class Rest::Router {
public:
    void addCustomHandler(const Route::Handler& handler) {}
};

#define MIME(type, subtype) "application/" #subtype

class Swagger {
public:
    void install(Rest::Router& router);
private:
    std::string uiPath_;
    std::string uiDirectory_;
    std::string apiPath_;
    std::function<std::string(const std::string&)> serializer_;
    std::string description_;
};