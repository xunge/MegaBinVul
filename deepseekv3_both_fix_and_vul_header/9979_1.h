#include <string>

namespace Http {
    struct Request {};
    struct Response {};
    struct Environment {};
    
    const std::string HEADER_X_FRAME_OPTIONS;
    const std::string CONTENT_TYPE_TXT;
}

class QObject {
public:
    static std::string tr(const char*);
};

class AbstractWebApplication {
protected:
    Http::Request request_;
    Http::Environment env_;
    int session_;

    virtual void clear();
    virtual void header(const std::string&, const std::string&);
    virtual void sessionInitialize();
    virtual bool sessionActive();
    virtual bool isAuthNeeded();
    virtual void sessionStart();
    virtual bool isBanned();
    virtual void status(int, const std::string&);
    virtual void print(const std::string&, const std::string&);
    virtual void processRequest();
    virtual Http::Response response();
public:
    virtual Http::Response processRequest(const Http::Request&, const Http::Environment&);
};