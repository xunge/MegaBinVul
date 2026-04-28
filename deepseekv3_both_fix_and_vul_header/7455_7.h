#include <string>
#include <vector>
#include <iostream>
#include <memory>

class QString {
public:
    QString(const std::string&);
    QString(const char*);
    std::string toStdString() const;
    QString toString() const;
    friend std::ostream& operator<<(std::ostream& os, const QString& str);
};

template<typename T>
class QList {
public:
    void push_back(const T&);
};

class GPGateway {
public:
    QString address() const;
};

class VpnStatus {
public:
    enum Status { pending };
};

class GPClientPrivate {
public:
    struct StatusLabel {
        void setText(const std::string&);
    }* statusLabel;
};

class settings {
public:
    static QString get(const std::string&, const std::string&);
};

class VpnInterface {
public:
    void connect(const QString&, const QList<QString>&, const QString&, const QString&);
    void connect(const QString&, const QList<QString>&, const QString&, const QString&, const QString&);
};

class GPClient {
public:
    void onGatewaySuccess(const QString &authCookie);
private:
    std::unique_ptr<GPClientPrivate> ui;
    std::unique_ptr<VpnInterface> vpn;
    bool isQuickConnect;
    std::vector<GPGateway> allGateways();
    GPGateway currentGateway();
    void updateConnectionStatus(VpnStatus::Status);
    struct PortalConfig {
        QString username() const;
    } portalConfig;
};

std::ostream& operator<<(std::ostream& os, const QString& str) {
    return os << str.toStdString();
}

#define PLOGI std::cout