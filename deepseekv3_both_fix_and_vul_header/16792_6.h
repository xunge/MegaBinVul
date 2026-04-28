#include <memory>
#include <string>
#include <utility>

class QVariant {
public:
    template<typename T> T value() const;
};

class QObject {
public:
    QVariant property(const std::string& name) const;
    static QObject* sender();
};

class QUrl {
public:
    explicit QUrl(const std::string& url);
};

class Account {
public:
    QUrl url() const;
};

using AccountPtr = std::shared_ptr<Account>;
constexpr const char* propertyAccountC = "account";

namespace Utility {
    void openBrowser(const QUrl& url);
}

namespace QDesktopServices {
    bool openUrl(const QUrl& url);
}

class ownCloudGui : public QObject {
public:
    void slotOpenOwnCloud();
};

template<typename T>
T qvariant_cast(const QVariant& v) {
    return v.value<T>();
}