#include <string>
#include <map>

struct QLatin1String {
    QLatin1String(const char*);
};

class QUrlQuery {
public:
    void addQueryItem(QLatin1String, QLatin1String);
};

class QUrl {
public:
    QUrl();
    QUrl(const std::string&);
};

class QNetworkRequest {
public:
    void addRawHeader(const std::string&, const std::string&);
};

class QByteArray {
public:
    bool isEmpty() const;
};

class SimpleApiJob {
public:
    void start();
};

class AbstractNetworkJob {
public:
    void start();
};

class Account {
public:
    QUrl url() const;
};

class JsonApiJob : public SimpleApiJob, public AbstractNetworkJob {
protected:
    QUrlQuery _additionalParams;
    QByteArray _body;
    QNetworkRequest _request;
    Account* _account;

    QUrlQuery& additionalParams();
    void sendRequest(const std::string& verb, const QUrl& url, const QNetworkRequest& request, const QByteArray& body = QByteArray());
    std::string verbToString() const;
    Account* account() const;
    std::string path() const;
    void addRawHeader(const std::string& headerName, const std::string& value);
public:
    void start();
};

class Utility {
public:
    static QUrl concatUrlPath(const QUrl&, const std::string&, const QUrlQuery&);
};