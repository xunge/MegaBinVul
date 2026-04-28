#include <iostream>
#include <string>
#include <map>

class QUrl {
public:
    QUrl();
};
class QNetworkRequest {
public:
    void setRawHeader(const std::string&, const std::string&);
};
class QByteArray {
public:
    bool isEmpty() const;
    const char* data() const;
    friend std::ostream& operator<<(std::ostream& os, const QByteArray& ba) {
        return os << ba.data();
    }
};
class QUrlQuery {};

class Account {
public:
    QUrl url() const;
};

class Utility {
public:
    static QUrl concatUrlPath(const QUrl&, const std::string&, const QUrlQuery& = QUrlQuery());
};

class AbstractNetworkJob {
public:
    void start();
};

class SimpleApiJob : public AbstractNetworkJob {
public:
    void start();
    QByteArray body() const;
    std::string path() const;
    Account* account() const;
    std::string verbToString() const;
    void sendRequest(const std::string&, const QUrl&, const QNetworkRequest&, const QByteArray& = QByteArray());
    QNetworkRequest request() const;
    void addRawHeader(const std::string&, const std::string&);

private:
    QNetworkRequest _request;
    QByteArray _body;
    QUrlQuery _additionalParams;
};

#define qCDebug(category) std::cout
#define lcSimpleApiJob 0