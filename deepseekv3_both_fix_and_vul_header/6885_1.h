#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Client {
public:
    std::string getClientIP();
};

class HTTPRequest {
public:
    bool parse();
    std::string methodIntToStr(int method);
    int getMethod();
    std::string getParseError();
    std::string getVersion();
    std::string getHeaderValue(const std::string& header);
    std::string getRequestUri();
};

class ResourceHost {};

class Status {
public:
    Status(int code);
};

class HTTPServer {
public:
    void handleRequest(Client* cl, HTTPRequest* req);
    void sendStatusResponse(Client* cl, Status status, const std::string& message = "");
    void handleGet(Client* cl, HTTPRequest* req, ResourceHost* resHost);
    void handleOptions(Client* cl, HTTPRequest* req);
    void handleTrace(Client* cl, HTTPRequest* req);
    
    std::unordered_map<std::string, ResourceHost*> vhosts;
    std::vector<ResourceHost*> hostList;
    int listenPort;
};

enum Method {
    HEAD,
    GET,
    OPTIONS,
    TRACE,
    NOT_IMPLEMENTED,
    BAD_REQUEST
};

const std::string HTTP_VERSION_11 = "HTTP/1.1";