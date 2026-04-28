#include <string>
#include <iostream>

struct QJsonDocument {
    std::string toJson() const;
};

struct QNetworkRequest {
    enum Header {
        ContentTypeHeader
    };
    void setHeader(Header, const std::string&);
};

class SimpleApiJob {
public:
    static void setBody(const std::string&);
    static std::string body();
    QNetworkRequest request();
};

class JsonApiJob {
public:
    void setBody(const QJsonDocument &body);
    QNetworkRequest request();
private:
    std::string _body;
    QNetworkRequest _request;
};

int lcJsonApiJob;

#define qCDebug(stream) std::cout
#define isEmpty() empty()